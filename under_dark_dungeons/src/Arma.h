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
    int precio; 

public:
    Arma(std::string name, Efecto efecto, int atk, int des, int precio);

    static Arma* Espada_basica();
    static Arma* Baston_basico();
    static Arma* Daga_basica();
    static Arma* Palo_desgastado();
    static Arma* EspadaFuego();
    static Arma* HachaHielo();
    static Arma* LanzaVenenosa();
    static Arma* ArcoElectrico();
    static Arma* MartilloTrueno();
    static Arma* DagaSombría();
    static Arma* BaculoLuz();
    static Arma* EspadaHelada();
    static Arma* LanzaPlasma();





    std::string getName() const;
    Efecto getEfecto() const;
    int getAtk() const;
    int getDes() const;
    int getPrecio() const;
};

#endif
