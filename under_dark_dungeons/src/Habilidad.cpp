#include "Habilidad.h"

#include "Efecto.h"
#include <vector>

// Constructor

Habilidad::Habilidad(std::string name, Efecto efecto, float mult):
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


// SOBRECARGA

// NADA
Habilidad Habilidad::HitoHitoNoMi() {
	return Habilidad("Nada", Efecto::Nada() ,1);
}

// PARALISIS DE TODA LA VIDA
Habilidad Habilidad::GoroGoroNoMi() {
	return Habilidad("Electrificacion",Efecto::Paralisis(),2);
}

// QUEMADURA DE TODA LA VIDA
Habilidad Habilidad::MeraMeraNoMi() {
	return Habilidad("Calcinacion", Efecto::Quemadura(),3 );
}

// VENENO DE TODA LA VIDA
Habilidad Habilidad::DokuDokuNoMi() {
	return Habilidad("Toxicidad", Efecto::Veneno(),4);
}

// SANGRADO DE TODA LA VIDA
Habilidad Habilidad::OpeOpeNoMi() {
	return Habilidad("Escama Roja Fluyente", Efecto::Sangrado(),2);
}

// CONGELACION DE TODA LA VIDA
class Habilidad Habilidad::HieHieNoMi() {
	return Habilidad("Ice Saber", Efecto::Congelacion(),2);
}


// HABILIDADES CABALLERO
Habilidad Habilidad::Corte() {
	return Habilidad("Corte", Efecto::Sangrado(), 1.2);
}

Habilidad Habilidad::Tajada() {
	return Habilidad("Tajada", Efecto::Nada(), 1.2);
}

Habilidad Habilidad::Amputacion() {
	return Habilidad("Amputacion", Efecto::Sangrado(), 1.3);
}

Habilidad Habilidad::Mandoble() {
	return Habilidad("Mandoble", Efecto::Paralisis(), 1.1);
}


// HABILIDADES LADRON

Habilidad Habilidad::Tajo_preciso() {
	return Habilidad("Tajo preciso", Efecto::Sangrado(), 1.1);
}

Habilidad Habilidad::Rodillazo() {
	return Habilidad("Rodillazo", Efecto::Nada(), 1.3);
}

Habilidad Habilidad::Golpe_rapido() {
	return Habilidad("Golpe rapido", Efecto::Nada(), 1.3);
}

Habilidad Habilidad::Desgarro() {
	return Habilidad("Desgarre", Efecto::Sangrado(), 1.1);
}


// HABILIDADES MAGO

Habilidad Habilidad::Bola_de_fuego() {
	return Habilidad("Bola de fuego", Efecto::Quemadura(), 1.9);
}

Habilidad Habilidad::Escarcha() {
	return Habilidad("Escarcha", Efecto::Congelacion(), 2.3);
}

Habilidad Habilidad::Rayo() {
	return Habilidad("Rayo", Efecto::Paralisis(), 2.2);
}

Habilidad Habilidad::Charco_venenoso() {
	return Habilidad("Charco venenoso", Efecto::Veneno(), 1.6);
}


// HABILIDADES MARGINADO

Habilidad Habilidad::Grito_de_furia() {
	return Habilidad("Grito de furia", Efecto::Nada(), 1.4);
}

Habilidad Habilidad::Recuerdos_de_guerra() {
	return Habilidad("Recuerdos de guerra", Efecto::Nada(), 1.45);
}

Habilidad Habilidad::Pisoton() {
	return Habilidad("Pisoton", Efecto::Paralisis(), 1.05);
}

Habilidad Habilidad::Golpetazo() {
	return Habilidad("Golpetazo", Efecto::Nada(), 1.23);
}



std::vector<Habilidad> Habilidad::Habilidades_caballero() {
	std::vector<Habilidad> ans = {
		Habilidad::Corte(),
		Habilidad::Tajada(),
		Habilidad::Amputacion(),
		Habilidad::Mandoble()
	};

	return ans;


}

std::vector<Habilidad> Habilidad::Habilidades_mago() {

	std::vector<Habilidad> ans = {
		Habilidad::Bola_de_fuego(),
		Habilidad::Escarcha(),
		Habilidad::Rayo(),
		Habilidad::Charco_venenoso()
	};

	return ans;

}

std::vector<Habilidad> Habilidad::Habilidades_ladron() {
	
	std::vector<Habilidad> ans = {
		Habilidad::Tajo_preciso(),
		Habilidad::Rodillazo(),
		Habilidad::Golpe_rapido(),
		Habilidad::Desgarro()
	};

	return ans;

}

std::vector<Habilidad> Habilidad::Habilidades_marginado() {

	std::vector<Habilidad> ans = {
		Habilidad::Grito_de_furia(),
		Habilidad::Recuerdos_de_guerra(),
		Habilidad::Pisoton(),
		Habilidad::Golpetazo()
	};

	return ans;

}
