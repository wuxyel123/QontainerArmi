#ifndef ESPLOSIVO_H
#define ESPLOSIVO_H
#include "arma.h"

class Esplosivo : public Arma
{
private:
    std::string filling,detonationMechanism;
    double fillingWeight;
public:
    Esplosivo(double=0.0,double=0.0,double=0.0,
              std::string="",std::string="",
              std::string="",std::string="",
              bool=false,std::string="",
              std::string="",double=0.0);
    ~Esplosivo() override;
    bool operator==(const Esplosivo&) const;
    bool operator!=(const Esplosivo&) const;
    std::string getFilling() const;
    std::string getDetonationMechanism() const;
    double getFillingWeight() const;
    std::string getInfo() const override;
    std::string getTipo() const override;
};
std::ostream& operator<<(std::ostream&,const Esplosivo&);

#endif // ESPLOSIVO_H
