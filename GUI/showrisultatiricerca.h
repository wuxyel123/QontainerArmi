#ifndef SHOWRISULTATIRICERCA_H
#define SHOWRISULTATIRICERCA_H
#include <QDialog>
#include <QFileDialog>
#include <QBuffer>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include "GERARCHIA/arma.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/esplosivo.h"
#include "modello.h"
#include "imageutility.h"

class showRisultatiRicerca : public QDialog
{
     Q_OBJECT
public:
    explicit showRisultatiRicerca(QWidget *parent = nullptr);
    void setIt(List<Arma*>::iterator,List<Arma*>::iterator);
    QPushButton* getEliminaTutto();
    QPushButton* getSalva();
    QPushButton* getElimina();
    List<Arma*>::iterator getCurrent();
    void updateOnSave();
    std::string getImg()const;
    double getPrice()const;
    void layoutModificaVisible(bool b);
private:
    QPushButton *modifica;
    QPushButton *elimina;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *eliminaTutto;
    QTextEdit *det;
    QLabel *img;
    QVBoxLayout *form;
    QHBoxLayout *buttons,*arma;
    List<Arma*>::iterator first,last,current;
    imageUtility* imgUti;
    QLabel* lPrice;
    QDoubleSpinBox *price;
    QLabel* lImg;
    QPushButton* btnImg;
    QPushButton* salva;
    QGridLayout* lModifica;
    std::string imageRawData;
private slots:
    void modificaClicked();
    void nextClicked();
    void prevClicked();
    void updateOnDelete();
    void slotChooseImage();


};

#endif // SHOWRISULTATIRICERCA_H
