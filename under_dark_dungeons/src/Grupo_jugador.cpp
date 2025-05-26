#include "Grupo_jugador.h"
#include <string>

// Constructor

GrupoJugador::GrupoJugador(std::string name, int dano_t, int oro) {
	this->name = name;
	this->dano_t = dano_t;
	this->oro = oro;
}


// Getters

std::string GrupoJugador::getName() {
	return this->name;
}

int GrupoJugador::getOro() {
	return this->oro;
}

vector<Heroe*> GrupoJugador::getHeroes() {
	return this->heroes;
}

vector<Objeto*> GrupoJugador::getInventario() {
	return this->inventario;
}

vector<Armadura*> GrupoJugador::getArmaduras() {
	return this->armaduras;
}

vector<Arma*> GrupoJugador::getArmas() {
	return this->armas;
}

// Setters
void GrupoJugador::setHeroes(vector<Heroe*> grupo) {
	this->heroes = grupo;
}

void GrupoJugador::sumarDano_t(int dnao) {
	this->dano_t += dnao;
}

std::string  GrupoJugador::sumarOro(int oro) {

	std::string ans = "El grupo gano " + to_string(oro) + " de oro.";
	this->oro += oro;

	return ans;
}


std::string GrupoJugador::usarItem(int indx, Heroe* heroe) 
{
	std::string ans = "Se uso " + inventario[indx]->getName() + " en " + heroe->nameGetter();
	return ans;	
}

std::string GrupoJugador::equiparArma(int indx, Heroe* heroe) 
{
	std::string ans = "Se equipo " + armas[indx]->getName() + " a " + heroe->nameGetter();
	return ans;
}


std::string GrupoJugador::equiparArmadura(int indx, Heroe* heroe) 
{
	std::string ans = "Se equipo " + armaduras[indx]->getName() + " en " + heroe->nameGetter();
	return ans;
}


