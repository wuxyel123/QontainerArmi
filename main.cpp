#include <QApplication>
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/esplosivo.h"
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/list.h"
#include "GUI/widget.h"
#include "modello.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(new Modello());
    w.setWindowTitle("Qontainer Armi");
    w.setWindowIcon(QIcon(":/Immagini/icon.png"));
    w.setMinimumSize(400,300);
    w.show();

    return a.exec();
    /*List<Arma*> l;
    Arma* a1=new Esplosivo(1,1,1,"1","1","1");
    Arma* a2=new ArmaBianca(2,2,2,"2","2","2");
    Arma* a3=new ArmaAPolvere(3,3,3,"3","3","3");
    Arma* a4=new ArmaPneumatica(4,4,4,"4","4","4");
    Arma* a5=new Esplosivo(5,5,5,"5","5","5");
    Arma* a6=new Esplosivo(6,6,6,"6","6","6");
    Arma* a7=new Esplosivo(7,7,7,"7","7","7");
    Arma* a8=new Esplosivo(8,8,8,"8","8","8");
    Arma* a9=new Esplosivo(9,9,9,"9","9","9");
    Arma* a10=new Esplosivo(10,10,10,"10","10","10");
    l.pushBack(a1);
    l.pushBack(a2);
    l.pushBack(a3);
    l.pushBack(a4);
    l.pushBack(a5);
    l.pushBack(a6);
    l.pushBack(a7);
    l.pushBack(a8);
    l.pushBack(a9);
    l.pushBack(a10);
    auto it=l.begin();
    l.erase(it);
     it=l.begin();
    l.erase(it);
    it=l.begin();
   l.erase(it);
   std::cout<<(*it)->getInfo();
    std::cout<<a1->getTipo()<<std::endl;
    std::cout<<a2->getTipo()<<std::endl;
    std::cout<<a3->getTipo()<<std::endl;
    std::cout<<a4->getTipo()<<std::endl;*/

}
