#include "showrisultatiricerca.h"

showRisultatiRicerca::showRisultatiRicerca(QWidget* parent) : QDialog(parent),
    modifica(new QPushButton("Modifica",this)),
    next(new QPushButton("Successivo>>",this)),
    prev(new QPushButton("<<Precedente",this)),
    eliminaTutto(new QPushButton("Elimina tutto",this)),
    det(new QTextEdit(this)),
    img(new QLabel(this)),
    form(new QVBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    arma(new QHBoxLayout(this)),
    imgUti(new imageUtility()),
    lPrice(new QLabel("Inserisci il nuovo prezzo netto:",this)),
    price(new QDoubleSpinBox(this)),
    lImg(new QLabel("Inserisci la nuova immagine:",this)),
    btnImg(new QPushButton("Scegli la foto",this)),
    salva(new QPushButton("Salva modifiche",this)),
    lModifica(new QGridLayout(this))
{
    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //SIZE POLICY
    prev->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    modifica->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    next->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    eliminaTutto->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    salva->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    btnImg->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    prev->setMaximumHeight(30);
    modifica->setMaximumHeight(30);
    salva->setMaximumHeight(30);
    eliminaTutto->setMaximumHeight(30);
    next->setMaximumHeight(30);
    img->setMinimumSize(300,300);
    img->setMaximumSize(400,400);
    img->setScaledContents(true);
    price->setMaximum(999999);
    //AGGIUNTA A LAYOUT
    buttons->addWidget(prev);
    buttons->addWidget(modifica);
    buttons->addWidget(salva);
    eliminaTutto->setIcon(QIcon(":/Immagini/deleteIcon.png"));
    buttons->addWidget(eliminaTutto);
    buttons->addWidget(next);
    arma->addWidget(det);
    arma->addWidget(img);

    lModifica->addWidget(lPrice,0,0);
    lModifica->addWidget(price,0,1);
    btnImg->setIcon(QIcon(":/Immagini/choosefile.png"));
    lModifica->addWidget(lImg,1,0);
    lModifica->addWidget(btnImg,1,1);

    lPrice->setVisible(false);
    price->setVisible(false);
    lImg->setVisible(false);
    btnImg->setVisible(false);
    salva->setVisible(false);

    form->addItem(arma);
    form->addItem(buttons);

    prev->setEnabled(false);
    next->setEnabled(false);

    connect(modifica,SIGNAL(clicked()),this,SLOT(modificaClicked()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextClicked()));
    connect(prev,SIGNAL(clicked()),this,SLOT(prevClicked()));
    connect(btnImg,SIGNAL(clicked()),this,SLOT(slotChooseImage()));

}

void showRisultatiRicerca::setIt(List<Arma*>::iterator f,List<Arma*>::iterator l){
    first=f;
    last=l;
    current=first;
    if(current==last) next->setEnabled(false);
    if(current==first) prev->setEnabled(false);
    if(first!=last){
        next->setEnabled(true);
    }
    if((*first)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata.");
    }
    det->setText(QString::fromStdString((*current)->getInfo()));

}

QPushButton* showRisultatiRicerca::getEliminaTutto(){
    return eliminaTutto;
}
QPushButton* showRisultatiRicerca::getSalva(){
    return salva;
}
List<Arma*>::iterator showRisultatiRicerca::getCurrent(){
    return current;
}

void showRisultatiRicerca::updateOnSave(){
    if((*current)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata.");
    }
    det->setText(QString::fromStdString((*current)->getInfo()));
    layoutModificaVisible(false);
}

std::string showRisultatiRicerca::getImg()const{
    if(imageRawData.size()>0)   return imageRawData;
    return "";
}

double showRisultatiRicerca::getPrice()const{
    return price->value();
}

void showRisultatiRicerca::layoutModificaVisible(bool b){
    if(b){//Visualizza il layout di modifica
        form->removeItem(buttons);
        form->addItem(lModifica);
        form->addItem(buttons);
        imageRawData="";
    }
    else{//Toglie il layout di modifica
        form->removeItem(lModifica);
        price->setValue(0);

    }
    lPrice->setVisible(b);
    price->setVisible(b);
    lImg->setVisible(b);
    btnImg->setVisible(b);
    salva->setVisible(b);
    modifica->setVisible(!b);
    buttons->update();
    form->update();
}

void showRisultatiRicerca::modificaClicked(){
    layoutModificaVisible(true);
}
void showRisultatiRicerca::nextClicked(){
    if(current==first) prev->setEnabled(true);
    current++;
    if(current==last) next->setEnabled(false);
    if((*current)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata.");
    }
    layoutModificaVisible(false);
}
void showRisultatiRicerca::prevClicked(){
    if(current==last) next->setEnabled(true);
    current--;
    if(current==first) prev->setEnabled(false);
    if((*current)->getImg()!=""){
        img->setPixmap(imgUti->getImage((*current)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata.");
    }
    layoutModificaVisible(false);
}

void showRisultatiRicerca::slotChooseImage(){
    QString file= QFileDialog::getOpenFileName(
                this,
                tr("Choose image"),
                "../",
                "Image file (*.jpg)"
                );
        QFileInfo relativePath(file);
        if(file!=""){
                QImage im(file);
                QByteArray  array;
                QBuffer b(&array);

                im.save(&b,"JPG");
                imageRawData=imgUti->getRawData(im);
            }

}
