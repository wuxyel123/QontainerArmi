#include "armaapolvere.h"

ArmaAPolvere::ArmaAPolvere(double le,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL,int rof,int fr,int mv,double bl,std::string c,std::string fs,std::string crt):ArmaDaFuoco(le,w,p,d,m,n,img,needL,rof,fr,mv,bl,c,fs),cartridge(crt){}
ArmaAPolvere::~ArmaAPolvere(){}
bool ArmaAPolvere::operator==(const ArmaAPolvere& a) const{
     return ArmaDaFuoco::operator==(a)&&cartridge==a.cartridge;
}
bool ArmaAPolvere::operator!=(const ArmaAPolvere& a) const{
     return ArmaDaFuoco::operator!=(a)||cartridge!=a.cartridge;
}
std::string ArmaAPolvere::getCartridge() const{
    return cartridge;
}
std::string ArmaAPolvere::getInfo() const{
    return  ArmaDaFuoco::getInfo()+
            "-Munizioni: "+cartridge+"\n\n"+
            "-Prezzo "+ std::to_string(getPrice())+" euro \n\n";
}
std::ostream& operator<<(std::ostream& os,const ArmaAPolvere& a){
    return os<<a.getInfo();
}
std::string ArmaAPolvere::getTipo() const {
    return "ArmaAPolvere";
}
