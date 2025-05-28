#include "Arma.h"
#include "Efecto.h"


Arma::Arma(std::string name, Efecto efecto, int atk, int des, int lck, int precio)
    : name(name), efecto(efecto), atk_p(atk), des_p(des), lck_p(lck), precio(precio) {}

Arma* Arma::Espada_basica() {
    return new Arma("Espada basica", Efecto::Nada(), 5, -2, 0, 100);
}

Arma* Arma::Baston_basico() {
    return new Arma("Baston magico debil", Efecto::Nada(), 5,  0, 5, 80);
}

Arma* Arma::Daga_basica() {
    return new Arma("Daga de iniciacion", Efecto::Nada(), 10, 10, 5, 90);
}

Arma* Arma::Palo_desgastado() {
    return new Arma("Palo desgastado", Efecto::Nada(), 7, 1, 1, 70);
}



std::string Arma::getName() const {
    return name;
}

Efecto Arma::getEfecto() const {
    return efecto;
}

int Arma::getAtk() const {
    return atk_p;
}

int Arma::getDes() const {
    return des_p;
}

int Arma::getLck() const {
    return lck_p;
}

int Arma::getPrecio() const {
    return precio;
}
