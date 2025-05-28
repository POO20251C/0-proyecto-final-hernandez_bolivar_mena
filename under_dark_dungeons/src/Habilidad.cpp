#include "Habilidad.h"

#include "Efecto.h"

// Constructor

Habilidad::Habilidad(std::string name, Efecto efecto, int mult):
	name(name), efecto(efecto), mult(mult) {

}

// Getters y setters

std::string Habilidad::nameGetter() {
	return this->name;
}

Efecto Habilidad::efectoGetter() {
	return this->efecto;
}

int Habilidad::multGetter() const {
	return this->mult;
}

Habilidad Habilidad::HitoHitoNoMi() {
	return {"Nada",{Efecto::Nada()},1};
}

Habilidad Habilidad::GoroGoroNoMi() {
	return {"Electrificacion",{Efecto::Paralisis()},2};
}

Habilidad Habilidad::MeraMeraNoMi() {
	return {"Calcinacion", {Efecto::Quemadura()},3 };
}

Habilidad Habilidad::DokuDokuNoMi() {
	return {"Toxicidad", {Efecto::Veneno()},4};
}

Habilidad Habilidad::OpeOpeNoMi() {
	return {"Escama Roja Fluyente", {Efecto::Sangrado()},2};
}

class Habilidad Habilidad::HieHieNoMi() {
	return {"Ice Saber", {Efecto::Congelacion()},2};
}
