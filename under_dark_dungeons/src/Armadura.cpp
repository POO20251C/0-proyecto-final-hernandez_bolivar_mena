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

Armadura* Armadura::Escarcha() {
    return new Armadura("Armadura de Escarcha", 50, -10, {Efecto::Congelacion()}, 150);
}

Armadura* Armadura::Hielo() {
    return new Armadura("Armadura de Hielo", 45, -5, {Efecto::Congelacion()}, 140);
}

Armadura* Armadura::Lava() {
    return new Armadura("Armadura de Lava", 60, -15, {Efecto::Quemadura()}, 180);
}

Armadura* Armadura::Rayo() {
    return new Armadura("Armadura de Rayo", 55, 0, {Efecto::Paralisis()}, 170);
}

Armadura* Armadura::Sombra() {
    return new Armadura("Armadura Transistora", 40, 5, {Efecto::Paralisis()}, 130);
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
