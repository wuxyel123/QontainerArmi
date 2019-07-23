#ifndef ARMAPNEUMATICA_H
#define ARMAPNEUMATICA_H
#include "armadafuoco.h"

class ArmaPneumatica : public ArmaDaFuoco
{
private:
    double joule;
    std::string gasUsed;
public:
    ArmaPneumatica(double=0.0,double=0.0,double=0.0,std::string="",std::string="",std::string="",std::string="",bool=false,int=0,int=0,int=0,double=0.0,std::string="",std::string="",double=0.0,std::string="");
    ~ArmaPneumatica() override;
    bool operator==(const ArmaPneumatica&) const;
    bool operator!=(const ArmaPneumatica&) const;
    double getJoule() const;
    std::string getGasUsed() const;
    double getPrice() const override;
    std::string getInfo() const override;
};
std::ostream& operator<<(std::ostream&,const ArmaPneumatica&);

#endif // ARMAPNEUMATICA_H
