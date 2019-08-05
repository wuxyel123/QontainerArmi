#include "dettagli.h"

Dettagli::Dettagli(QWidget *parent) : QDialog(parent),
    info(new QTextEdit(this)),
    img(new QLabel(this)),
    lPrice(new QLabel("Inserisci il nuovo prezzo netto:",this)),
    lImg(new QLabel("Inserisci la nuova immagine:",this)),
    price(new QDoubleSpinBox(this)),
    btnImg(new QPushButton("Scegli la foto",this)),
    elimina(new QPushButton("Elimina",this)),
    modifica(new QPushButton("Modifica",this)),
    salva(new QPushButton("Salva modifiche",this)),
    form(new QVBoxLayout(this)),
    layoutDettagli(new QHBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    lModifica(new QGridLayout(this))
{
    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //SIZE POLICY
    this->setMinimumSize(575,315);
    this->setMaximumSize(1150,630);
    img->setMaximumSize(600,600);
    img->setScaledContents(true);
    info->setMaximumSize(500,500);
    //price->setMaximumSize(100,30);
    elimina->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    modifica->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    salva->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    btnImg->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    elimina->setMaximumSize(100,30);
    modifica->setMaximumSize(100,30);
    salva->setMaximumSize(100,30);
    //btnImg->setMaximumSize(100,30);
    form->setSpacing(10);
    layoutDettagli->setSpacing(10);
    buttons->setSpacing(50);

    //RANGE
    price->setMaximum(999999);

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


    //INFO READ ONLY
    info->setReadOnly(true);

    //INSERIMENTO IN LAYOUT
    layoutDettagli->addWidget(info);
    layoutDettagli->addWidget(img);

    lPrice->setVisible(false);
    lImg->setVisible(false);
    price->setVisible(false);
    btnImg->setVisible(false);
    lModifica->addWidget(lPrice,0,0);
    lModifica->addWidget(price,0,1);
    btnImg->setIcon(QIcon(":/Immagini/choosefile.png"));
    lModifica->addWidget(lImg,1,0);
    lModifica->addWidget(btnImg,1,1);

    buttons->addWidget(modifica);
    elimina->setIcon(QIcon(":/Immagini/deleteIcon.png"));
    buttons->addWidget(elimina);
    salva->setVisible(false);
    buttons->addWidget(salva);

    form->addItem(layoutDettagli);
    form->addItem(buttons);

    //SLOT
    connect(modifica,SIGNAL(clicked()),this,SLOT(slotModifica()));

}

void Dettagli::slotModifica()const{
    layoutModificaVisible(true);
}

QPushButton* Dettagli::getSalva(){
    return salva;
}
QPushButton* Dettagli::getElimina(){
    return elimina;
}

void Dettagli::layoutModificaVisible(bool b)const{
    if(b){//Visualizza il layout di modifica
        form->removeItem(buttons);
        form->addItem(lModifica);
        form->addItem(buttons);
    }
    else{//Toglie il layout di modifica
        form->removeItem(lModifica);
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









