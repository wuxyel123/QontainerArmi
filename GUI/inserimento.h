#ifndef INSERIMENTO_H
#define INSERIMENTO_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QIcon>
#include <QCheckBox>
#include <QMessageBox>
#include "comboboxtipoarma.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>
#include "GERARCHIA/arma.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/esplosivo.h"
#include "imageutility.h"

class Inserimento : public QDialog
{
    Q_OBJECT
public:
    explicit Inserimento(QWidget *parent = nullptr);
    comboBoxTipoArma* getCBTipoArma()const;
    QPushButton* getInserisci()const;
    Arma* getWeaponToInsert();//Modifica imageRawData

private:
    void setAllExtraNotVisible() const;
    void setArmaDaFuocoVisible(bool) const;//Questo e i seguenti set modificano anche l'enabled
    void setArmaPneumaticaVisible(bool) const;
    void setArmaAPolvereVisible(bool) const;
    void setArmaBiancaVisible(bool) const;
    void setEsplosivoVisible(bool) const;
    comboBoxTipoArma *tipoArma;

    //ARMA
    QLabel *lLenght,*lWeight,*lPrice,*lDesigner,*lMaterials,*lName,*lLicense;
    QDoubleSpinBox *lenght;
    QDoubleSpinBox *weight;
    QDoubleSpinBox *price;
    QLineEdit *designer;
    QTextEdit *materials;
    QLineEdit *name;
    QPushButton *selImg;
    QCheckBox *licenseNeeded;


    //ARMA DA FUOCO
    QLabel *lRateOfFire,*lFiringRange,*lMuzzleVelocity,*lBarrelLength,*lCaliber,*lFeedSystem;
    QSpinBox *rateOfFire;
    QSpinBox *firingRange;
    QSpinBox *muzzleVelocity;
    QDoubleSpinBox *barrelLength;
    QLineEdit *caliber;
    QTextEdit *feedSystem;

    //ARMA PNEUMATICA
    QLabel *lJoule,*lGasUsed;
    QDoubleSpinBox *joule;
    QLineEdit *gasUsed;

    //ARMA A POLVERE
    QLabel *lCartridge;
    QTextEdit *cartridge;
    
    //ARMA BIANCA
    QLabel *lBladeLength,*lHiltType,*lBladeType;
    QDoubleSpinBox *bladeLength;
    QTextEdit *hiltType;
    QTextEdit *bladeType;    
    
    //ESPLOSIVO
    QLabel *lFilling,*lDetonationMechanism,*lFillingWeight;
    QLineEdit *filling;
    QTextEdit *detonationMechanism;
    QDoubleSpinBox *fillingWeight;

    //BOTTONI
    QPushButton *reset;
    QPushButton *inserisci;

    //LAYOUTS
    QVBoxLayout* form;
    QGridLayout* fields;
    QHBoxLayout* btn;
    QHBoxLayout* img;

    QLabel *lImg;

    Arma* armaDaInserire;
    std::string imageRawData;
    imageUtility* utils;

private slots:
    void slotViewElements(int)const;
    void slotChooseImage();
public slots:
    void slotReset()const;

signals:

};

#endif // INSERIMENTO_H
