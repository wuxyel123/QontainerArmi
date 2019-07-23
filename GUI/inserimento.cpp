#include "inserimento.h"

Inserimento::Inserimento(QWidget *parent) : QDialog(parent),
    tipoArma(new comboBoxTipoArma(this)),

    lLenght(new QLabel("Lunghezza (cm):",this)),
    lWeight(new QLabel("Peso (kg):",this)),
    lPrice(new QLabel("Prezzo (€):",this)),
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

    //CONNECT
    connect(tipoArma,SIGNAL(activated(int)),this,SLOT(slotViewElements(int)));
    connect(selImg,SIGNAL(clicked()), this, SLOT(slotChooseImage()));
    connect(reset,SIGNAL(clicked()),this,SLOT(slotReset()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(slotInserisci()));
}
void Inserimento::setAllExtraNotVisible()const {
    //Settaggio campi specifici a disabled
    rateOfFire->setEnabled(false);
    firingRange->setEnabled(false);
    muzzleVelocity->setEnabled(false);
    barrelLength->setEnabled(false);
    caliber->setEnabled(false);
    feedSystem->setEnabled(false);

    joule->setEnabled(false);
    gasUsed->setEnabled(false);

    cartridge->setEnabled(false);

    bladeLength->setEnabled(false);
    hiltType->setEnabled(false);
    bladeType->setEnabled(false);

    filling->setEnabled(false);
    detonationMechanism->setEnabled(false);
    fillingWeight->setEnabled(false);

    //Settaggio campi specifici a !visible
    rateOfFire->setVisible(false);
    firingRange->setVisible(false);
    muzzleVelocity->setVisible(false);
    barrelLength->setVisible(false);
    caliber->setVisible(false);
    feedSystem->setVisible(false);
    lRateOfFire->setVisible(false);
    lFiringRange->setVisible(false);
    lMuzzleVelocity->setVisible(false);
    lBarrelLength->setVisible(false);
    lCaliber->setVisible(false);
    lFeedSystem->setVisible(false);

    joule->setVisible(false);
    gasUsed->setVisible(false);
    lJoule->setVisible(false);
    lGasUsed->setVisible(false);

    cartridge->setVisible(false);
    lCartridge->setVisible(false);

    bladeLength->setVisible(false);
    hiltType->setVisible(false);
    bladeType->setVisible(false);
    lBladeLength->setVisible(false);
    lHiltType->setVisible(false);
    lBladeType->setVisible(false);

    filling->setVisible(false);
    detonationMechanism->setVisible(false);
    fillingWeight->setVisible(false);
    lFilling->setVisible(false);
    lDetonationMechanism->setVisible(false);
    lFillingWeight->setVisible(false);
}
void Inserimento::slotViewElements(int index)const{
    switch (index) {
        case 0:
        //Rimozione campi specifici dalla finestra
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

        fields->removeWidget(lJoule);
        fields->removeWidget(lGasUsed);
        fields->removeWidget(joule);
        fields->removeWidget(gasUsed);

        fields->removeWidget(lCartridge);
        fields->removeWidget(cartridge);

        fields->removeWidget(lBladeLength);
        fields->removeWidget(lHiltType);
        fields->removeWidget(lBladeType);
        fields->removeWidget(bladeLength);
        fields->removeWidget(hiltType);
        fields->removeWidget(bladeType);

        fields->removeWidget(lFilling);
        fields->removeWidget(lDetonationMechanism);
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(filling);
        fields->removeWidget(detonationMechanism);
        fields->removeWidget(fillingWeight);

        setAllExtraNotVisible();

        form->update();
        fields->update();

        break;
        case 1://PNEUMATICA
        //Rimozione campi specifici dalla finestra
        fields->removeWidget(lCartridge);
        fields->removeWidget(cartridge);

        fields->removeWidget(lBladeLength);
        fields->removeWidget(lHiltType);
        fields->removeWidget(lBladeType);
        fields->removeWidget(bladeLength);
        fields->removeWidget(hiltType);
        fields->removeWidget(bladeType);

        fields->removeWidget(lFilling);
        fields->removeWidget(lDetonationMechanism);
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(filling);
        fields->removeWidget(detonationMechanism);
        fields->removeWidget(fillingWeight);

        rateOfFire->setVisible(true);
        firingRange->setVisible(true);
        muzzleVelocity->setVisible(true);
        barrelLength->setVisible(true);
        caliber->setVisible(true);
        feedSystem->setVisible(true);
        lRateOfFire->setVisible(true);
        lFiringRange->setVisible(true);
        lMuzzleVelocity->setVisible(true);
        lBarrelLength->setVisible(true);
        lCaliber->setVisible(true);
        lFeedSystem->setVisible(true);

        joule->setVisible(true);
        gasUsed->setVisible(true);
        lJoule->setVisible(true);
        lGasUsed->setVisible(true);

        cartridge->setVisible(false);
        lCartridge->setVisible(false);

        bladeLength->setVisible(false);
        hiltType->setVisible(false);
        bladeType->setVisible(false);
        lBladeLength->setVisible(false);
        lHiltType->setVisible(false);
        lBladeType->setVisible(false);

        filling->setVisible(false);
        detonationMechanism->setVisible(false);
        fillingWeight->setVisible(false);
        lFilling->setVisible(false);
        lDetonationMechanism->setVisible(false);
        lFillingWeight->setVisible(false);

        //Settaggio campi specifici a disabled/enabled
        rateOfFire->setEnabled(true);
        firingRange->setEnabled(true);
        muzzleVelocity->setEnabled(true);
        barrelLength->setEnabled(true);
        caliber->setEnabled(true);
        feedSystem->setEnabled(true);

        joule->setEnabled(true);
        gasUsed->setEnabled(true);

        cartridge->setEnabled(false);

        bladeLength->setEnabled(false);
        hiltType->setEnabled(false);
        bladeType->setEnabled(false);

        filling->setEnabled(false);
        detonationMechanism->setEnabled(false);
        fillingWeight->setEnabled(false);

        //inserimento campi specifici in fields
        fields->addWidget(lRateOfFire,0,2);
        fields->addWidget(rateOfFire,0,3);

        fields->addWidget(lFiringRange,1,2);
        fields->addWidget(firingRange,1,3);

        fields->addWidget(lMuzzleVelocity,2,2);
        fields->addWidget(muzzleVelocity,2,3);

        fields->addWidget(lBarrelLength,3,2);
        fields->addWidget(barrelLength,3,3);

        fields->addWidget(lCaliber,4,2);
        caliber->setPlaceholderText("Inserisci il calibro.");
        fields->addWidget(caliber,4,3);

        fields->addWidget(lFeedSystem,5,2);
        feedSystem->setPlaceholderText("Inserisci il tipo di alimentazione.");
        fields->addWidget(feedSystem,5,3);

        fields->addWidget(lJoule,6,2);
        fields->addWidget(joule,6,3);

        fields->addWidget(lGasUsed,7,2);
        gasUsed->setPlaceholderText("Inserisci il gas compresso utilizzato. (Es. CO2, Aria)");
        fields->addWidget(gasUsed,7,3);

        form->update();
        fields->update();

        break;
        case 2://ARMA A POLVERE
        //Rimozione campi specifici dalla finestra
        fields->removeWidget(lJoule);
        fields->removeWidget(lGasUsed);
        fields->removeWidget(joule);
        fields->removeWidget(gasUsed);

        fields->removeWidget(lBladeLength);
        fields->removeWidget(lHiltType);
        fields->removeWidget(lBladeType);
        fields->removeWidget(bladeLength);
        fields->removeWidget(hiltType);
        fields->removeWidget(bladeType);

        fields->removeWidget(lFilling);
        fields->removeWidget(lDetonationMechanism);
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(filling);
        fields->removeWidget(detonationMechanism);
        fields->removeWidget(fillingWeight);

        rateOfFire->setVisible(true);
        firingRange->setVisible(true);
        muzzleVelocity->setVisible(true);
        barrelLength->setVisible(true);
        caliber->setVisible(true);
        feedSystem->setVisible(true);
        lRateOfFire->setVisible(true);
        lFiringRange->setVisible(true);
        lMuzzleVelocity->setVisible(true);
        lBarrelLength->setVisible(true);
        lCaliber->setVisible(true);
        lFeedSystem->setVisible(true);

        joule->setVisible(false);
        gasUsed->setVisible(false);
        lJoule->setVisible(false);
        lGasUsed->setVisible(false);

        cartridge->setVisible(true);
        lCartridge->setVisible(true);

        bladeLength->setVisible(false);
        hiltType->setVisible(false);
        bladeType->setVisible(false);
        lBladeLength->setVisible(false);
        lHiltType->setVisible(false);
        lBladeType->setVisible(false);

        filling->setVisible(false);
        detonationMechanism->setVisible(false);
        fillingWeight->setVisible(false);
        lFilling->setVisible(false);
        lDetonationMechanism->setVisible(false);
        lFillingWeight->setVisible(false);

        //Settaggio campi specifici a disabled/enabled
        rateOfFire->setEnabled(true);
        firingRange->setEnabled(true);
        muzzleVelocity->setEnabled(true);
        barrelLength->setEnabled(true);
        caliber->setEnabled(true);
        feedSystem->setEnabled(true);

        joule->setEnabled(false);
        gasUsed->setEnabled(false);

        cartridge->setEnabled(true);

        bladeLength->setEnabled(false);
        hiltType->setEnabled(false);
        bladeType->setEnabled(false);

        filling->setEnabled(false);
        detonationMechanism->setEnabled(false);
        fillingWeight->setEnabled(false);

        //inserimento campi specifici in fields
        fields->addWidget(lRateOfFire,0,2);
        fields->addWidget(rateOfFire,0,3);

        fields->addWidget(lFiringRange,1,2);
        fields->addWidget(firingRange,1,3);

        fields->addWidget(lMuzzleVelocity,2,2);
        fields->addWidget(muzzleVelocity,2,3);

        fields->addWidget(lBarrelLength,3,2);
        fields->addWidget(barrelLength,3,3);

        fields->addWidget(lCaliber,4,2);
        caliber->setPlaceholderText("Inserisci il calibro.");
        fields->addWidget(caliber,4,3);

        fields->addWidget(lFeedSystem,5,2);
        feedSystem->setPlaceholderText("Inserisci il tipo di alimentazione.");
        fields->addWidget(feedSystem,5,3);

        fields->addWidget(lCartridge,7,2);
        cartridge->setPlaceholderText("Inserisci il tipo di munizioni. (Es. 45ACP, 7.62x39mm, .338 Lapua Magnum)");
        fields->addWidget(cartridge,7,3);

        form->update();
        fields->update();

        break;
        case 3://ARMA BIANCA
        //Rimozione campi specifici dalla finestra
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

        fields->removeWidget(lJoule);
        fields->removeWidget(lGasUsed);
        fields->removeWidget(joule);
        fields->removeWidget(gasUsed);

        fields->removeWidget(lCartridge);
        fields->removeWidget(cartridge);

        fields->removeWidget(lFilling);
        fields->removeWidget(lDetonationMechanism);
        fields->removeWidget(lFillingWeight);
        fields->removeWidget(filling);
        fields->removeWidget(detonationMechanism);
        fields->removeWidget(fillingWeight);

        rateOfFire->setVisible(false);
        firingRange->setVisible(false);
        muzzleVelocity->setVisible(false);
        barrelLength->setVisible(false);
        caliber->setVisible(false);
        feedSystem->setVisible(false);
        lRateOfFire->setVisible(false);
        lFiringRange->setVisible(false);
        lMuzzleVelocity->setVisible(false);
        lBarrelLength->setVisible(false);
        lCaliber->setVisible(false);
        lFeedSystem->setVisible(false);

        joule->setVisible(false);
        gasUsed->setVisible(false);
        lJoule->setVisible(false);
        lGasUsed->setVisible(false);

        cartridge->setVisible(false);
        lCartridge->setVisible(false);

        bladeLength->setVisible(true);
        hiltType->setVisible(true);
        bladeType->setVisible(true);
        lBladeLength->setVisible(true);
        lHiltType->setVisible(true);
        lBladeType->setVisible(true);

        filling->setVisible(false);
        detonationMechanism->setVisible(false);
        fillingWeight->setVisible(false);
        lFilling->setVisible(false);
        lDetonationMechanism->setVisible(false);
        lFillingWeight->setVisible(false);

        //Settaggio campi specifici a disabled/enabled
        rateOfFire->setEnabled(false);
        firingRange->setEnabled(false);
        muzzleVelocity->setEnabled(false);
        barrelLength->setEnabled(false);
        caliber->setEnabled(false);
        feedSystem->setEnabled(false);

        joule->setEnabled(false);
        gasUsed->setEnabled(false);

        cartridge->setEnabled(false);

        bladeLength->setEnabled(true);
        hiltType->setEnabled(true);
        bladeType->setEnabled(true);

        filling->setEnabled(false);
        detonationMechanism->setEnabled(false);
        fillingWeight->setEnabled(false);

        //inserimento specifici classe
        fields->addWidget(lBladeLength,0,2);
        fields->addWidget(bladeLength,0,3);

        fields->addWidget(lBladeType,1,2);
        bladeType->setPlaceholderText("Inserisci il tipo di lama. ");
        fields->addWidget(bladeType,1,3);

        fields->addWidget(lHiltType,2,2);
        hiltType->setPlaceholderText("Inserisci il tipo di impugnatura e/o il materiale.(Es. Polimero, a due mani, con crociera a bracci diritti  )");
        fields->addWidget(hiltType,2,3);



        form->update();
        fields->update();

        break;
        case 4://ESPLOSIVO

        //Rimozione campi specifici dalla finestra
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

        fields->removeWidget(lJoule);
        fields->removeWidget(lGasUsed);
        fields->removeWidget(joule);
        fields->removeWidget(gasUsed);

        fields->removeWidget(lCartridge);
        fields->removeWidget(cartridge);

        fields->removeWidget(lBladeLength);
        fields->removeWidget(lHiltType);
        fields->removeWidget(lBladeType);
        fields->removeWidget(bladeLength);
        fields->removeWidget(hiltType);
        fields->removeWidget(bladeType);

        rateOfFire->setVisible(false);
        firingRange->setVisible(false);
        muzzleVelocity->setVisible(false);
        barrelLength->setVisible(false);
        caliber->setVisible(false);
        feedSystem->setVisible(false);
        lRateOfFire->setVisible(false);
        lFiringRange->setVisible(false);
        lMuzzleVelocity->setVisible(false);
        lBarrelLength->setVisible(false);
        lCaliber->setVisible(false);
        lFeedSystem->setVisible(false);

        joule->setVisible(false);
        gasUsed->setVisible(false);
        lJoule->setVisible(false);
        lGasUsed->setVisible(false);

        cartridge->setVisible(false);
        lCartridge->setVisible(false);

        bladeLength->setVisible(false);
        hiltType->setVisible(false);
        bladeType->setVisible(false);
        lBladeLength->setVisible(false);
        lHiltType->setVisible(false);
        lBladeType->setVisible(false);

        filling->setVisible(true);
        detonationMechanism->setVisible(true);
        fillingWeight->setVisible(true);
        lFilling->setVisible(true);
        lDetonationMechanism->setVisible(true);
        lFillingWeight->setVisible(true);

        //Settaggio campi specifici a disabled/enabled
        rateOfFire->setEnabled(false);
        firingRange->setEnabled(false);
        muzzleVelocity->setEnabled(false);
        barrelLength->setEnabled(false);
        caliber->setEnabled(false);
        feedSystem->setEnabled(false);

        joule->setEnabled(false);
        gasUsed->setEnabled(false);

        cartridge->setEnabled(false);

        bladeLength->setEnabled(false);
        hiltType->setEnabled(false);
        bladeType->setEnabled(false);

        filling->setEnabled(true);
        detonationMechanism->setEnabled(true);
        fillingWeight->setEnabled(true);

        //inserimento specifici classe
        fields->addWidget(lFilling,0,2);
        filling->setPlaceholderText("Inserisci il tipo di lama. ");
        fields->addWidget(filling,0,3);

        fields->addWidget(lDetonationMechanism,1,2);
        detonationMechanism->setPlaceholderText("Inserisci il tipo di impugnatura e/o il materiale.(Es. Polimero, a due mani, con crociera a bracci diritti  )");
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
            }

}
void Inserimento::slotInserisci(){
    if (tipoArma->currentIndex()==0 ){
        QMessageBox::warning(this,"Attenzione","Devi selezionare il tipo di arma che vuoi inserire.");
    }
    else{
        QMessageBox checkCampi;
        checkCampi.setWindowTitle("Inserimento");
        checkCampi.setIcon(QMessageBox::Question);
        checkCampi.setText("Procedere all'inserimento?");
        checkCampi.setInformativeText("Una volta confermato l'inserimento, non sarà più possibile modificare i campi dati ad eccezzione di prezzo e foto.");
        checkCampi.setStandardButtons(QMessageBox::Cancel |QMessageBox::Save);
        checkCampi.setDefaultButton(QMessageBox::Save);
        int ret = checkCampi.exec();
        switch (ret) {
            case QMessageBox::Save:
                //salvataggio dati in container da aggiungere
            break;
            case QMessageBox::Cancel:
               //Non deve far nulla
            break;
            default:
                QMessageBox::critical(this,"ERRORE!","Qualcosa è andato storto durante l'inserimento dei dati.");
            break;
        }
    }
}
