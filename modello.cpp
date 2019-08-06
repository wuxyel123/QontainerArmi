#include "modello.h"
#include "iostream"
#include "QMessageBox"

Modello::Modello(std::string p):lista(new List<Arma*>()),srcRes(new List<Arma*>()),path(p){}

void  Modello::push(Arma* a){
    lista->pushBack(a);
}
List<Arma*>::iterator Modello::begin(){
    return lista->begin();
}
List<Arma*>::iterator Modello::last(){
    return lista->end();
}
List<Arma*>::iterator Modello::ptend(){
    return lista->ptend();
}
List<Arma*>::constiterator Modello::cbegin() const{
    return lista->cbegin();
}
List<Arma*>::constiterator Modello::clast()const{
    return lista->cend();
}
List<Arma*>::constiterator Modello::cptend() const{
    return lista->cptend();
}
unsigned int Modello::getSize()const{
    return lista->_size();
}
bool Modello::isEmpty() const{
    return lista->empty();
}
void Modello::erase(List<Arma*>::iterator it){
    lista->erase(it);
}
void Modello::clear(){
    lista->_clear();
}
void Modello::save()const{
    /*QSaveFile file(QString::fromStdString(path));
       if(!file.open(QIODevice::WriteOnly)) {
           std::cout<<"Errore nell'apertura del file";
           throw NoFileFoundException("Errore nell'apertura del file");

       }

       QXmlStreamWriter writer(&file);

       writer.setAutoFormatting(true); // Per leggibilità del file XML
       writer.writeStartDocument();    // Scrive le intestazioni XML
       writer.writeComment("NON MODIFICARE QUESTO FILE!!!");

       writer.writeStartElement("root");                                // <root>

       auto it=cbegin();
       while(it!=cend()) {
           const Arma* toSave = *it;
           const QString tipo=QString::fromStdString(toSave->getTipo());
           writer.writeEmptyElement(tipo);

           //ARMA
           writer.writeAttribute("lenght",QString::fromStdString(toSave->getName()));
           writer.writeAttribute("weight",QString::fromStdString(std::to_string(toSave->getWeight())));
           writer.writeAttribute("price",QString::fromStdString(std::to_string(toSave->Arma::getPrice())));
           writer.writeAttribute("designer",QString::fromStdString(toSave->getDesigner()));
           writer.writeAttribute("materials",QString::fromStdString(toSave->getMaterials()));
           writer.writeAttribute("name",QString::fromStdString(toSave->getName()));
           writer.writeAttribute("img",QString::fromStdString(toSave->getImg()));
           writer.writeAttribute("licenseNeeded",toSave->isLicenseNeeded()? "Yes": "No");
           //ARMA PNEUMATICA
           if(tipo=="ArmaPneumatica"){
               const ArmaPneumatica* p= static_cast<const ArmaPneumatica*>(toSave);
               writer.writeAttribute("rateOfFire",QString::fromStdString(std::to_string( p->getRateOfFire())));
               writer.writeAttribute("firingRange",QString::fromStdString(std::to_string( p->getFiringRange())));
               writer.writeAttribute("muzzleVelocity",QString::fromStdString(std::to_string( p->getMuzzleVelocity())));
               writer.writeAttribute("barrelLength",QString::fromStdString(std::to_string( p->getBarrelLength())));
               writer.writeAttribute("caliber",QString::fromStdString(p->getCaliber()));
               writer.writeAttribute("feedSystem",QString::fromStdString(p->getFeedSystem()));

               writer.writeAttribute("joule",QString::fromStdString(std::to_string( p->getJoule())));
               writer.writeAttribute("gasUsed",QString::fromStdString(p->getGasUsed()));

           }else if(tipo=="ArmaAPolvere"){//ARMA A POLVERE
               const ArmaAPolvere* p= static_cast<const ArmaAPolvere*>(toSave);
               writer.writeAttribute("rateOfFire",QString::fromStdString(std::to_string( p->getRateOfFire())));
               writer.writeAttribute("firingRange",QString::fromStdString(std::to_string( p->getFiringRange())));
               writer.writeAttribute("muzzleVelocity",QString::fromStdString(std::to_string( p->getMuzzleVelocity())));
               writer.writeAttribute("barrelLength",QString::fromStdString(std::to_string( p->getBarrelLength())));
               writer.writeAttribute("caliber",QString::fromStdString(p->getCaliber()));
               writer.writeAttribute("feedSystem",QString::fromStdString(p->getFeedSystem()));

               writer.writeAttribute("cartridge",QString::fromStdString(p->getCartridge()));

           }else if(tipo=="ArmaBianca"){//ARMA BIANCA
               const ArmaBianca* p= static_cast<const ArmaBianca*>(toSave);
               writer.writeAttribute("bladeLength",QString::fromStdString(std::to_string( p->getBladeLength())));
               writer.writeAttribute("bladeType",QString::fromStdString(p->getBladeType()));
               writer.writeAttribute("hiltType",QString::fromStdString(p->getHiltType()));

           }else if(tipo=="Esplosivo"){//ESPLOSIVO
               const Esplosivo* p= static_cast<const Esplosivo*>(toSave);
               writer.writeAttribute("filling",QString::fromStdString(p->getFilling()));
               writer.writeAttribute("detonationMechanism",QString::fromStdString(p->getDetonationMechanism()));
               writer.writeAttribute("fillingWeight",QString::fromStdString(std::to_string( p->getFillingWeight())));
           }
           if (writer.hasError()){
               throw std::exception();
           }

           ++it;
       }

       writer.writeEndElement();
       writer.writeEndDocument();
       file.commit();*/
}

void Modello::load(){

}

//Metodi per srcRes
List<Arma*>::constiterator Modello::res_cbegin() const{
    return srcRes->cbegin();
}
List<Arma*>::constiterator Modello::res_cend() const{
    return srcRes->cend();
}
unsigned int Modello::res_getSize()const{
    return srcRes->_size();
}
bool Modello::res_isEmpty() const{
    return srcRes->empty();
}
void Modello::res_clear(){
    srcRes->_clear();
}








