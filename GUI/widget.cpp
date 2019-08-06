#include "widget.h"

Widget::Widget(Modello* m,QWidget *parent) :
    QWidget(parent),
    modello(m),
    cerca(new QPushButton("Cerca",this)),
    inserisci(new QPushButton("Inserisci",this)),
    visualizza(new QPushButton("Dettagli",this)),
    next(new QPushButton("Successivo >>",this)),
    prev(new QPushButton("<< Precedente",this)),
    advancedDelete(new QPushButton("Eliminzazione \n Avanzata",this)),
    img(new QLabel("IMMAGINE",this)),
    r(new Ricerca(this)),
    e(new Elimina(this)),
    i(new Inserimento(this)),
    d(new Dettagli(this))
{
    QHBoxLayout* mainForm= new QHBoxLayout(this);
    QVBoxLayout* bottoniSx= new QVBoxLayout(this);
    QVBoxLayout* imgContainer= new QVBoxLayout(this);
    QHBoxLayout* imgButtons= new QHBoxLayout(this);


    //SIZE POLICY
    cerca->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    inserisci->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    advancedDelete->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    cerca->setMaximumSize(300,200);
    inserisci->setMaximumSize(300,200);
    advancedDelete->setMaximumSize(300,200);
    prev->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    visualizza->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    next->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    prev->setMaximumHeight(30);
    visualizza->setMaximumHeight(30);
    next->setMaximumHeight(30);
    img->setScaledContents(true);
    //IMG DEFAULT
    QString file=":/Immagini/noData.png";
    QFileInfo relativePath(file);
    if(file!=""){
    QImage im(file);
    QByteArray  array;
    QBuffer b(&array);
    im.save(&b,"JPG");
    img->setPixmap(QPixmap::fromImage(im));
    }

    //AGGIUNTA A LAYOUT
    bottoniSx->setSpacing(25);
    bottoniSx->addWidget(cerca);
    bottoniSx->addWidget(inserisci);
    bottoniSx->addWidget(advancedDelete);

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
    connect(advancedDelete,SIGNAL(clicked()),this,SLOT(advancedDeleteClicked()));
    connect(i->getInserisci(),SIGNAL(clicked()),this,SLOT(slotInserimento()));
    connect(r->getCerca(),SIGNAL(clicked()),this,SLOT(slotCerca()));
    connect(e->getElimina(),SIGNAL(clicked()),this,SLOT(slotElimina()));
    connect(d->getSalva(),SIGNAL(clicked()),this,SLOT(slotSalva()));
    connect(d->getElimina(),SIGNAL(clicked()),this,SLOT(slotDelete()));


}
void Widget::srcClicked(){
    (*r).setWindowTitle("Ricerca-Qontainer Armi");
    (*r).setModal(true);
    (*r).show();
    //Info
    QMessageBox::information(e,"Info","Ricorda di compilare solo i campi secondo i quali vuoi effettuare la ricerca.\n"
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
void Widget::advancedDeleteClicked(){
    (*e).setWindowTitle("Eliminazione avanzata-Qontainer Armi");
    (*e).setModal(true);
    (*e).show();
    //Info
    QMessageBox::information(e,"Info","Ricorda di compilare solo i campi secondo i quali vuoi effettuare l'eliminazione.\n"
                                         "Info utili:\n"
                                         "-Se non scegli il tipo di arma verranno eliminate tutte le armi che soddisfano i restanti parametri.\n"
                                         "-Se non compili uno dei restanti parametri non verrà considerato ai fini dell'eliminazione.\n"
                                         "-Se scegli solo il tipo di arma verranno eliminate tutte le armi di quel tipo.");
}
void Widget::visualizzaClicked(){
    (*d).setWindowTitle("Dettagli-Qontainer Armi");
    (*d).setModal(true);
    (*d).show();
}
void Widget::nextClicked(){

}
void Widget::prevClicked(){

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
                toInsert=i->getWeaponToInsert();
                modello->push(toInsert);
                modello->save();
            break;
            case QMessageBox::Cancel:
               //Non deve far nulla
            break;
        }
    }

}

void Widget::slotCerca(){

}

void Widget::slotElimina(){

}

void Widget::slotDelete(){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(d, "Eliminazione oggetto.", "Sicuro di voler eliminare questo oggetto?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes){

      }

}

void Widget::slotSalva(){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(d, "Salvataggio modifiche.", "Sicuro di voler salvare le modifiche?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes){
        d->layoutModificaVisible(false);
      }
}


Widget::~Widget()
{
    delete this;
}
