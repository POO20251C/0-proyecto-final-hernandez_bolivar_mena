#include "Armadura.h"
#include <algorithm>

Armadura::Armadura(std::string name, int def, int vel, std::vector<Efecto> inv, int precio) {
    this->name = name;
    this->def_p = def;
    this->vel_n = vel;
    this->invulnerable = inv;
    this->precio = precio; 
}

Armadura* Armadura::mallaLigera() {
	return new Armadura("Malla ligera", 30, 10, {}, 100);
}

std::string Armadura::getName() {
    return this->name;
}

int Armadura::getDef() {
    return this->def_p;
}

int Armadura::getVel() {
    return this->vel_n;
}

int Armadura::getPrecio() {
    return this->precio;
}
