#include "arma.h"
Arma::Arma(double l,double w,double p,std::string d,std::string m,std::string n,std::string img,bool needL):
length(l),weight(w),price(p),designer(d),materials(m),name(n),image(img),needLicense(needL){}
Arma::~Arma(){}
bool Arma::operator==(const Arma& a) const{
    return length==a.length && weight==a.weight && price==a.price && designer==a.designer
            && materials==a.materials && name==a.name && needLicense==a.needLicense;
}
bool Arma::operator!=(const Arma& a) const{
    return length!=a.length || weight!=a.weight || price!=a.price || designer!=a.designer
            || materials!=a.materials || name!=a.name || needLicense!=a.needLicense;
}
double Arma::getLength() const{
    return length;
}
double Arma::getWeight() const{
    return weight;
}
double Arma::getPrice() const{
    return price;
}
void Arma::setPrice(double p){
    price=p;
}
std::string Arma::getDesigner() const{
    return designer;
}
std::string Arma::getMaterials() const{
    return materials;
}
std::string Arma::getName() const{
    return name;
}
std::string Arma::getImg() const{
    return image;
}
void Arma::setImg(std::string img){
    image=img;
}
bool Arma::isLicenseNeeded() const{
    return needLicense;
}
std::string Arma::getInfo() const{
    return  "-Nome: "+name+"\n\n"+
            "-Designer: "+designer+"\n\n"+
            "-Materiali: "+materials+"\n\n"+
            "-Lunghezza: "+std::to_string(length)+" cm \n\n"+
            "-Peso: "+std::to_string(weight)+" kg \n\n"+
            "-Porto d'armi "+ (needLicense?"":"non ")
            +"necessario \n\n";

}

std::string Arma::getTipo() const {
    return "Arma";
}
