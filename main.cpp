#include <QApplication>
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/esplosivo.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/list.h"
#include "GUI/widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("Qontainer Armi");
    w.setWindowIcon(QIcon(":/Immagini/icon.png"));
    w.setMinimumSize(400,300);
    w.show();

    return a.exec();
}
