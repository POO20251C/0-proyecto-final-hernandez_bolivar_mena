#include "Efecto.h"

// Constructores

Efecto::Efecto(std::string name, int hp, int def, int vel, int lck) {

	this->name = name;
	this->mult_hp = hp;
	this->mult_def = def;
	this->mult_vel = vel;
	this->mult_lck = lck;

}


Efecto Efecto::Nada() {
	return Efecto("Nada", 0, 0, 0, 0);
}


Efecto Efecto::Quemadura() {
	return Efecto("Quemadura", -5, -2, -1, 0);
}

Efecto Efecto::Congelacion() {
	return Efecto("Congelacion", -5, 5, -10, -2);
}

Efecto Efecto::Veneno() {
	return Efecto("Veneno", -10, 0, -3, -1);
}

Efecto Efecto::Paralisis() {
	return Efecto("Paralisis", 0, -5, -100, -5);
}

Efecto Efecto::Sangrado() {
  return Efecto("Sangrado", -2, -10, -20, 10);
}

// Getters

std::string Efecto::getname() {
	return this->name;
}

int Efecto::gethp() {
	return this->mult_hp;
}

int Efecto::getdef() {
	return this->mult_def;
}

int Efecto::getvel() {
	return this->mult_vel;
}

int Efecto::getlck() {
	return this->mult_lck;
}

