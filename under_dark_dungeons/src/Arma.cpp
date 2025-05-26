#include "Arma.h"
#include "Efecto.h"

// Constructores

Arma::Arma(std::string name, Efecto efecto, int atk, int des, int lck) : name(name), efecto(efecto), atk_p(atk), des_p(des), lck_p(lck) {}

Arma* Arma::Espada_basica() {
	return new Arma("Espada basica", Efecto::Nada(), 15, -2, 0);
}

Arma* Arma::Baston_basico() {
	return new Arma("Baston magico debil", Efecto::Nada(), 5,  0, 5);
}

Arma* Arma::Daga_basica() {
	return new Arma("Daga de iniciacion", Efecto::Nada(), 10, 10, 5);
}

Arma* Arma::Palo_desgastado() {
	return new Arma("Palo desgastado", Efecto::Nada(), 7, 1, 1);
}


// Getters
 
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
	return this->des_p;
}

int Arma::getLck() const {
	return this->lck_p;
}
