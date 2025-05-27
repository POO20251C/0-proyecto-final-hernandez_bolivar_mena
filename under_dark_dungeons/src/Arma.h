#ifndef ARMA_H
#define ARMA_H 

#include "Efecto.h"
#include <string>

class Arma {

private:
    std::string name;
    Efecto efecto;

    int atk_p;
    int des_p;
    int lck_p;
    int precio; 

public:
    Arma(std::string name, Efecto efecto, int atk, int des, int lck, int precio);

    static Arma* Espada_basica();
    static Arma* Baston_basico();
    static Arma* Daga_basica();
    static Arma* Palo_desgastado();

    std::string getName() const;
    Efecto getEfecto() const;
    int getAtk() const;
    int getDes() const;
    int getLck() const;
    int getPrecio() const;
};

#endif
