#include "showrisultatiricerca.h"

showRisultatiRicerca::showRisultatiRicerca(QWidget* parent) : QDialog(parent),
    dettagli(new QPushButton("Dettagli",this)),
    next(new QPushButton("Successivo",this)),
    prev(new QPushButton("Precedente",this)),
    eliminaTutto(new QPushButton("Elimina tutto",this)),
    img(new QLabel(this)),
    d(new Dettagli(this)),
    form(new QVBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    imgUti(new imageUtility())
{
    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //SIZE POLICY
    prev->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    dettagli->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    next->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    eliminaTutto->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    prev->setMaximumHeight(30);
    dettagli->setMaximumHeight(30);
    eliminaTutto->setMaximumHeight(30);
    next->setMaximumHeight(30);
    img->setMinimumSize(300,300);
    img->setMaximumSize(400,400);
    img->setScaledContents(true);
    //AGGIUNTA A LAYOUT
    buttons->addWidget(prev);
    dettagli->setIcon(QIcon(":/Immagini/info.png"));
    buttons->addWidget(dettagli);
    buttons->addWidget(eliminaTutto);
    buttons->addWidget(next);
    form->addWidget(img);
    form->addItem(buttons);

    prev->setEnabled(false);
    next->setEnabled(false);

    connect(dettagli,SIGNAL(clicked()),this,SLOT(dettagliClicked()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextClicked()));
    connect(prev,SIGNAL(clicked()),this,SLOT(prevClicked()));
    connect(d->getElimina(),SIGNAL(clicked()),this,SLOT(updateOnDelete()));

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
        img->setPixmap(imgUti->getImage((*first)->getImg()));
    }
    else{
        img->setText("Nessun immagine trovata per l'arma: "+QString::fromStdString((*first)->getName()));
    }
}

Dettagli* showRisultatiRicerca::getDettagliRicerca(){
    return d;
}

QPushButton* showRisultatiRicerca::getEliminaTutto(){
    return eliminaTutto;
}
List<Arma*>::iterator showRisultatiRicerca::getCurrent(){
    return current;
}
void showRisultatiRicerca::dettagliClicked(){
    (*d).setModal(true);
    (*d).update_values((*current)->getImg(),(*current)->getInfo());
    (*d).show();
}
void showRisultatiRicerca::nextClicked(){
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
void showRisultatiRicerca::prevClicked(){
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

void showRisultatiRicerca::updateOnDelete(){
    if(first==last){
        QMessageBox::information(this,"Ricerca","Tutti gli oggetti che soddisfavano i parametri della ricerca sono stati eliminati. ");
       this->close();
    }
    else if(current==first){
        nextClicked();
    }
    else if(current==last){
        prevClicked();
    }
    else prevClicked();
}

void showRisultatiRicerca::updateOnSave(){
    img->setPixmap(imgUti->getImage(d->getImg()));
}
