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

    }



/*Heroe Heroe::Caballero() {
	return Heroe("Charles", 120, 80, 100, 40, 30, 0, habilidades, efectos, Armadura("Armadura basica", 1, 1, []) ,Arma::Espada_basica());
}*/


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

void Heroe::setArma(Arma* nueva_arma) {
	this->arma = nueva_arma;
}

void Heroe::setArmadura(Armadura* nueva_armadura) {
	this->armadura = nueva_armadura;
}





