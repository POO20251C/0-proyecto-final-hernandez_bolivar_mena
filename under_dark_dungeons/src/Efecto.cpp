#include "Efecto.h"

Efecto::Efecto(std::string name, int hp, int def, int vel, int lck) {

	this->name = name;
	this->mult_hp = hp;
	this->mult_def = def;
	this->mult_vel = vel;
	this->mult_lck = lck;

}


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

