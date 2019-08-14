#include "ricerca.h"

Ricerca::Ricerca(QWidget *parent) : QDialog(parent),
    ric(new layoutRicercaElimina(this)),
    form(new QVBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    cerca(new QPushButton("Cerca",this)),
    reset(new QPushButton("Reset",this))
{

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //Aggiunta elementi
    buttons->addWidget(reset);
    cerca->setIcon(QIcon(":/Immagini/searchIcon.png"));
    buttons->addWidget(cerca);
    form->addWidget(ric);
    form->addItem(buttons);

    //CONNECT
    connect(reset,SIGNAL(clicked()),ric,SLOT(slotReset()));
}

layoutRicercaElimina* Ricerca::getLCampi()const{
    return ric;
}

QPushButton* Ricerca::getCerca()const{
    return cerca;
}
