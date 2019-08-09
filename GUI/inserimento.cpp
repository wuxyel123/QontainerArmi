#include "inserimento.h"

Inserimento::Inserimento(QWidget *parent) : QDialog(parent),
    tipoArma(new comboBoxTipoArma(this)),

    lLenght(new QLabel("Lunghezza (cm):",this)),
    lWeight(new QLabel("Peso (kg):",this)),
    lPrice(new QLabel("Prezzo base(€):",this)),
    lDesigner(new QLabel("Designer:",this)),
    lMaterials(new QLabel("Materiali:",this)),
    lName(new QLabel("Nome:",this)),
    lLicense(new QLabel("Porto d'armi necessario:",this)),
    lenght(new QDoubleSpinBox(this)),
    weight(new QDoubleSpinBox(this)),
    price(new QDoubleSpinBox(this)),
    designer(new QLineEdit(this)),
    materials(new QTextEdit(this)),
    name(new QLineEdit(this)),
    selImg(new QPushButton(this)),
    licenseNeeded(new QCheckBox(this)),

    lRateOfFire(new QLabel("Rateo di fuoco (RPM):",this)),
    lFiringRange(new QLabel("Tiro utile (m):",this)),
    lMuzzleVelocity(new QLabel("Velocità alla volata (m/s):",this)),
    lBarrelLength(new QLabel("Lunghezza canna (cm):",this)),
    lCaliber(new QLabel("Calibro:",this)),
    lFeedSystem(new QLabel("Alimentazione:",this)),
    rateOfFire(new QSpinBox(this)),
    firingRange(new QSpinBox(this)),
    muzzleVelocity(new QSpinBox(this)),
    barrelLength(new QDoubleSpinBox(this)),
    caliber(new QLineEdit(this)),
    feedSystem(new QTextEdit(this)),

    lJoule(new QLabel("Joule:",this)),
    lGasUsed(new QLabel("Gas compresso utilizzato:",this)),
    joule(new QDoubleSpinBox(this)),
    gasUsed(new QLineEdit(this)),

    lCartridge(new QLabel("Munizioni:",this)),
    cartridge(new QTextEdit(this)),

    lBladeLength(new QLabel("Lungheezza lama (cm):",this)),
    lHiltType(new QLabel("Tipo impugnatura:",this)),
    lBladeType(new QLabel("Tipo lama:",this)),
    bladeLength(new QDoubleSpinBox(this)),
    hiltType(new QTextEdit(this)),
    bladeType(new QTextEdit(this)),

    lFilling(new QLabel("Carica:",this)),
    lDetonationMechanism(new QLabel("Azionamento:",this)),
    lFillingWeight(new QLabel("Peso carica (g):",this)),
    filling(new QLineEdit(this)),
    detonationMechanism(new QTextEdit(this)),
    fillingWeight(new QDoubleSpinBox(this)),

    reset(new QPushButton("Reset",this)),
    inserisci(new QPushButton("Inserisci",this)),

    form(new QVBoxLayout(this)),
    fields(new QGridLayout(this)),
    btn(new QHBoxLayout(this)),
    img(new QHBoxLayout(this)),
    lImg(new QLabel(this))
{
    //SIZE POLICY
    lImg->setMaximumSize(384,216);
    lImg->setScaledContents(true);
    fields->setSpacing(10);

    //Disabilita pulsante WhatsThis
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    fields->addWidget(tipoArma,0,0);
    //ARMA
    fields->addWidget(lName,1,0);
    name->setPlaceholderText("Inserisci il nome.");
    fields->addWidget(name,1,1);

    fields->addWidget(lDesigner,2,0);
    designer->setPlaceholderText("Inserisci il/i designer.");
    fields->addWidget(designer,2,1);

    fields->addWidget(lLenght,3,0);
    fields->addWidget(lenght,3,1);

    fields->addWidget(lWeight,4,0);
    fields->addWidget(weight,4,1);

    fields->addWidget(lMaterials,5,0);
    materials->setPlaceholderText("Inserisci i materiali.");
    fields->addWidget(materials,5,1);

    fields->addWidget(lPrice,6,0);
    fields->addWidget(price,6,1);

    fields->addWidget(lLicense,7,0);
    fields->addWidget(licenseNeeded,7,1);

    selImg->setMaximumSize(selImg->width(),selImg->height());

    selImg->setText("Scegli la foto");
    selImg->setIcon(QIcon(":/Immagini/choosefile.png"));

    img->addWidget(selImg);
    img->addWidget(lImg);

    btn->addWidget(reset);
    btn->addWidget(inserisci);

    form->addItem(fields);
    form->addItem(img);
    form->addItem(btn);

    setAllExtraNotVisible();

    //SPIN BOX RANGE
    lenght->setMaximum(1500);
    weight->setMaximum(9999);
    price->setMaximum(999999);
    rateOfFire->setMaximum(9999);
    firingRange->setMaximum(99999);
    muzzleVelocity->setMaximum(9999);
    barrelLength->setMaximum(1000);
    joule->setMaximum(100000);
    bladeLength->setMaximum(300);
    fillingWeight->setMaximum(9999);

    //Placeholders
    caliber->setPlaceholderText("Inserisci il calibro.");
    feedSystem->setPlaceholderText("Inserisci il tipo di alimentazione. (Es. Caricatori standard da 30 colpi, Caricatore a tamburo da 100 colpi)");
    gasUsed->setPlaceholderText("Inserisci il gas compresso utilizzato. (Es. CO2, Aria)");
    cartridge->setPlaceholderText("Inserisci il tipo di munizioni. (Es. 45ACP, 7.62x39mm, .338 Lapua Magnum)");
    bladeType->setPlaceholderText("Inserisci il tipo di lama. ");
    hiltType->setPlaceholderText("Inserisci il tipo di impugnatura e/o il materiale.(Es. Polimero, a due mani, con crociera a bracci diritti  )");
    filling->setPlaceholderText("Inserisci il tipo di lama. ");
    detonationMechanism->setPlaceholderText("Inserisci il tipo di impugnatura e/o il materiale.(Es. Polimero, a due mani, con crociera a bracci diritti  )");

    //CONNECT
    connect(tipoArma,SIGNAL(activated(int)),this,SLOT(slotViewElements(int)));
    connect(selImg,SIGNAL(clicked()), this, SLOT(slotChooseImage()));
    connect(reset,SIGNAL(clicked()),this,SLOT(slotReset()));
}
void Inserimento::setAllExtraNotVisible()const {
    setArmaDaFuocoVisible(false);
    setArmaPneumaticaVisible(false);
    setArmaAPolvereVisible(false);
    setArmaBiancaVisible(false);
    setEsplosivoVisible(false);
}

void Inserimento::setArmaDaFuocoVisible(bool b)const {

    rateOfFire->setEnabled(b);
    firingRange->setEnabled(b);
    muzzleVelocity->setEnabled(b);
    barrelLength->setEnabled(b);
    caliber->setEnabled(b);
    feedSystem->setEnabled(b);

    rateOfFire->setVisible(b);
    firingRange->setVisible(b);
    muzzleVelocity->setVisible(b);
    barrelLength->setVisible(b);
    caliber->setVisible(b);
    feedSystem->setVisible(b);
    lRateOfFire->setVisible(b);
    lFiringRange->setVisible(b);
    lMuzzleVelocity->setVisible(b);
    lBarrelLength->setVisible(b);
    lCaliber->setVisible(b);
    lFeedSystem->setVisible(b);

    if(!b){
        fields->removeWidget(lRateOfFire);
        fields->removeWidget(lFiringRange);
        fields->removeWidget(lMuzzleVelocity);
        fields->removeWidget(lBarrelLength);
        fields->removeWidget(lCaliber);
        fields->removeWidget(lFeedSystem);
        fields->removeWidget(rateOfFire);
        fields->removeWidget(firingRange);
        fields->removeWidget(muzzleVelocity);
        fields->removeWidget(barrelLength);
        fields->removeWidget(caliber);
        fields->removeWidget(feedSystem);
    }
    else{
        fields->addWidget(lRateOfFire,0,2);
        fields->addWidget(rateOfFire,0,3);

        fields->addWidget(lFiringRange,1,2);
        fields->addWidget(firingRange,1,3);

        fields->addWidget(lMuzzleVelocity,2,2);
        fields->addWidget(muzzleVelocity,2,3);

        fields->addWidget(lBarrelLength,3,2);
        fields->addWidget(barrelLength,3,3);

        fields->addWidget(lCaliber,4,2);
        fields->addWidget(caliber,4,3);

        fields->addWidget(lFeedSystem,5,2);
        fields->addWidget(feedSystem,5,3);
    }

}

void Inserimento::setArmaPneumaticaVisible(bool b)const {

    joule->setEnabled(b);
    gasUsed->setEnabled(b);

    joule->setVisible(b);
    gasUsed->setVisible(b);
    lJoule->setVisible(b);
    lGasUsed->setVisible(b);

    if(!b){
        fields->removeWidget(lJoule);
        fields->removeWidget(lGasUsed);
        fields->removeWidget(joule);
        fields->removeWidget(gasUsed);
    }

}

void Inserimento::setArmaAPolvereVisible(bool b)const {

    cartridge->setEnabled(b);

    cartridge->setVisible(b);
    lCartridge->setVisible(b);

    if(!b){
        fields->removeWidget(lCartridge);
        fields->removeWidget(cartridge);
    }

}

void Inserimento::setArmaBiancaVisible(bool b)const {

    bladeLength->setEnabled(b);
    hiltType->setEnabled(b);
    bladeType->setEnabled(b);

    bladeLength->setVisible(b);
    hiltType->setVisible(b);
    bladeType->setVisible(b);
    lBladeLength->setVisible(b);
    lHiltType->setVisible(b);
    lBladeType->setVisible(b);

    if(!b){
        fields->removeWidget(lBladeLength);
        fields->removeWidget(lHiltType);
        fields->removeWidget(lBladeType);
        fields->removeWidget(bladeLength);
        fields->removeWidget(hiltType);
        fields->removeWidget(bladeType);
    }

}
void Inserimento::setEsplosivoVisible(bool b)const {

    filling->setEnabled(b);
    detonationMechanism->setEnabled(b);
    fillingWeight->setEnabled(b);

    filling->setVisible(b);
    detonationMechanism->setVisible(b);
    fillingWeight->setVisible(b);
    lFilling->setVisible(b);
    lDetonationMechanism->setVisible(b);
    lFillingWeight->setVisible(b);

    if(!b){
        fields->removeWidget(lFilling);
        fields->removeWidget(lDetonationMechanism);
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(filling);
        fields->removeWidget(detonationMechanism);
        fields->removeWidget(fillingWeight);
    }

}
void Inserimento::slotViewElements(int index)const{
    switch (index) {
        case 0:
        setAllExtraNotVisible();
        form->update();
        fields->update();
        break;
        case 1://ARMA PNEUMATICA
        setArmaDaFuocoVisible(true);
        setArmaPneumaticaVisible(true);
        setArmaAPolvereVisible(false);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(false);

        fields->addWidget(lJoule,6,2);
        fields->addWidget(joule,6,3);

        fields->addWidget(lGasUsed,7,2);
        fields->addWidget(gasUsed,7,3);

        form->update();
        fields->update();

        break;
        case 2://ARMA A POLVERE
        //Rimozione campi specifici dalla finestra
        setArmaDaFuocoVisible(true);
        setArmaPneumaticaVisible(false);
        setArmaAPolvereVisible(true);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(false);

        fields->addWidget(lCartridge,7,2);
        fields->addWidget(cartridge,7,3);

        form->update();
        fields->update();

        break;
        case 3://ARMA BIANCA
        setArmaDaFuocoVisible(false);
        setArmaPneumaticaVisible(false);
        setArmaAPolvereVisible(false);
        setArmaBiancaVisible(true);
        setEsplosivoVisible(false);

        fields->addWidget(lBladeLength,0,2);
        fields->addWidget(bladeLength,0,3);

        fields->addWidget(lBladeType,1,2);
        fields->addWidget(bladeType,1,3);

        fields->addWidget(lHiltType,2,2);
        fields->addWidget(hiltType,2,3);

        form->update();
        fields->update();

        break;
        case 4://ESPLOSIVO

        setArmaDaFuocoVisible(false);
        setArmaPneumaticaVisible(false);
        setArmaAPolvereVisible(false);
        setArmaBiancaVisible(false);
        setEsplosivoVisible(true);

        //inserimento specifici classe
        fields->addWidget(lFilling,0,2);
        fields->addWidget(filling,0,3);

        fields->addWidget(lDetonationMechanism,1,2);
        fields->addWidget(detonationMechanism,1,3);

        fields->addWidget(lFillingWeight,2,2);
        fields->addWidget(fillingWeight,2,3);

        form->update();
        fields->update();

        break;
    }

}
void Inserimento::slotReset()const{
            tipoArma->setCurrentIndex(0);
            lenght->setValue(0);
            weight->setValue(0);
            price->setValue(0);
            designer->setText("");
            materials->setText("");
            name->setText("");
            licenseNeeded->setChecked(0);
            rateOfFire->setValue(0);
            firingRange->setValue(0);
            muzzleVelocity->setValue(0);
            barrelLength->setValue(0);
            caliber->setText("");
            feedSystem->setText("");
            joule->setValue(0);
            gasUsed->setText("");
            cartridge->setText("");
            bladeLength->setValue(0);
            hiltType->setText("");
            bladeType->setText("");
            filling->setText("");
            detonationMechanism->setText("");
            fillingWeight->setValue(0);
            lImg->clear();
            setAllExtraNotVisible();
}
void Inserimento::slotChooseImage(){
    QString file= QFileDialog::getOpenFileName(
                this,
                tr("Choose image"),
                "../",
                "Image file (*.jpg)"
                );
        QFileInfo relativePath(file);
        if(file!=""){
                QImage im(file);
                QByteArray  array;
                QBuffer b(&array);

                im.save(&b,"JPG");
                lImg->setPixmap(QPixmap::fromImage(im));
                imageRawData=utils->getRawData(im);
            }

}

comboBoxTipoArma* Inserimento::getCBTipoArma(){
    return tipoArma;
}

QPushButton* Inserimento::getInserisci(){
    return inserisci;
}

Arma* Inserimento::getWeaponToInsert(){
    switch (tipoArma->currentIndex()) {
        case 1:
            armaDaInserire=new ArmaPneumatica(
                        //Arma
                        lenght->value(),
                        weight->value(),
                        price->value(),
                        designer->text().toStdString(),
                        materials->toPlainText().toStdString(),
                        name->text().toStdString(),
                        imageRawData,
                        licenseNeeded->isChecked(),
                        //ArmaDaFuoco
                        rateOfFire->value(),
                        firingRange->value(),
                        muzzleVelocity->value(),
                        barrelLength->value(),
                        caliber->text().toStdString(),
                        feedSystem->toPlainText().toStdString(),
                        //ArmaPneumatica
                        joule->value(),
                        gasUsed->text().toStdString()
                        );
        break;
        case 2:
            armaDaInserire=new ArmaAPolvere(
                        //Arma
                        lenght->value(),
                        weight->value(),
                        price->value(),
                        designer->text().toStdString(),
                        materials->toPlainText().toStdString(),
                        name->text().toStdString(),
                        imageRawData,
                        licenseNeeded->isChecked(),
                        //ArmaDaFuoco
                        rateOfFire->value(),
                        firingRange->value(),
                        muzzleVelocity->value(),
                        barrelLength->value(),
                        caliber->text().toStdString(),
                        feedSystem->toPlainText().toStdString(),
                        //ArmaAPolvere
                        cartridge->toPlainText().toStdString()
                        );
        break;
        case 3:
            armaDaInserire=new ArmaBianca(
                        //Arma
                        lenght->value(),
                        weight->value(),
                        price->value(),
                        designer->text().toStdString(),
                        materials->toPlainText().toStdString(),
                        name->text().toStdString(),
                        imageRawData,
                        licenseNeeded->isChecked(),
                        //ArmaBianca
                        bladeLength->value(),
                        bladeType->toPlainText().toStdString(),
                        hiltType->toPlainText().toStdString()
                        );
        break;
        case 4:
            armaDaInserire=new Esplosivo(
                        //Arma
                        lenght->value(),
                        weight->value(),
                        price->value(),
                        designer->text().toStdString(),
                        materials->toPlainText().toStdString(),
                        name->text().toStdString(),
                        imageRawData,
                        licenseNeeded->isChecked(),
                        //Esplosivo
                        filling->text().toStdString(),
                        detonationMechanism->toPlainText().toStdString(),
                        fillingWeight->value()
                        );
        break;
    }
    return armaDaInserire;
}















