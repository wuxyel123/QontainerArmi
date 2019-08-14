#ifndef DETTAGLI_H
#define DETTAGLI_H

#include <QDialog>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDoubleSpinBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>
#include <QMessageBox>
#include "GERARCHIA/list.h"
#include "GERARCHIA/arma.h"
#include "imageutility.h"

class Dettagli : public QDialog
{
    Q_OBJECT
public:
    explicit Dettagli(QWidget *parent = nullptr);
    QPushButton *getSalva()const;
    QPushButton *getElimina()const;
    std::string getImg()const;
    double getPrice()const;
    void layoutModificaVisible(bool);
    void update_values(std::string,std::string);

private:
    QTextEdit* info;
    QLabel* img;
    QLabel* lPrice;
    QLabel* lImg;
    QDoubleSpinBox *price;
    QPushButton* btnImg;
    QPushButton *elimina;
    QPushButton *modifica;
    QPushButton *salva;
    QVBoxLayout *form;
    QHBoxLayout* layoutDettagli;
    QHBoxLayout* buttons;
    QGridLayout* lModifica;
    imageUtility *imgUti;
    std::string imageRawData;

signals:

private slots:
    void slotModifica();
    void slotChooseImage();
};

#endif // DETTAGLI_H
