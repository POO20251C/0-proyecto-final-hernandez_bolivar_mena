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

Objeto Objeto::Pocion() {
	return {"Pocion", 50, 30};
}

Objeto Objeto::BayaZidra() {
	return {"Baya Zidra", 30, 50};
}

Objeto Objeto::BayaAranja() {
	return {"Baya Aranja", 10, 15};
}

Objeto Objeto::HiperPocion() {
	return {"Hiper Pocion", 200, 170};
}

Objeto Objeto::MegaPocion() {
	return {"Mega Pocion", 100, 120};
}