#include "Armadura.h"

Armadura::Armadura(std::string name, int def, int vel, std::vector<Efecto> inv) {

	this->name = name;
	this->def_p = def;
	this->vel_n = vel;
	this->invulnerable = inv;

};
