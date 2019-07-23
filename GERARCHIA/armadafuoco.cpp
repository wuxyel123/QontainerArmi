#include "armadafuoco.h"

ArmaDaFuoco::ArmaDaFuoco(double le,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL,int rof,int fr,int mv,double bl,std::string c,std::string fs):Arma(le,w,p,d,m,n,img,needL),rateOfFire(rof),firingRange(fr),muzzleVelocity(mv),barrelLength(bl),caliber(c),feedSystem(fs){}
ArmaDaFuoco::~ArmaDaFuoco(){}
bool ArmaDaFuoco::operator==(const ArmaDaFuoco& a) const{
    return Arma::operator==(a)&&rateOfFire==a.rateOfFire&&firingRange==a.firingRange
    &&muzzleVelocity==a.muzzleVelocity&&barrelLength==a.barrelLength&&caliber==a.caliber
    &&feedSystem==a.feedSystem;
}
bool ArmaDaFuoco::operator!=(const ArmaDaFuoco& a) const{
    return Arma::operator!=(a)||rateOfFire!=a.rateOfFire||firingRange!=a.firingRange
    ||muzzleVelocity!=a.muzzleVelocity||barrelLength!=a.barrelLength||caliber!=a.caliber
    ||feedSystem!=a.feedSystem;
}
int ArmaDaFuoco::getRateOfFire() const{
    return rateOfFire;
}
int ArmaDaFuoco::getFiringRange() const{
    return firingRange;
}
int ArmaDaFuoco::getMuzzleVelocity() const{
    return muzzleVelocity;
}
double ArmaDaFuoco::getBarrelLength() const{
    return barrelLength;
}
std::string ArmaDaFuoco::getCaliber() const{
    return caliber;
}
std::string ArmaDaFuoco::getFeedSystem() const{
    return feedSystem;
}
double ArmaDaFuoco::getPrice() const{
/* Se considerata arma lunga sovratassa del 35% 
* un arma da fuoco è considerata arma lunga se la canna ha lunghezza superiore ai 30cm
* o se la lunghezza totale è superiore ai 60 come definito in cee 91/447
*/
return (Arma::getLength()>60||barrelLength>30.0)?Arma::getPrice()*1.35:Arma::getPrice();
}
std::string ArmaDaFuoco::getInfo() const{//virtual 
    return  Arma::getInfo()+
            "Rateo di fuoco: "+std::to_string(rateOfFire)+" RPM \n"+
            "Tiro utile: "+std::to_string(firingRange)+" m \n"+
            "Velocità alla volata: "+std::to_string(muzzleVelocity)+"m/s \n"+
            "Lunghezza canna: "+std::to_string(barrelLength)+" cm \n"+
            "Calibro: "+caliber+"\n"+
            "Alimentazione: "+feedSystem+"\n";
}
std::ostream& operator<<(std::ostream& os,const ArmaDaFuoco& a){
    return os<<a.getInfo();
}
