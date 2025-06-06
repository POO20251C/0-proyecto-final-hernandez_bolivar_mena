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
	
    // ARMADURAS INICIALES
    static Armadura* mallaLigera();
    static Armadura* capa_basica();
    static Armadura* peto_de_cuero();
    static Armadura* Piel_de_oso();


    static Armadura* Escarcha();
    static Armadura* Transistora();
    static Armadura* Lava();
    static Armadura* Rayo();
    static Armadura* Hielo();
    static Armadura* Sombra();



    // Fin constructores

    // getters
    
    std::string getName();
    
    int getDef();
    int getVel();

    int getPrecio();
    std::vector<Efecto> getEfectos();

    //bool esInmuneA(const std::string& efecto) const;

};

#endif
