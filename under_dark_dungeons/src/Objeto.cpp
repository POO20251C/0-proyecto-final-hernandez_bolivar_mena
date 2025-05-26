#include "Objeto.h"

Objeto::Objeto(std::string name) {
	this->name = name;
}


std::string Objeto::getName() {
	return this->name;
}
