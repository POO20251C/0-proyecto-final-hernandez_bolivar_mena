#ifndef ARMADURA_H
#define ARMADURA_H

#include <string>
#include <vector>

#include "Efecto.h"

class Armadura {

private:

    std::string name;

    int def_p;
    int vel_n;

    std::vector<Efecto> invulnerable;

    int precio; 

public:

    Armadura(std::string name, int def_p, int vel_n, std::vector<Efecto> inv, int precio);

    // getters
    
    std::string getName() const;
    
    int getDef() const;
    int getVel() const;

    int getPrecio() const;

    //bool esInmuneA(const std::string& efecto) const;

};

#endif
