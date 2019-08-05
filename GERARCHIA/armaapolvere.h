#ifndef ARMAAPOLVERE_H
#define ARMAAPOLVERE_H
#include "armadafuoco.h"

class ArmaAPolvere : public ArmaDaFuoco
{
private:
    std::string cartridge;
public:
    ArmaAPolvere(double=0.0,double=0.0,double=0.0,std::string="",std::string="",std::string="",std::string="",bool=false,int=0,int=0,int=0,double=0.0,std::string="",std::string="",std::string="");
    ~ArmaAPolvere() override;
    bool operator==(const ArmaAPolvere&) const;
    bool operator!=(const ArmaAPolvere&) const;
    std::string getCartridge() const;
    std::string getInfo() const override;
    std::string getTipo() const override;
};
std::ostream& operator<<(std::ostream&,const ArmaAPolvere&);

#endif // ARMAAPOLVERE_H
