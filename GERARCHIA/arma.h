#ifndef ARMA_H
#define ARMA_H
#include <string>
#include <iostream>
class Arma{
private:
    double length,weight,price;
    std::string designer,materials,name,image;
    bool needLicense;
public:
    Arma(double=0.0,double=0.0,double=0.0,std::string="",std::string="",std::string="",std::string="",bool=false);
    virtual ~Arma()=0;
    bool operator==(const Arma&) const;
    bool operator!=(const Arma&) const;
    double getLength() const;
    double getWeight() const;
    virtual double getPrice() const;
    void setPrice(double);
    std::string getDesigner() const;
    std::string getMaterials() const;
    std::string getName() const;
    std::string getImg() const;
    void setImg(std::string);
    bool isLicenseNeeded() const;
    virtual std::string getInfo() const;
    virtual std::string getTipo() const;
};
#endif // ARMA_H
