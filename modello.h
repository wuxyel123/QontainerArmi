#ifndef MODELLO_H
#define MODELLO_H
#include <GERARCHIA/arma.h>
#include "GERARCHIA/armaapolvere.h"
#include "GERARCHIA/armabianca.h"
#include "GERARCHIA/armapneumatica.h"
#include "GERARCHIA/esplosivo.h"
#include "GERARCHIA/list.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include "nofilefoundexception.h"
using std::cerr;
using std::endl;

//espone i metodi Qontainer<Arma*>
class Modello
{
private:
    List<Arma*>* lista;
    List<Arma*>* srcRes;
    std::string path;

public:
    Modello(std::string ="../QontainerArmi/dati.xml");
    ~Modello();
    //Metodi per list
    void push_end(Arma*);
    List<Arma*>::iterator begin();
    List<Arma*>::iterator end();
    List<Arma*>::constiterator cbegin() const;
    List<Arma*>::constiterator cend() const;
    unsigned int getSize()const;
    bool isEmpty() const;
    void erase(List<Arma*>::iterator);
    void clear();
    void save() const;
    void load();

    //Metodi per srcRes
    List<Arma*>::constiterator res_cbegin() const;
    List<Arma*>::constiterator res_cend() const;
    unsigned int res_getSize()const;
    bool res_isEmpty() const;
    void res_clear();

};

#endif // MODELLO_H
