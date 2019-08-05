#ifndef ELIMINA_H
#define ELIMINA_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "layoutricercaelimina.h"

class Elimina : public QDialog
{
    Q_OBJECT
private:
    layoutRicercaElimina *del;
    QVBoxLayout* form;
    QHBoxLayout* buttons;
    QPushButton* elimina,*reset;

public:
    explicit Elimina(QWidget *parent = nullptr);
    layoutRicercaElimina* getLCampi();
    QPushButton* getElimina();

signals:

};

#endif // ELIMINA_H
