#include "ricerca.h"

Ricerca::Ricerca(QWidget *parent) : QDialog(parent)
{

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

}
