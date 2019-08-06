#include "elimina.h"
#include <QMessageBox>

Elimina::Elimina(QWidget *parent) : QDialog(parent),
    del(new layoutRicercaElimina(this)),
    form(new QVBoxLayout(this)),
    buttons(new QHBoxLayout(this)),
    elimina(new QPushButton("Elimina",this)),
    reset(new QPushButton("Reset",this))
{

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    //Aggiunta elementi
    buttons->addWidget(reset);
    elimina->setIcon(QIcon(":/Immagini/deleteIcon.png"));
    buttons->addWidget(elimina);
    form->addWidget(del);
    form->addItem(buttons);

    //CONNECT
    connect(reset,SIGNAL(clicked()),del,SLOT(slotReset()));
}

layoutRicercaElimina* Elimina::getLCampi(){
    return del;
}

QPushButton* Elimina::getElimina(){
    return elimina;
}
