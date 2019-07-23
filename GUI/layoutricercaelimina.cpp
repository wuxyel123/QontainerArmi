#include "layoutricercaelimina.h"

layoutRicercaElimina::layoutRicercaElimina(QWidget *parent) : QWidget(parent),
    tipoArma(new comboBoxTipoArma(this)),
    lName(new QLabel("Nome:",this)),
    lDesigner(new QLabel("Designer:",this)),
    lPriceMin(new QLabel("Prezzo: Da",this)),
    lPriceMax(new QLabel("A:",this)),
    lLicense(new QLabel("Porto d'armi necessario:",this)),
    name(new QLineEdit(this)),
    designer(new QLineEdit(this)),
    pricetMin(new QDoubleSpinBox(this)),
    priceMax(new QDoubleSpinBox(this)),
    licenseNeeded(new QCheckBox(this)),
    lCaliber(new QLabel("Calibro:",this)),
    caliber(new QLineEdit(this)),
    lJoule(new QLabel("Joule:",this)),
    joule(new QDoubleSpinBox(this)),
    lBladeLengthMin(new QLabel("Lunghezza lama (cm) Da:",this)),
    lBladeLengthMax(new QLabel("A:",this)),
    bladeLengthMin(new QDoubleSpinBox(this)),
    bladeLengthMax(new QDoubleSpinBox(this)),
    lFillingWeight(new QLabel("Peso carica (g):",this)),
    fillingWeight(new QDoubleSpinBox(this)),
    fields(new QGridLayout(this))
{
    //SIZE POLICY
    fields->setSpacing(10);


    fields->addWidget(tipoArma,0,0);

    fields->addWidget(lName,1,0);
    fields->addWidget(name,1,1);

    fields->addWidget(lDesigner,2,0);
    fields->addWidget(designer,2,1);

    fields->addWidget(lPriceMin,3,0);
    fields->addWidget(pricetMin,3,1);
    fields->addWidget(lPriceMax,4,0);
    fields->addWidget(priceMax,4,1);

    fields->addWidget(lLicense,5,0);
    fields->addWidget(licenseNeeded,5,1);


    pricetMin->setMaximum(999999);
    priceMax->setMaximum(999999);
    joule->setMaximum(100000);
    bladeLengthMin->setMaximum(300);
    bladeLengthMax->setMaximum(300);
    fillingWeight->setMaximum(9999);

}
