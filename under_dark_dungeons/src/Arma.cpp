#include "Arma.h"
#include "Efecto.h"


Arma::Arma(std::string name, Efecto efecto, int atk, int des, int precio)
    : name(name), efecto(efecto), atk_p(atk), des_p(des), precio(precio) {}

Arma* Arma::Espada_basica() {
    return new Arma("Espada basica", Efecto::Nada(), 15, -2, 100);
}

Arma* Arma::Baston_basico() {
    return new Arma("Baston magico debil", Efecto::Nada(), 5,  0, 80);
}

Arma* Arma::Daga_basica() {
    return new Arma("Daga de iniciacion", Efecto::Nada(), 10, 10, 90);
}

Arma* Arma::Palo_desgastado() {
    return new Arma("Palo desgastado", Efecto::Nada(), 7, 1,  70);
}

Arma *Arma::EspadaFuego() {
    return new Arma("Espada de fuego", Efecto::Quemadura(), 50, 1, 150);
}
Arma* Arma::EspadaHelada() {
    return new Arma("Espada helada", Efecto::Congelacion(), 48, 1,  145);
}

Arma* Arma::LanzaPlasma() {
    return new Arma("Lanza de plasma", Efecto::Paralisis(), 52, 1, 155);
}

Arma* Arma::ArcoElectrico() {
    return new Arma("Arco eléctrico", Efecto::Paralisis(), 35, 1,125);
}

Arma* Arma::BaculoLuz() {
    return new Arma("Báculo de luz", Efecto::Quemadura(), 40, 1,135);

}

Arma* Arma::DagaSombría() {
    return new Arma("Daga sombría", Efecto::Veneno(), 30, 1,110);
}

Arma* Arma::HachaHielo() {
    return new Arma("Hacha de hielo", Efecto::Congelacion(), 45, 1,140);
}
Arma* Arma::LanzaVenenosa() {
    return new  Arma("Lanza venenosa", Efecto::Veneno(), 40, 1,130);
}
class Arma *Arma::MartilloTrueno() {
    return new Arma("Martillo de trueno", Efecto::Paralisis(), 55, 1,160);
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


int Arma::getPrecio() const {
    return precio;
}
