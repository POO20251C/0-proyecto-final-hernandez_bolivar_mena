#include "Armadura.h"
#include <algorithm>

Armadura::Armadura(std::string name, int def, int vel, std::vector<Efecto> inv) {

	this->name = name;
	this->def_p = def;
	this->vel_n = vel;
	this->invulnerable = inv;

};


std::string Armadura::getName() {
	return this->name;
}

int Armadura::getDef() {
	return this->def_p;
}

int Armadura::getVel() {
	return this->vel_n;
}

