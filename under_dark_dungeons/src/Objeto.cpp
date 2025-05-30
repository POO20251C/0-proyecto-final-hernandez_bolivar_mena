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

// Ordenados por potencia: de menor a mayor vida proporcionada

Objeto Objeto::BayaAranja() {
	return {"Gotas de elixir divino", 10, 15};
}

Objeto Objeto::BayaZidra() {
	return {"Elixir divino mediano", 30, 50};
}

Objeto Objeto::Pocion() {
	return {"Elixir divino pequeño", 50, 30};
}

Objeto Objeto::MegaPocion() {
	return {"Elixir divino grande", 100, 120};
}

Objeto Objeto::HiperPocion() {
	return {"Esencia de dios caído", 200, 170};
}