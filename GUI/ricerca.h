#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "layoutricercaelimina.h"
#include "GERARCHIA/list.h"
#include <GERARCHIA/arma.h>

class Ricerca : public QDialog
{
    Q_OBJECT
private:
    layoutRicercaElimina *ric;
    QVBoxLayout* form;
    QHBoxLayout* buttons;
    QPushButton* cerca,*reset;


public:
    explicit Ricerca(QWidget *parent = nullptr);
    layoutRicercaElimina* getLCampi();
    QPushButton* getCerca();

signals:

};


#endif // RICERCA_H
