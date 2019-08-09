#include "widget.h"

Widget::Widget(Modello* m,QWidget *parent) :
    QWidget(parent),
    modello(m),
    cerca(new QPushButton("Cerca",this)),
    inserisci(new QPushButton("Inserisci",this)),
    visualizza(new QPushButton("Dettagli",this)),
    next(new QPushButton("Successivo >>",this)),
    prev(new QPushButton("<< Precedente",this)),
    loadNewFile(new QPushButton("Carica nuovo \n file",this)),
    img(new QLabel(this)),
    r(new Ricerca(this)),
    risRic(new showRisultatiRicerca(this)),
    i(new Inserimento(this)),
    d(new Dettagli(this)),
    imgUti(new imageUtility()),
    noData(true)
{
    QHBoxLayout* mainForm= new QHBoxLayout(this);
    QVBoxLayout* bottoniSx= new QVBoxLayout(this);
    QVBoxLayout* imgContainer= new QVBoxLayout(this);
    QHBoxLayout* imgButtons= new QHBoxLayout(this);


    //SIZE POLICY
    cerca->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    inserisci->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    loadNewFile->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    cerca->setMaximumSize(300,200);
    inserisci->setMaximumSize(300,200);
    loadNewFile->setMaximumSize(300,200);
    prev->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    visualizza->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    next->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    prev->setMaximumHeight(30);
    visualizza->setMaximumHeight(30);
    next->setMaximumHeight(30);
    img->setScaledContents(true);
    anyDataFound(true);
    //AGGIUNTA A LAYOUT
    bottoniSx->setSpacing(25);
    bottoniSx->addWidget(loadNewFile);
    bottoniSx->addWidget(cerca);
    bottoniSx->addWidget(inserisci);

    imgButtons->setSpacing(50);
    imgButtons->addWidget(prev);
    visualizza->setIcon(QIcon(":/Immagini/info.png"));
    imgButtons->addWidget(visualizza);
    imgButtons->addWidget(next);

    imgContainer->addWidget(img);
    imgContainer->addItem(imgButtons);

    mainForm->addItem(bottoniSx);
    mainForm->addItem(imgContainer);

    connect(cerca,SIGNAL(clicked()),this,SLOT(srcClicked()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(insertClicked()));
    connect(visualizza,SIGNAL(clicked()),this,SLOT(visualizzaClicked()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextClicked()));
    connect(prev,SIGNAL(clicked()),this,SLOT(prevClicked()));
    connect(loadNewFile,SIGNAL(clicked()),this,SLOT(slotLoad()));
    connect(i->getInserisci(),SIGNAL(clicked()),this,SLOT(slotInserimento()));
    connect(r->getCerca(),SIGNAL(clicked()),this,SLOT(slotCerca()));
    connect(d->getSalva(),SIGNAL(clicked()),this,SLOT(slotSalva()));
    connect(d->getElimina(),SIGNAL(clicked()),this,SLOT(slotDelete()));
    connect(risRic->getDettagliRicerca()->getElimina(),SIGNAL(clicked()),this,SLOT(slotDeleteFromSrc()));
    connect(risRic->getDettagliRicerca()->getSalva(),SIGNAL(clicked()),this,SLOT(slotSalvaFromSrc()));
    connect(risRic->getEliminaTutto(),SIGNAL(clicked()),this,SLOT(slotEliminaTutto()));

    if(modello->getPath()==nullptr) pathSaveLoad();
    if(modello->getPath()!=nullptr){
        modello->load();
        anyDataFound(false);
    }


}

void Widget::pathSaveLoad(){
    //Path modello per salvataggio e caricamento
        QMessageBox checkCampi(this);
        checkCampi.setWindowTitle("Scegli file salvataggio/caricamento");
        checkCampi.setIcon(QMessageBox::Question);
        checkCampi.setInformativeText("Selezionare un file da cui effettuare il caricamento dati e su cui effettuarne il salvataggio.");
        checkCampi.setStandardButtons(QMessageBox::Ok);
        int ret = checkCampi.exec();
        if(ret==QMessageBox::Ok){
            QString file= QFileDialog::getOpenFileName(
                        this,
                        tr("Choose file"),
                        "../",
                        "File XML (*.xml)"
                        );
            modello->setPath(file);
        }
}

void Widget::anyDataFound(bool b){
    if(b){
        noData=true;
        //IMG DEFAULT
        QString file=":/Immagini/noData.png";
        QFileInfo relativePath(file);
        if(file!=""){
        QImage im(file);
        QByteArray  array;
        QBuffer b(&array);
        im.save(&b,"JPG");
        img->setPixmap(QPixmap::fromImage(im));
        visualizza->setEnabled(false);
        next->setEnabled(false);
        prev->setEnabled(false);
        }
    }
    else{
        if(!modello->isEmpty()){
            noData=false;
            first=modello->begin();
            last=modello->last();
            current=first;
            visualizza->setEnabled(true);
            if(first!=last){
                next->setEnabled(true);
            }
            if((*first)->getImg()!=""){
                img->setPixmap(imgUti->getImage((*first)->getImg()));
            }
            else{
                img->setText("Nessun immagine trovata per l'arma: "+QString::fromStdString((*first)->getName()));
            }
        }

    }


}

void Widget::srcClicked(){
    (*r).setWindowTitle("Ricerca-Qontainer Armi");
    (*r).setModal(true);
    (*r).show();
    //Info
    QMessageBox::information(r,"Info","Ricorda di compilare solo i campi secondo i quali vuoi effettuare la ricerca.\n"
                                         "Info utili:\n"
                                         "-Se non scegli il tipo di arma verranno cercate tutte le armi che soddisfano i restanti parametri.\n"
                                         "-Se non compili uno dei restanti parametri non verrà considerato ai fini della ricerca.\n"
                                         "-Se scegli solo il tipo di arma verranno visualizzate tutte le armi di quel tipo.\n"
                                         "-Se non compili nulla vedrai la lista di tutte le armi presenti");

}
void Widget::insertClicked(){
    (*i).setWindowTitle("Inserimento-Qontainer Armi");
    (*i).setModal(true);
    (*i).show();

}
void Widget::visualizzaClicked(){
    (*d).setModal(true);
    (*d).update_values((*current)->getImg(),(*current)->getInfo());
    (*d).show();

}
void Widget::nextClicked(){
    if(current==first) prev->setEnabled(true);
    current++;
    if(current==last) next->setEnabled(false);
    if((*current)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata per l'arma: "+QString::fromStdString((*current)->getName()));
    }

}
void Widget::prevClicked(){
    if(current==last) next->setEnabled(true);
    current--;
    if(current==first) prev->setEnabled(false);
    if((*current)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata per l'arma: "+QString::fromStdString((*current)->getName()));
    }
}

void Widget::slotLoad(){
    pathSaveLoad();
    modello->clear();
    modello->load();
    
    first=nullptr;
    last=nullptr;
    current=nullptr;
    anyDataFound(true);
    anyDataFound(false);
}

//SLOT PER SIGNALS ESTERNI
void Widget::slotInserimento(){

    if (i->getCBTipoArma()->currentIndex()==0 ){
        QMessageBox::warning(i,"Attenzione","Devi selezionare il tipo di arma che vuoi inserire.");
    }
    else{
        QMessageBox checkCampi(i);
        checkCampi.setWindowTitle("Inserimento");
        checkCampi.setIcon(QMessageBox::Question);
        checkCampi.setText("Procedere all'inserimento?");
        checkCampi.setInformativeText("Una volta confermato l'inserimento, non sarà più possibile modificare i campi dati ad eccezzione di prezzo e foto.");
        checkCampi.setStandardButtons(QMessageBox::Cancel |QMessageBox::Save);
        checkCampi.setDefaultButton(QMessageBox::Save);
        int ret = checkCampi.exec();
        switch (ret) {
            case QMessageBox::Save:
                if(modello->getPath()==nullptr) pathSaveLoad();
                if(modello->getPath()==nullptr) break;
                toInsert=i->getWeaponToInsert();
                modello->push(toInsert);
                modello->save();
                i->slotReset();
                if(noData){ anyDataFound(false); }
                else{
                    last=modello->last();
                    next->setEnabled(true);
                }

            break;
            case QMessageBox::Cancel:
               //Non deve far nulla
            break;
        }
    }

}

void Widget::slotCerca(){
    //Elimina il risultato della precedente ricerca
    modello->res_clear();
    //Inizializzazione paramentri di ricerca
    int tipo=r->getLCampi()->getTipo();
    QString name=r->getLCampi()->getName();
    QString designer=r->getLCampi()->getDesigner();
    double priceMin=r->getLCampi()->getPriceMin();
    double priceMax=r->getLCampi()->getPriceMax();
    int licenseNeeded=r->getLCampi()->getLicenseNeeded();
    //Arma da fuoco
    QString caliber=r->getLCampi()->getCaliber();
    //arma pneumatica
    double joule=r->getLCampi()->getJoule();
    //arma bianca
    double bladeLengthMin=r->getLCampi()->getBladeLengthMin();
    double bladeLengthMax=r->getLCampi()->getBladeLengthMax();
    //esplosivo
    double fillingWeight=r->getLCampi()->getFillingWeight();
    bool insertThis;
    //Ricerca
    /*  QString::compare
    *   Ritorna 0 se le 2 stringhe sono uguali altrimenti numero intero diverso da 0
    */

    for(auto it=modello->begin();it!=modello->ptend();++it){
        insertThis=false;
        //controllo su campi base di arma
        if(
                (!QString::compare( QString::fromStdString((*it)->getName()),name,Qt::CaseInsensitive)||name=="")&&
                (!QString::compare( QString::fromStdString((*it)->getDesigner()),designer,Qt::CaseInsensitive)||designer=="")&&
                ((*it)->getPrice()>=priceMin&&(*it)->getPrice()<=priceMax)
        ){
            if(licenseNeeded==0){insertThis=true;}
            else if(licenseNeeded==1){
                if((*it)->isLicenseNeeded()==true)insertThis=true;
                else insertThis=false;
            }
            else if(licenseNeeded==2){
                if((*it)->isLicenseNeeded()==false)insertThis=true;
                else insertThis=false;
            }
        }
        //Se insert this==true proseguo altrimenti non soddisfa i parametri
        if(insertThis){
            if(tipo==0){
                modello->res_push((*it));
            }
            else if (tipo==1) {
                if((*it)->getTipo()=="ArmaPneumatica"){
                    ArmaPneumatica* a=static_cast<ArmaPneumatica*>((*it));
                    if(
                            (!QString::compare( QString::fromStdString(a->getCaliber()),caliber,Qt::CaseInsensitive)||caliber=="")&&
                            (a->getJoule()==joule||joule==0)
                      ){
                        modello->res_push((*it));
                      }
                }
            }
            else if (tipo==2) {
                if((*it)->getTipo()=="ArmaAPolvere"){
                    ArmaAPolvere* a=static_cast<ArmaAPolvere*>((*it));
                    if(
                            (!QString::compare( QString::fromStdString(a->getCaliber()),caliber,Qt::CaseInsensitive)||caliber=="")
                      ){
                        modello->res_push((*it));
                      }
                }
            }
            else if (tipo==3) {
                if((*it)->getTipo()=="ArmaBianca"){
                    ArmaBianca* a=static_cast<ArmaBianca*>((*it));
                    if(
                            (a->getBladeLength()>=bladeLengthMin&&a->getBladeLength()<=bladeLengthMax)
                      ){
                        modello->res_push((*it));
                      }
                }
            }
            else if (tipo==4) {
                if((*it)->getTipo()=="Esplosivo"){
                    Esplosivo* a=static_cast<Esplosivo*>((*it));
                    if(
                            (a->getFillingWeight()<=fillingWeight||fillingWeight==0)
                      ){
                        modello->res_push((*it));
                      }
                }
            }
        }
    }

    if(modello->res_isEmpty()){
        QMessageBox::information(this,"Ricerca","Non ci sono elementi che soddisfano i paramentri di ricerca.");
    }
    else{
        (*risRic).setWindowTitle("Risultato della ricerca-Qontainer Armi");
        (*risRic).setModal(true);
        (*risRic).show();
        (*risRic).setIt(modello->res_begin(),modello->res_end());
    }

}

void Widget::funDelete(Dettagli * det){
    QMessageBox::StandardButton reply;
         reply = QMessageBox::question(d, "Eliminazione oggetto.", "Sicuro di voler eliminare questo oggetto?",
                                       QMessageBox::Yes|QMessageBox::No);
         if (reply == QMessageBox::Yes){
           List<Arma*>::iterator it=current;
           if(first==last){
              anyDataFound(true);
           }
           else if(current==first){
               nextClicked();
           }
           else if(current==last){
               prevClicked();
           }
           else prevClicked();
           modello->erase(it);
           det->close();
           if(!noData){
               last=modello->last();
               first=modello->begin();
               if(current==last) next->setEnabled(false);
               if(current==first) prev->setEnabled(false);
           }
           modello->save();

         }
}

void Widget::slotDelete(){//elimina di "Dettagli"
    funDelete(d);
}
void Widget::funSave(Dettagli * det){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(det, "Salvataggio modifiche.", "Sicuro di voler salvare le modifiche?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes){
        det->layoutModificaVisible(false);
        if(det->getImg()!="") (*current)->setImg(det->getImg());
        if(det->getPrice()>0) (*current)->setPrice(det->getPrice());
        img->setPixmap(imgUti->getImage((*current)->getImg()));
        det->update_values((*current)->getImg(),(*current)->getInfo());
        modello->save();
      }
}
void Widget::slotSalva(){
    funSave(d);
}

void Widget::slotDeleteFromSrc(){
       /* List<Arma*>::iterator realCurrent=++current;
        current=risRic->getCurrent();
        funDelete(risRic->getDettagliRicerca());
        current=realCurrent;*/
        //risRic->setIt(modello->res_begin(),modello->res_end());
    modello->erase(risRic->getCurrent());
}
void Widget::slotSalvaFromSrc(){
    if(current!=risRic->getCurrent()){
        List<Arma*>::iterator realCurrent=current;
        current=risRic->getCurrent();
        funSave(risRic->getDettagliRicerca());
        current=realCurrent;
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else slotSalva();
    risRic->updateOnSave();
}
void Widget::slotEliminaTutto(){

}

Widget::~Widget()=default;
