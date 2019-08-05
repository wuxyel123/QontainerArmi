#ifndef ARMABIANCA_H
#define ARMABIANCA_H
#include "arma.h"
class ArmaBianca : public Arma
{
private:
    double bladeLength;
    std::string hiltType,bladeType;
public:
    ArmaBianca(double=0.0,double=0.0,double=0.0,std::string="",std::string="",std::string="",std::string="",bool=false,double=0.0,std::string="",std::string="");
    ~ArmaBianca() override;
    bool operator==(const ArmaBianca&) const;
    bool operator!=(const ArmaBianca&) const;
    double getBladeLength() const;
    std::string getHiltType() const;
    std::string getBladeType() const;
    double getPrice() const override;
    std::string getInfo() const override;
    std::string getTipo() const override;
};
std::ostream& operator<<(std::ostream&,const ArmaBianca&); 

#endif // ARMABIANCA_H
