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

class Dettagli : public QDialog
{
    Q_OBJECT
public:
    explicit Dettagli(QWidget *parent = nullptr);
    QPushButton *getSalva();
    QPushButton *getElimina();
    void layoutModificaVisible(bool)const;

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

signals:

private slots:
    void slotModifica()const;
};

#endif // DETTAGLI_H
