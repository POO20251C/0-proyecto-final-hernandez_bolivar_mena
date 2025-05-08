#include "Entidad.h"
#include <string>

#include "Habilidad.h"


// Constructor

Entidad::Entidad(std::string name, int hp, int atk, int def, int des, int lck, int p, std::vector<Habilidad> habilidades, std::vector<Efecto> efectos) {
	this->name = name;

	this->habilidades = habilidades;
	this->efectos = efectos;

	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->des = des;
	this->lck = lck;

	this->p = p;
}

// Getters - Setters

void Entidad::nameSetter(std::string name) {
	this->name = name;
}

std::string Entidad::nameGetter() {
	return this->name;
}


void Entidad::hpSetter(int hp) {
	this->hp = hp;
}

int Entidad::hpGetter() {
	return this->hp;
}

void Entidad::atkSetter(int atk) {
	this->atk = atk;
}

int Entidad::atkGetter() {
	return this->atk;
}

void Entidad::defSetter(int def) {
	this->def = def;
}

int Entidad::defGetter() {
	return this->def;
}

void Entidad::desSetter(int des) {
	this->des = des;
}

int Entidad::desGetter() {
	return this->des;
}

void Entidad::lckSetter(int lck) {
	this->lck = lck;
}

int Entidad::lckGetter() {
	return this->lck;
}

void Entidad::pSetter(int p) {
	this->p = p;
}

int Entidad::pGetter() {
	return this-> p;
}

// Funciones generales de identidad


// ESTA FUNCION ES PARA HEROE NO PARA ENTIDAD
std::string Entidad::mostrarHabilidades() {

	std::string ans = "";

	for (int i = 0; i < this->habilidades.size(); i++) {
		ans += std::to_string(i+1) + ". " + habilidades[i].nameGetter() + "\n"; 
	}

	return ans;
}






