#include "armabianca.h"

ArmaBianca::ArmaBianca(double le,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL,double l,std::string h,std::string t):Arma(le,w,p,d,m,n,img,needL),bladeLength(l),hiltType(h),bladeType(t){}
ArmaBianca::~ArmaBianca(){}
bool ArmaBianca::operator==(const ArmaBianca& a) const{
    return Arma::operator==(a)&&bladeLength==a.bladeLength&&hiltType==a.hiltType&&bladeType==a.bladeType;
}
bool ArmaBianca::operator!=(const ArmaBianca& a) const{
    return Arma::operator!=(a)||bladeLength!=a.bladeLength||hiltType!=a.hiltType||bladeType!=a.bladeType;
}
double ArmaBianca::getBladeLength() const{
    return bladeLength;
}
std::string ArmaBianca::getHiltType() const{
    return hiltType;
}
std::string ArmaBianca::getBladeType() const{
    return bladeType;
}
double ArmaBianca::getPrice() const{
    //virtual, ritorna il prezzo base se la lama è meno lunga di 15cm altrimenti aumento del 20%
    return bladeLength>15?Arma::getPrice()*1.2:Arma::getPrice();
}
std::string ArmaBianca::getInfo() const{//virtual 
    return  Arma::getInfo()+
            "-Lunghezza lama: "+std::to_string(bladeLength)+" cm \n\n"+
            "-Tipo impugnatura: "+hiltType+"\n\n"+
            "-Tipo lama: "+bladeType+"\n\n"+
            "-Prezzo "+ std::to_string(getPrice())+" euro \n\n";
}
std::ostream& operator<<(std::ostream& os,const ArmaBianca& a){
    return os<<a.getInfo();
}
std::string ArmaBianca::getTipo() const {
    return "ArmaBianca";
}
