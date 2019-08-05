#ifndef ARMADAFUOCO_H
#define ARMADAFUOCO_H
#include "arma.h"
class ArmaDaFuoco : public Arma
{
private:
    int rateOfFire,firingRange,muzzleVelocity;//La velocità alla volata (muzzleVelocity) è in m/s
    double barrelLength;
    std::string caliber,feedSystem;
public:
    ArmaDaFuoco(double=0.0,double=0.0,double=0.0,std::string="",std::string="",std::string="",std::string="",bool=false,int=0,int=0,int=0,double=0.0,std::string="",std::string="");
    ~ArmaDaFuoco()=0;
    bool operator==(const ArmaDaFuoco&) const;
    bool operator!=(const ArmaDaFuoco&) const;
    int getRateOfFire() const;
    int getFiringRange() const;
    int getMuzzleVelocity() const;
    double getBarrelLength() const;
    std::string getCaliber() const;
    std::string getFeedSystem() const;
    double getPrice() const override;
    std::string getInfo() const override; 
    std::string getTipo() const override;;
};
std::ostream& operator<<(std::ostream&,const ArmaDaFuoco&);

#endif // ARMADAFUOCO_H
