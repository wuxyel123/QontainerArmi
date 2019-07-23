#include "ricerca.h"

Ricerca::Ricerca(QWidget *parent) : QDialog(parent),
    ric(new layoutRicercaElimina(this))
{

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}
