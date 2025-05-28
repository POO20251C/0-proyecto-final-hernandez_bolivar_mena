#include "Entidad.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Efecto.h"
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
    int lck = 10 + (nivel * 7);
    int p = 100 + (nivel * 20);
    return new Entidad("Goblin", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarLagarto(int nivel) {
    int hp = 60 + (nivel * 20);
    int atk = 22 + (nivel * 20);
    int def = 10 + (nivel * 20);
    int des = 12 + (nivel * 20);
    int lck = 6 + (nivel * 7);
    int p = 200 + (nivel * 20);
    return new Entidad("Lagarto", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarAraña(int nivel) {
    int hp = 80 + (nivel * 20);
    int atk = 20 + (nivel * 20);
    int def = 15 + (nivel * 20);
    int des = 15 + (nivel * 20);
    int lck = 10 + (nivel * 7);
    int p = 200 + (nivel * 20);
    return new Entidad("Araña", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarOrco(int nivel) {
    int hp = 100 + (nivel * 20);
    int atk = 25 + (nivel * 20);
    int def = 20 + (nivel * 20);
    int des = 28 + (nivel * 20);
    int lck = 3 + (nivel * 7);
    int p = 400 + (nivel * 20);
    return new Entidad("Orco", hp, atk, def, des, lck, p, {}, {});
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
	
	int trueDef = this->def;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueDef += efectos[i].getdef();
		}
	}

	return trueDef;
}

void Entidad::desSetter(int des) {
	this->des = des;
}

int Entidad::desGetter() {
	int trueDes = this->des;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueDes += efectos[i].getvel();
		}
	}

	return trueDes;
}

void Entidad::lckSetter(int lck) {
	this->lck = lck;	
}

int Entidad::lckGetter() {
	int trueLck = this->lck;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueLck += efectos[i].getlck();
		}
	}

	return trueLck;
}

void Entidad::pSetter(int p) {
	this->p = p;
}

int Entidad::pGetter() {
	return this-> p;
}

bool Entidad::getVivo() {
	bool ans = true;
	if (this->hp <= 0) {
		if (this->hp < 0) {
			this->hp = 0;
		}
		ans = false;
	}
	return ans;
}


std::vector<Habilidad> Entidad::getHabilidades() {
	return this->habilidades;
}

// Funciones generales de identidad


std::string Entidad::recibirAtaque(int dano, Efecto posible_efecto) {

	// def es un porcentaje -> dano - (dano * (def/100))
	// lck es un una probabilidad de que no se aplique el efecto


	srand(time(nullptr));
	std::string ans;
	int dano_total = dano - (this->defGetter() * 0.3);
	if(this->hpGetter() - dano_total <= 0) {
		this->hp = 0;
		ans = this->name + " cayó muerto.\n";
	}
	
	else {

		// RECIBE EL DAÑOOOO

		this->hp -= dano_total;

		int prob = 1 + rand() % 100;
		if (prob > lck) {
			this->efectos.push_back(posible_efecto);
			ans  = this->name + " recibio " +  posible_efecto.getname();
		}
	}

	return ans;

}

std::string Entidad::aplicarEfecto() {

	int dano_total = 0;
	std::string ans;

	for (Efecto e : this->efectos) {
		
		dano_total += e.gethp();
		ans = this->name + " recibio " + std::to_string(e.gethp()) + " por "  + e.getname() + "\n";

		if (this->hpGetter() + dano_total <= 0) 
		{
			ans += this->name + " murio por " + e.getname() + "\n";
		}

	}

	return ans;

}




// ESTA FUNCION ES PARA HEROE NO PARA ENTIDAD
//
// QUIEN HIZO ESTO AQUI??
//
// AAAAH NO, Los minibosses y los bosses tambien usan habilidades MLP.

std::string Entidad::mostrarHabilidades() {

	std::string ans = "";

	for (int i = 0; i < this->habilidades.size(); i++) {
		ans += std::to_string(i+1) + ". " + habilidades[i].nameGetter() + "\n"; 
	}

	return ans;
}



