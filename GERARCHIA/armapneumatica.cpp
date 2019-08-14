#include "armapneumatica.h"

ArmaPneumatica::ArmaPneumatica(double le,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL,int rof,int fr,int mv,double bl,std::string c,std::string fs,double j,std::string gas):ArmaDaFuoco(le,w,p,d,m,n,img,needL,rof,fr,mv,bl,c,fs),joule(j),gasUsed(gas){}
ArmaPneumatica::~ArmaPneumatica(){}
bool ArmaPneumatica::operator==(const ArmaPneumatica& a) const{
     return ArmaDaFuoco::operator==(a)&&joule==a.joule&&gasUsed==a.gasUsed;
}
bool ArmaPneumatica::operator!=(const ArmaPneumatica& a) const{
     return ArmaDaFuoco::operator!=(a)||joule!=a.joule||gasUsed!=a.gasUsed;
}
double ArmaPneumatica::getJoule() const{
    return joule;
}
std::string ArmaPneumatica::getGasUsed() const{
    return gasUsed;
}
double ArmaPneumatica::getPrice() const {
    /* Si può distinguere tra arma lunga e arma corta (getPrice() classe genitore) solo se considerata
    *   arma propria, considerabile arma propria se potenza>=7.5 joule
    */
   return (joule>=7.5)?ArmaDaFuoco::getPrice():Arma::getPrice();
    
}
std::string ArmaPneumatica::getInfo() const{
    return  ArmaDaFuoco::getInfo()+
            "-Potenza: "+std::to_string(joule)+" joule \n\n"+
            "-Principio di funzionamento: "+gasUsed+"\n\n"
            "-Prezzo "+ std::to_string(getPrice())+" euro \n\n";
}
std::ostream& operator<<(std::ostream& os,const ArmaPneumatica& a){
    return os<<a.getInfo();
}
std::string ArmaPneumatica::getTipo() const {
    return "ArmaPneumatica";
}
