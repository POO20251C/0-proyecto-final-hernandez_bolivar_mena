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

Habilidad Habilidad::HieHieNoMi() {
	return {"Ice Saber", {Efecto::Congelacion()},2};
}

Habilidad Habilidad::BomuBomuNoMi() {
	return {"Bomba Explosiva", {Efecto::Quemadura()}, 1};
}

Habilidad Habilidad::SunaSunaNoMi() {
	return {"Bomba de Humo", {Efecto::Ceguera()}, 1};
}

Habilidad Habilidad::HoroHoroNoMi() {
	return {"Fantasmas Negativos", {Efecto::Debilidad()}, 1};
}

Habilidad Habilidad::KageKageNoMi() {
	return {"Sombra Asechadora", {Efecto::Desesperacion()}, 1};
}

Habilidad Habilidad::MaguMaguNoMi() {
	return {"Golpe Magma", {Efecto::Quemadura()}, 2};
}

Habilidad Habilidad::NoroNoroNoMi() {
	return {"Rayo Ralentizador", {Efecto::Lentitud()}, 1};
}

Habilidad Habilidad::PikaPikaNoMi() {
	return {"Rafaga de luz", {Efecto::Ceguera()}, 1};
}

Habilidad Habilidad::YamiYamiNoMi() {
	return {"Agujero Negro", {Efecto::Miedo()}, 2};
}
