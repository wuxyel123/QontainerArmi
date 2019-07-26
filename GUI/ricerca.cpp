#include "ricerca.h"

Ricerca::Ricerca(QWidget *parent) : QDialog(parent),
    ric(new layoutRicercaElimina(this)),
    form(new QVBoxLayout(this))
{

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    form->addWidget(ric);

}
