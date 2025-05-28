#include "Objeto.h"

Objeto::Objeto(std::string name, int vida_proporcionada, int precio) {
	this->name = name;
	this->vida_proporcionada = vida_proporcionada;
	this->precio = precio;
}


std::string Objeto::getName() {
	return this->name;
}

int Objeto::getVida_proporcionada() {
	return this->vida_proporcionada;
}

int Objeto::getPrecio() {
	return this->precio;
}

