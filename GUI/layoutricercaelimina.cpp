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
    lFillingWeight(new QLabel("Peso carica (g) <= di:",this)),
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

    setAllExtraNotVisible();

    pricetMin->setMaximum(999999);
    priceMax->setMaximum(999999);
    priceMax->setValue(999999);
    joule->setMaximum(100000);
    bladeLengthMin->setMaximum(300);
    bladeLengthMax->setMaximum(300);
    bladeLengthMax->setValue(300);
    fillingWeight->setMaximum(9999);

    //Placeholders
    name->setPlaceholderText("Inserisci il nome.");
    designer->setPlaceholderText("Inserisci il/i designer.");
    caliber->setPlaceholderText("Inserisci il calibro.");

    //CONNECT
    connect(tipoArma,SIGNAL(activated(int)),this,SLOT(slotViewElements(int)));
    connect(priceMax,SIGNAL(valueChanged(double)),this,SLOT(slotPrice(double)));
    connect(bladeLengthMax,SIGNAL(valueChanged(double)),this,SLOT(slotBladeLength(double)));
}


void layoutRicercaElimina::setAllExtraNotVisible()const {
    setArmaDaFuocoVisible(false);
    setArmaPneumaticaVisible(false);
    setArmaBiancaVisible(false);
    setEsplosivoVisible(false);
}

void layoutRicercaElimina::setArmaDaFuocoVisible(bool b)const {

    caliber->setEnabled(b);

    lCaliber->setVisible(b);
    caliber->setVisible(b);

    if(!b){
        fields->removeWidget(lCaliber);
        fields->removeWidget(caliber);
    }
    else{
        fields->addWidget(lCaliber,6,0);
        fields->addWidget(caliber,6,1);
    }

}

void layoutRicercaElimina::setArmaPneumaticaVisible(bool b)const {

    joule->setEnabled(b);

    joule->setVisible(b);
    lJoule->setVisible(b);

    if(!b){
        fields->removeWidget(lJoule);
        fields->removeWidget(joule);
    }
}

void layoutRicercaElimina::setArmaBiancaVisible(bool b)const {

    bladeLengthMin->setEnabled(b);
    bladeLengthMax->setEnabled(b);

    bladeLengthMin->setVisible(b);
    lBladeLengthMin->setVisible(b);
    bladeLengthMax->setVisible(b);
    lBladeLengthMax->setVisible(b);

    if(!b){
        fields->removeWidget(lBladeLengthMin);
        fields->removeWidget(bladeLengthMin);
        fields->removeWidget(lBladeLengthMax);
        fields->removeWidget(bladeLengthMax);
    }

}
void layoutRicercaElimina::setEsplosivoVisible(bool b)const {

    fillingWeight->setEnabled(b);

    fillingWeight->setVisible(b);
    lFillingWeight->setVisible(b);

    if(!b){
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(fillingWeight);
    }

}
void layoutRicercaElimina::slotViewElements(int index)const{
    switch (index) {
        case 0:
        setAllExtraNotVisible();
        fields->update();
        break;
        case 1:
        setArmaDaFuocoVisible(true);
        setArmaPneumaticaVisible(true);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(false);

        fields->addWidget(lJoule,7,0);
        fields->addWidget(joule,7,1);

        fields->update();

        break;

        case 2://ARMA A POLVERE
        //Rimozione campi specifici dalla finestra
        setArmaDaFuocoVisible(true);
        setArmaPneumaticaVisible(false);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(false);

        fields->update();

        break;

        case 3://ARMA BIANCA
        setArmaDaFuocoVisible(false);
        setArmaPneumaticaVisible(false);

        setArmaBiancaVisible(true);
        setEsplosivoVisible(false);

        fields->addWidget(lBladeLengthMin,6,0);
        fields->addWidget(bladeLengthMin,6,1);
        fields->addWidget(lBladeLengthMax,7,0);
        fields->addWidget(bladeLengthMax,7,1);

        fields->update();

        break;
        case 4://ESPLOSIVO

        setArmaDaFuocoVisible(false);
        setArmaPneumaticaVisible(false);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(true);

        fields->addWidget(lFillingWeight,6,0);
        fields->addWidget(fillingWeight,6,1);

        fields->update();

        break;
    }

}

void layoutRicercaElimina::slotReset()const{
    tipoArma->setCurrentIndex(0);
    name->setText("");
    designer->setText("");
    pricetMin->setValue(0);
    priceMax->setValue(999999);
    licenseNeeded->setChecked(false);
    caliber->setText("");
    joule->setValue(0);
    bladeLengthMin->setValue(0);
    bladeLengthMax->setValue(300);
    fillingWeight->setValue(0);
    setAllExtraNotVisible();
}

void layoutRicercaElimina::slotPrice(double val){
    pricetMin->setMaximum(val);
}
void layoutRicercaElimina::slotBladeLength(double val){
    bladeLengthMin->setMaximum(val);
}

int layoutRicercaElimina::getTipo()const{
    return tipoArma->currentIndex();
}
QString layoutRicercaElimina::getName()const{
    return name->text();
}
QString layoutRicercaElimina::getDesigner()const{
    return designer->text();
}
double layoutRicercaElimina::getPriceMin()const{
    return pricetMin->value();
}
double layoutRicercaElimina::getPriceMax()const{
    return priceMax->value();
}
bool layoutRicercaElimina::getLicenseNeeded()const{
    return licenseNeeded->isChecked();
}
QString layoutRicercaElimina::getCaliber()const{
    return caliber->text();
}
double layoutRicercaElimina::getJoule()const{
    return joule->value();
}
double layoutRicercaElimina::getBladeLengthMin()const{
    return bladeLengthMin->value();
}
double layoutRicercaElimina::getBladeLengthMax()const{
    return bladeLengthMax->value();
}
double layoutRicercaElimina::getFillingWeight()const{
    return fillingWeight->value();
}


