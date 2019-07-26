#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    cerca(new QPushButton("Cerca",this)),
    inserisci(new QPushButton("Inserisci",this)),
    visualizza(new QPushButton("Dettagli",this)),
    next(new QPushButton("Successivo >>",this)),
    prev(new QPushButton("<< Precedente",this)),
    advancedDelete(new QPushButton("Eliminzazione \n Avanzata",this)),
    img(new QLabel("IMMAGINE",this)),
    r(),
    i(),
    d()
{
    QHBoxLayout* mainForm= new QHBoxLayout(this);
    QVBoxLayout* bottoniSx= new QVBoxLayout(this);
    QVBoxLayout* imgContainer= new QVBoxLayout(this);
    QHBoxLayout* imgButtons= new QHBoxLayout(this);


    //SIZE POLICY
    cerca->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    inserisci->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    advancedDelete->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    cerca->setMaximumSize(300,200);
    inserisci->setMaximumSize(300,200);
    advancedDelete->setMaximumSize(300,200);
    prev->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    visualizza->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    next->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    prev->setMaximumHeight(30);
    visualizza->setMaximumHeight(30);
    next->setMaximumHeight(30);
    img->setScaledContents(true);
    //IMG DEFAULT
    QString file=":/Immagini/noData.png";
    QFileInfo relativePath(file);
    if(file!=""){
    QImage im(file);
    QByteArray  array;
    QBuffer b(&array);
    im.save(&b,"JPG");
    img->setPixmap(QPixmap::fromImage(im));
    }

    //AGGIUNTA A LAYOUT
    bottoniSx->setSpacing(25);
    bottoniSx->addWidget(cerca);
    bottoniSx->addWidget(inserisci);
    bottoniSx->addWidget(advancedDelete);

    imgButtons->setSpacing(50);
    imgButtons->addWidget(prev);
    visualizza->setIcon(QIcon(":/Immagini/info.png"));
    imgButtons->addWidget(visualizza);
    imgButtons->addWidget(next);

    imgContainer->addWidget(img);
    imgContainer->addItem(imgButtons);

    mainForm->addItem(bottoniSx);
    mainForm->addItem(imgContainer);

    connect(cerca,SIGNAL(clicked()),this,SLOT(srcClicked()));
    connect(inserisci,SIGNAL(clicked()),this,SLOT(insertClicked()));
    connect(visualizza,SIGNAL(clicked()),this,SLOT(visualizzaClicked()));
    connect(next,SIGNAL(clicked()),this,SLOT(nextClicked()));
    connect(prev,SIGNAL(clicked()),this,SLOT(prevClicked()));
    connect(advancedDelete,SIGNAL(clicked()),this,SLOT(advancedDeleteClicked()));


}
void Widget::srcClicked(){
    r=new Ricerca(this);
    (*r).setWindowTitle("Ricerca-Qontainer Armi");
    (*r).setModal(true);
    (*r).show();
}
void Widget::insertClicked(){
    if(i!=nullptr) delete i;
    i=new Inserimento(this);
    (*i).setWindowTitle("Inserimento-Qontainer Armi");
    (*i).setModal(true);
    (*i).show();

}
void Widget::advancedDeleteClicked(){

}
void Widget::visualizzaClicked(){
    d=new Dettagli("x",this);
    (*d).setWindowTitle("Dettagli-Qontainer Armi");
    (*d).setModal(true);
    (*d).show();
}
void Widget::nextClicked(){

}
void Widget::prevClicked(){}

Widget::~Widget()
{
    delete this;
}
