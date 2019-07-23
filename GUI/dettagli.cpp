#include "dettagli.h"

Dettagli::Dettagli(QString s,QWidget *parent) : QDialog(parent),
    info(new QTextEdit(this)),
    img(new QLabel(this)),
    elimina(new QPushButton("Elimina",this)),
    modifica(new QPushButton("Modifica",this)),
    form(new QVBoxLayout(this)),
    layoutDettagli(new QHBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    pos(s)
{
    //SIZE POLICY
    this->setMinimumSize(575,315);
    this->setMaximumSize(1150,630);
    img->setMaximumSize(600,600);
    img->setScaledContents(true);
    info->setMaximumSize(500,500);
    elimina->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    modifica->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    elimina->setMaximumSize(100,30);
    modifica->setMaximumSize(100,30);
    form->setSpacing(10);
    layoutDettagli->setSpacing(10);
    buttons->setSpacing(50);

    //DESCRIPTION
    info->setWhatsThis("Tutte le informazioni disponibili di questo oggetto.");
    img->setWhatsThis("Un immagine di questo oggetto.");
    modifica->setWhatsThis("Permette di modificare la foto e/o il prezzo di questo oggetto.");
    elimina->setWhatsThis("Elimina questo oggetto dalla lista.");

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

    buttons->addWidget(modifica);
    elimina->setIcon(QIcon(":/Immagini/deleteIcon.png"));
    buttons->addWidget(elimina);

    form->addItem(layoutDettagli);
    form->addItem(buttons);

    //SLOT
    connect(elimina,SIGNAL(clicked()),this,SLOT(slotDelete()));
    connect(modifica,SIGNAL(clicked()),this,SLOT(slotModifica()));


}

void Dettagli::slotDelete(){
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "Eliminazione oggetto.", "Sicuro di voler eliminare questo oggetto?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {

      }

}

void Dettagli::slotModifica()const{

}














