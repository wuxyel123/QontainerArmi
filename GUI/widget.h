#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "inserimento.h"
#include "ricerca.h"
#include "dettagli.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QPushButton *cerca;
    QPushButton *inserisci;
    QPushButton *visualizza;
    QPushButton *next;
    QPushButton *prev;
    QPushButton *advancedDelete;
    QLabel *img;
    Ricerca *r;
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

};

#endif // WIDGET_H
