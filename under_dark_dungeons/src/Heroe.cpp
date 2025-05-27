

#include "Heroe.h"
#include "Armadura.h"
#include "Arma.h"
#include "Habilidad.h"
#include "Efecto.h"

// Constructores

Heroe::Heroe(std::string name, int hp, int atk, int def, int des, int lck, int p,
             std::vector<Habilidad> habilidades,
             std::vector<Efecto> efectos,
             Armadura* armadura_inicial,
             Arma* arma_inicial) 
	:Entidad(name, hp, atk, def, des, lck, p, habilidades, efectos), armadura(armadura_inicial), arma(arma_inicial) {

		this->arma = arma_inicial;
		this->armadura = armadura_inicial;

		this->vivo = true;


    }



Heroe* Heroe::Caballero() {
	return new Heroe("Charles", 120, 80, 100, 40, 30, 0, {}, {}, Armadura::mallaLigera(), Arma::Espada_basica());
}


// Fin constructores

void Heroe::setArma(Arma* arma) {
	this->arma = arma;
}

void Heroe::setArmadura(Armadura* armadura) {
	this->armadura = armadura;
}

//bool Heroe::recibeDanoPor(const std::string& efecto) {

//	return !armadura->esInmuneA(efecto);
//}






// Getters

int Heroe::getHp() {
	return this->hp;	
}

int Heroe::getDef() {
	return this->def + armadura->getDef();
}

int Heroe::getAtk() {
	return this->atk + this->arma->getAtk();
}

int Heroe::getDes() {
	return this->des + this->armadura->getVel();
}

int Heroe::getLck() {
	return this->lck;
}


// setters






