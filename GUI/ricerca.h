#ifndef RICERCA_H
#define RICERCA_H

#include <QDialog>
#include "layoutricercaelimina.h"

class Ricerca : public QDialog
{
    Q_OBJECT
private:
    layoutRicercaElimina *ric;
    QVBoxLayout* form;
public:
    explicit Ricerca(QWidget *parent = nullptr);
};


#endif // RICERCA_H
