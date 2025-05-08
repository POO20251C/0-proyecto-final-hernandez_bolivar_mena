#include "Habilidad.h"

// Constructor

Habilidad::Habilidad(std::string name, std::string tipo, int mult, int usos) {

	this->name = name;
	this->tipo = tipo;

	this->mult = mult;
	this->usos = usos;
}

// Getters y setter

std::string Habilidad::nameGetter() {
	return this->name;
}

std::string Habilidad::tipoGetter() {
	return this->tipo;
}

int Habilidad::multGetter() {
	return this->mult;
}

void Habilidad::usosSetter(int usos) {
	this->usos = usos;
}

int Habilidad::usosGetter() {
	return this->usos;
}
