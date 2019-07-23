#ifndef DETTAGLI_H
#define DETTAGLI_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QFileDialog>
#include <QFileInfo>
#include <QBuffer>
#include <QMessageBox>

class Dettagli : public QDialog
{
    Q_OBJECT
public:
    explicit Dettagli(QString,QWidget *parent = nullptr);

private:
    QTextEdit* info;
    QLabel* img;
    QPushButton *elimina;
    QPushButton *modifica;
    QVBoxLayout *form;
    QHBoxLayout* layoutDettagli;
    QHBoxLayout* buttons;
    QString pos;
signals:

public slots:
    void slotDelete();
    void slotModifica()const;
};

#endif // DETTAGLI_H
