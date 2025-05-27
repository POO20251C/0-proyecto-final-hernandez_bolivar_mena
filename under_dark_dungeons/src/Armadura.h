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
	

    // Constructores 

    Armadura(std::string name, int def_p, int vel_n, std::vector<Efecto> inv, int precio);
	
    static Armadura* mallaLigera();

    // Fin constructores

    // getters
    
    std::string getName();
    
    int getDef();
    int getVel();

    int getPrecio();

    //bool esInmuneA(const std::string& efecto) const;

};

#endif
