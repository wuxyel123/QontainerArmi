#ifndef LAYOUTRICERCAELIMINA_H
#define LAYOUTRICERCAELIMINA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include "comboboxtipoarma.h"
#include <QLineEdit>
#include <QTextEdit>
#include <QDoubleSpinBox>

class layoutRicercaElimina : public QWidget
{
    Q_OBJECT
public:
    explicit layoutRicercaElimina(QWidget *parent = nullptr);
    int getTipo()const;
    QString getName()const;
    QString getDesigner()const;
    double getPriceMin()const;
    double getPriceMax()const;
    bool getLicenseNeeded()const;
    QString getCaliber()const;
    double getJoule()const;
    double getBladeLengthMin()const;
    double getBladeLengthMax()const;
    double getFillingWeight()const;

private:
    void setAllExtraNotVisible() const;
    void setArmaDaFuocoVisible(bool) const;//Questo e i seguenti set modificano anche l'enabled
    void setArmaPneumaticaVisible(bool) const;
    void setArmaBiancaVisible(bool) const;
    void setEsplosivoVisible(bool) const;
    comboBoxTipoArma *tipoArma;

    //ARMA
    QLabel *lName,*lDesigner,*lPriceMin,*lPriceMax,*lLicense;
    QLineEdit *name;
    QLineEdit *designer;
    QDoubleSpinBox *pricetMin;
    QDoubleSpinBox *priceMax;
    QCheckBox *licenseNeeded;

    //ARMA DA FUOCO
    QLabel *lCaliber;
    QLineEdit *caliber;

    //ARMA PNEUMATICA
    QLabel *lJoule;
    QDoubleSpinBox *joule;

    //ARMA A POLVERE
    /*Il calibro presente nella classe arma è sufficiente
     * per la ricerca/eliminazione delle armi di questo tipo*/

    //ARMA BIANCA
    QLabel *lBladeLengthMin,*lBladeLengthMax;
    QDoubleSpinBox *bladeLengthMin,*bladeLengthMax;

    //ESPLOSIVO
    QLabel *lFillingWeight;
    QDoubleSpinBox *fillingWeight;

    //LAYOUT
    QGridLayout* fields;

signals:

public slots:
    void slotViewElements(int)const;
    void slotReset()const;
private slots:
    void slotPrice(double);
    void slotBladeLength(double);
};

#endif // LAYOUTRICERCAELIMINA_H
