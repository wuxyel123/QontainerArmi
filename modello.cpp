#include "modello.h"
#include "iostream"
#include "QMessageBox"

Modello::Modello(QString p):lista(new List<Arma*>()),srcRes(new List<Arma*>()),path(p){}

QString Modello::getPath(){
    return path;
}
void Modello::setPath(QString s){
    if(s!=nullptr) path=s;
}
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
    //lista->erase((*it),it,it);
    lista->erase(it);

}
void Modello::clear(){
    lista->_clear();
}
void Modello::save()const{
    QSaveFile file(path);
       if(!file.open(QIODevice::WriteOnly)) {
           throw NoFileFoundException("Errore nell'apertura del file");
       }
       QXmlStreamWriter writer(&file);

       writer.setAutoFormatting(true); // Per leggibilità del file XML
       writer.writeStartDocument();    // Scrive le intestazioni XML
       writer.writeComment("NON MODIFICARE QUESTO FILE!!!");

       writer.writeStartElement("root");                                // <root>

       auto it=cbegin();
       while(it!=cptend()) {
           const Arma* toSave = *it;
           const QString tipo=QString::fromStdString(toSave->getTipo());
           writer.writeEmptyElement(tipo);

           //ARMA
           writer.writeAttribute("lenght",QString::fromStdString(std::to_string(toSave->getLength())));
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
       file.commit();
}

void Modello::load(){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) {
        throw NoFileFoundException("Errore nell'apertura del file");
    }
    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement()){
        if(reader.name()=="root"){
            while(reader.readNextStartElement()){
                const QXmlStreamAttributes att= reader.attributes();

                double lenght= att.hasAttribute("lenght")? att.value("lenght").toDouble():0;
                double weight= att.hasAttribute("weight")? att.value("weight").toDouble():0;
                double price= att.hasAttribute("price")? att.value("price").toDouble(): 0;
                std::string designer= att.hasAttribute("designer")? att.value("designer").toString().toStdString(): "";
                std::string materials= att.hasAttribute("materials")? att.value("materials").toString().toStdString(): "";
                std::string name= att.hasAttribute("name")?
                            att.value("name").toString().toStdString(): "";
                std::string img= att.hasAttribute("img")?
                                            att.value("img").toString().toStdString(): "";
                bool licenseNeeded=att.hasAttribute("licenseNeeded")?att.value("licenseNeeded")
                                                                   .toString()=="Yes"? true: false : false;

                Arma* toPush=nullptr;

                if(reader.name()=="ArmaPneumatica"){

                    int rateOfFire= att.hasAttribute("rateOfFire")? att.value("rateOfFire").toInt(): 0;
                    int firingRange= att.hasAttribute("firingRange")? att.value("firingRange").toInt(): 0;
                    int muzzleVelocity= att.hasAttribute("muzzleVelocity")? att.value("muzzleVelocity").toInt(): 0;
                    double barrelLength= att.hasAttribute("barrelLength")? att.value("barrelLength").toDouble(): 0;
                    std::string caliber= att.hasAttribute("caliber")? att.value("caliber").toString().toStdString(): "";
                    std::string feedSystem= att.hasAttribute("feedSystem")? att.value("feedSystem").toString().toStdString(): "";
                    double joule= att.hasAttribute("joule")? att.value("joule").toDouble(): 0;
                    std::string gasUsed= att.hasAttribute("gasUsed")? att.value("gasUsed").toString().toStdString(): "";
                    toPush= new ArmaPneumatica(
                                //arma
                                lenght,weight,price,designer,materials,name,img,licenseNeeded,
                                //arma da fuoco
                                rateOfFire,firingRange,muzzleVelocity,barrelLength,caliber,feedSystem,
                                //arma pneumatica
                                joule,gasUsed
                                );

                }else if(reader.name()=="ArmaAPolvere"){

                    int rateOfFire= att.hasAttribute("rateOfFire")? att.value("rateOfFire").toInt(): 0;
                    int firingRange= att.hasAttribute("firingRange")? att.value("firingRange").toInt(): 0;
                    int muzzleVelocity= att.hasAttribute("muzzleVelocity")? att.value("muzzleVelocity").toInt(): 0;
                    double barrelLength= att.hasAttribute("barrelLength")? att.value("barrelLength").toDouble(): 0;
                    std::string caliber= att.hasAttribute("caliber")? att.value("caliber").toString().toStdString(): "";
                    std::string feedSystem= att.hasAttribute("feedSystem")? att.value("feedSystem").toString().toStdString(): "";
                    std::string cartridge= att.hasAttribute("cartridge")? att.value("cartridge").toString().toStdString(): "";
                    toPush= new ArmaAPolvere(
                                //arma
                                lenght,weight,price,designer,materials,name,img,licenseNeeded,
                                //arma da fuoco
                                rateOfFire,firingRange,muzzleVelocity,barrelLength,caliber,feedSystem,
                                //arma a polvere
                                cartridge
                                );

                }else if(reader.name()=="ArmaBianca"){

                    double bladeLength= att.hasAttribute("bladeLength")? att.value("bladeLength").toDouble(): 0;
                    std::string bladeType= att.hasAttribute("bladeType")? att.value("bladeType").toString().toStdString(): "";
                    std::string hiltType= att.hasAttribute("hiltType")? att.value("hiltType").toString().toStdString(): "";
                    toPush= new ArmaBianca(
                               //arma
                               lenght,weight,price,designer,materials,name,img,licenseNeeded,
                               //arma bianca
                               bladeLength,bladeType,hiltType
                               );
                }else if(reader.name()=="Esplosivo"){

                    std::string filling= att.hasAttribute("filling")? att.value("filling").toString().toStdString(): "";
                    std::string detonationMechanism= att.hasAttribute("detonationMechanism")? att.value("detonationMechanism").toString().toStdString(): "";
                    double fillingWeight= att.hasAttribute("fillingWeight")? att.value("fillingWeight").toDouble(): 0;
                    toPush= new Esplosivo(
                                //arma
                                lenght,weight,price,designer,materials,name,img,licenseNeeded,
                                //esplosivo
                                filling,detonationMechanism,fillingWeight
                                );
                }


                if(toPush!= nullptr){
                    push(toPush);
                }
                else throw std::exception();

                if(!reader.isEndDocument())
                    reader.skipCurrentElement();
            }
        }
    }
    file.close();
}

//Metodi per srcRes
void  Modello::res_push(Arma* a){
    srcRes->pushBack(a);
}
List<Arma*>::iterator Modello::res_begin() const{
    return srcRes->begin();
}
List<Arma*>::iterator Modello::res_end() const{
    return srcRes->end();
}
List<Arma*>::iterator Modello::res_ptend() const{
    return srcRes->ptend();
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









