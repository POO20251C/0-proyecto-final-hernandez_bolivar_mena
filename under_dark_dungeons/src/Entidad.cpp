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
    int lck = 20 + (nivel * 20);
    int p = 100 + (nivel * 20);
    return new Entidad("Goblin", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarLagarto(int nivel) {
    int hp = 60 + (nivel * 20);
    int atk = 22 + (nivel * 20);
    int def = 10 + (nivel * 20);
    int des = 12 + (nivel * 20);
    int lck = 20 + (nivel * 20);
    int p = 200 + (nivel * 20);
    return new Entidad("Lagarto", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarAraña(int nivel) {
    int hp = 80 + (nivel * 20);
    int atk = 20 + (nivel * 20);
    int def = 15 + (nivel * 20);
    int des = 15 + (nivel * 20);
    int lck = 20 + (nivel * 20);
    int p = 200 + (nivel * 20);
    return new Entidad("Araña", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarOrco(int nivel) {
    int hp = 100 + (nivel * 20);
    int atk = 25 + (nivel * 20);
    int def = 20 + (nivel * 20);
    int des = 28 + (nivel * 20);
    int lck = 20 + (nivel * 20);
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

//MINIBOSSES

Entidad* Entidad::Toxsydra(int nivel) {

	int hp = 80 + (nivel * 20);
	int atk = 30 + (nivel * 20);
	int def = 35 + (nivel * 20);
	int des = 45 + (nivel * 20);
	int lck = 60 + (nivel * 20);
	int p = 400 + (nivel * 20);

	return new Entidad("Toxysdra", hp, atk, def, des, lck, p, {Habilidad::DokuDokuNoMi()}, {} );
}

Entidad* Entidad::Frostbane(int nivel) {

	int hp = 120 + (nivel * 20);
	int atk = 40 + (nivel * 20);
	int def = 20 + (nivel * 20);
	int des = 40 + (nivel * 20);
	int lck = 55 + (nivel * 20);
	int p = 350 + (nivel * 20);

	return new Entidad("Frostbane", hp, atk, def, des, lck, p, {Habilidad::HieHieNoMi()}, {} );

}

Entidad* Entidad::Razorbleed(int nivel) {

	int hp = 130 + (nivel * 20);
	int atk = 15 + (nivel * 20);
	int def = 60 + (nivel * 20);
	int des = 10 + (nivel * 20);
	int lck = 75 + (nivel * 20);
	int p = 300 + (nivel * 20);

	return new Entidad("Razorbleed", hp, atk, def, des, lck, p, {Habilidad::OpeOpeNoMi()}, {} );
}

Entidad* Entidad::Voltstryx(int nivel) {

	int hp = 70 + (nivel * 20);
	int atk = 50 + (nivel * 20);
	int def = 15 + (nivel * 20);
	int des = 50 + (nivel * 20);
	int lck = 65 + (nivel * 20);
	int p = 450 + (nivel * 20);

	return new Entidad("Voltstryx", hp, atk, def, des, lck, p, {Habilidad::GoroGoroNoMi()}, {} );
}


Entidad* Entidad::CianotipoElMounstroCopiador(int nivel) {


	int hp = 110 + (nivel * 20);
	int atk = 45 + (nivel * 20);
	int def = 36 + (nivel * 20);
	int des = 45 + (nivel * 20);
	int lck = 60 + (nivel * 20);
	int p = 200 + (nivel * 20);

	return new Entidad("Cianotipo El Mounstro Copiador", hp, atk, def, des, lck, p, {Habilidad::HitoHitoNoMi()}, {} );
}

Entidad* Entidad::MiguelDavidArroyo(int nivel) {

	int hp = 70 + (nivel * 20);
	int atk = 35 + (nivel * 20);
	int def = 25 + (nivel * 20);
	int des = 65 + (nivel * 20);
	int lck = 72 + (nivel * 20);
	int p = 450 + (nivel * 20);

	return new Entidad("Miguel D. Kuzan", hp, atk, def, des, lck, p, {Habilidad::HieHieNoMi()}, {} );;
}

Entidad* Entidad::JimboElPayasoAsesino(int nivel) {

	int hp = 140 + (nivel * 20);
	int atk = 20 + (nivel * 20);
	int def = 40 + (nivel * 20);
	int des = 10 + (nivel * 20);
	int lck = 55 + (nivel * 20);
	int p = 300 + (nivel * 20);

	return new Entidad("Cianotipo El Mounstro Copiador", hp, atk, def, des, lck, p, {Habilidad::HitoHitoNoMi()}, {} );
}

// BOSSES MAYORES

Entidad* Entidad::AshkarIncandescente() {

	return new Entidad("Ashkar, el Corazón Incandescente", 250, 80, 80, 40, 80, 700, {Habilidad::MeraMeraNoMi()}, {} );
}

Entidad* Entidad::GelumdraSilente() {
	return new Entidad("Gelumdra, Reina del Hielo Silente ", 200, 100,50,75,85,800, {Habilidad::HieHieNoMi()}, {});
}

Entidad *Entidad::VarkhemSangrante() {
	return new Entidad("Varkhem, el Desollado Sangrante ", 350, 90,90,45,85,900, {Habilidad::OpeOpeNoMi()}, {});
}

Entidad* Entidad::VoltumnDevorasínapsis() {
	return new Entidad("Voltumn, el Devorasínapsis ", 150, 100,80,90,90,850, {Habilidad::GoroGoroNoMi()}, {});
}
Entidad* Entidad::SatanasElDiablo() {
	return new Entidad("EL MISMISIMO DIABLO", 400, 100,100,100,90,1000, {Habilidad::MeraMeraNoMi()}, {});
}

Entidad *Entidad::XyrothInfecto() {
	return new Entidad("Xyroth, el Jardín Infecto ", 200, 100,50,85,90,750, {Habilidad::DokuDokuNoMi()}, {});
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






