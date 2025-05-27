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

	this->vivo = true;
}

// Enemigos

Entidad* Entidad::generarGoblin(int nivel) {
    int hp = 40 + (nivel * 20);
    int atk = 15 + (nivel * 20);
    int def = 5 + (nivel * 20);
    int des = 20 + (nivel * 20);
    int lck = 10 + (nivel * 20);
    int p = 100 + (nivel * 20);
    return new Entidad("Goblin", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarLagarto(int nivel) {
    int hp = 60 + (nivel * 20);
    int atk = 22 + (nivel * 20);
    int def = 10 + (nivel * 20);
    int des = 12 + (nivel * 20);
    int lck = 6 + (nivel * 20);
    int p = 200 + (nivel * 20);
    return new Entidad("Lagarto", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarAraña(int nivel) {
    int hp = 80 + (nivel * 20);
    int atk = 20 + (nivel * 20);
    int def = 15 + (nivel * 20);
    int des = 15 + (nivel * 20);
    int lck = 10 + (nivel * 20);
    int p = 200 + (nivel * 20);
    return new Entidad("Araña", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarOrco(int nivel) {
    int hp = 100 + (nivel * 20);
    int atk = 25 + (nivel * 20);
    int def = 20 + (nivel * 20);
    int des = 28 + (nivel * 20);
    int lck = 3 + (nivel * 20);
    int p = 400 + (nivel * 20);
    return new Entidad("Goblin", hp, atk, def, des, lck, p, {}, {});
}

std::vector<Entidad*> Entidad::Goblings(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarGoblin(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Lagartos(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarLagarto(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Araña_gigantes(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarAraña(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Orcos(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarOrco(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

// BOSSES



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






