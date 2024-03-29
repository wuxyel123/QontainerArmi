#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "inserimento.h"
#include "ricerca.h"
#include "showrisultatiricerca.h"
#include "dettagli.h"
#include "GERARCHIA/arma.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/esplosivo.h"
#include "modello.h"
#include "imageutility.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(Modello*,QWidget *parent = nullptr);
    ~Widget();
    void pathSaveLoad();
    void anyDataFound(bool);
    void risRicSave()const;

private:
    Ui::Widget *ui;
    Modello* modello;
    QPushButton *cerca;
    QPushButton *inserisci;
    QPushButton *visualizza;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *loadNewFile;
    QLabel *img;
    Ricerca *r;
    showRisultatiRicerca *risRic;
    Inserimento *i;    
    Dettagli *d;
    imageUtility* imgUti;
    Arma* toInsert;
    List<Arma*>::iterator first,last,current;
    bool noData;

signals:

private slots:
    void srcClicked()const;
    void insertClicked()const;
    void visualizzaClicked()const;
    void nextClicked();
    void prevClicked();
    void slotLoad();
    //SLOT PER SIGNALS ESTERNI
    void slotInserimento();
    void slotCerca();
    void slotDelete();
    void slotSalva()const;
    void slotSalvaFromSrc();
    void slotEliminaTutto();
};

#endif // WIDGET_H
