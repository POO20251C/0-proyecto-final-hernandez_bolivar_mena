#include "Arma.h"

Arma::Arma(std::string name, std::string efecto, int atk) {
     
	     this->name = name;
	     this->efecto = efecto;

	     this->atk_p = atk;

}

std::string Arma::getName() const {
	return name;
}

std::string Arma::getEfecto() const {
	return efecto;
}

int Arma::getAtk() const {
	return atk_p;
}
