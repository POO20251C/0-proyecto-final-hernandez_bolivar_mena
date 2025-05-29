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
	return {"Elixir divino pequeño", 50, 30};
}

Objeto Objeto::BayaZidra() {
	return {"Elixir divino mediano", 30, 50};
}

Objeto Objeto::BayaAranja() {
	return {"Gotas de elixir divino", 10, 15};
}

Objeto Objeto::HiperPocion() {
	return {"Escencia de dios caido", 200, 170};
}

Objeto Objeto::MegaPocion() {
	return {"Elixir divino grande", 100, 120};
}
