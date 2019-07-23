#include "comboboxtipoarma.h"

comboBoxTipoArma::comboBoxTipoArma(QWidget *parent):
    QComboBox (parent)
{
    addItem("Scegli il tipo di arma");

    addItem("Arma Pneumatica");
    addItem("Arma a polvere");
    addItem("Arma Bianca");
    addItem("Esplosivo");
}
