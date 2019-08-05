#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "inserimento.h"
#include "ricerca.h"
#include "elimina.h"
#include "dettagli.h"
#include "GERARCHIA/arma.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/esplosivo.h"
#include "modello.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(Modello*,QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Modello* modello;
    QPushButton *cerca;
    QPushButton *inserisci;
    QPushButton *visualizza;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *advancedDelete;
    QLabel *img;
    Ricerca *r;
    Elimina *e;
    Inserimento *i;    
    Dettagli *d;



signals:

public slots:
    void srcClicked();
    void insertClicked();
    void visualizzaClicked();
    void nextClicked();
    void prevClicked();
    void advancedDeleteClicked();
    //SLOT PER SIGNALS ESTERNI
    void slotInserimento();
    void slotCerca();
    void slotElimina();//Eliminazione avanzata
    void slotDelete();//elimina di "Dettagli"
    void slotSalva();

};

#endif // WIDGET_H
