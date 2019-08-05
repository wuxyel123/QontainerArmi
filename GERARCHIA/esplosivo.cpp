#include "esplosivo.h"

Esplosivo::Esplosivo(double le,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL,std::string fi,std::string dm,double fw):Arma(le,w,p,d,m,n,img,needL),filling(fi),detonationMechanism(dm),fillingWeight(fw){}
Esplosivo::~Esplosivo(){}
bool Esplosivo::operator==(const Esplosivo& a) const{
    return Arma::operator==(a)&&filling==a.filling&&detonationMechanism==a.detonationMechanism&&fillingWeight==a.fillingWeight;
}
bool Esplosivo::operator!=(const Esplosivo& a) const{
    return Arma::operator!=(a)||filling!=a.filling||detonationMechanism!=a.detonationMechanism||fillingWeight!=a.fillingWeight;
}
std::string Esplosivo::getFilling() const{
    return filling;
}
std::string Esplosivo::getDetonationMechanism() const{
    return detonationMechanism;
}
double Esplosivo::getFillingWeight() const{
    return fillingWeight;
}
std::string Esplosivo::getInfo() const{
    return Arma::getInfo()+
    "Carica: "+filling+"\n"+
    "Peso carica: "+std::to_string(fillingWeight)+" g \n"+
    "Spoletta: "+detonationMechanism+"\n"+
    "Prezzo "+ std::to_string(getPrice())+" euro \n";
}
std::ostream& operator<<(std::ostream& os,const Esplosivo& a){
    return os<<a.getInfo();
}
std::string Esplosivo::getTipo() const {
    return "Esplosivo";
}

