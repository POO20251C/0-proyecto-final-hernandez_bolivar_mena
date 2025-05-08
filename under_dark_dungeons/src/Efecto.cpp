#include "Efecto.h"

Efecto::Efecto(std::string name, int hp, int def, int vel, int lck) {

	this->name = name;
	this->mult_hp = hp;
	this->mult_def = def;
	this->mult_vel = vel;
	this->mult_lck = lck;

}
