#ifndef SHOWRISULTATIRICERCA_H
#define SHOWRISULTATIRICERCA_H
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "dettagli.h"
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
    Dettagli* getDettagliRicerca();
    QPushButton* getEliminaTutto();
    List<Arma*>::iterator getCurrent();
    void updateOnSave();
private:
    QPushButton *dettagli;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *eliminaTutto;
    QLabel *img;
    Dettagli *d;
    QVBoxLayout *form;
    QHBoxLayout *buttons;
    List<Arma*>::iterator first,last,current;
    imageUtility* imgUti;
private slots:
    void dettagliClicked();
    void nextClicked();
    void prevClicked();
    void updateOnDelete();


};

#endif // SHOWRISULTATIRICERCA_H
