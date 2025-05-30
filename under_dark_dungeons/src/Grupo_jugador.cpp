#include "Grupo_jugador.h"
#include "Heroe.h"
#include <ios>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

GrupoJugador::GrupoJugador(std::string name, int dano_t, int oro) {
    this->name = name;
    this->dano_t = dano_t;
    this->oro = oro;
}

std::string GrupoJugador::getName() {
    return this->name;
}

int GrupoJugador::getOro() {
    return this->oro;
}

int GrupoJugador::getTotalDamage() {
	return this->dano_t;
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

void GrupoJugador::setHeroes(vector<Heroe*> grupo) {
    this->heroes = grupo;
}

void GrupoJugador::sumarDano_t(int dano) {
    this->dano_t += dano;
}

std::string GrupoJugador::sumarOroC(int oro) {
	
	this->oro += oro;

	return "El grupo gano " + to_string(oro) + " de oro.";

}

std::string GrupoJugador::sumarOro(int cantidad) {
    if (cantidad < 0 && oro + cantidad < 0) {
        return "No tienes suficiente oro.";
    }
    oro += cantidad;
    if (cantidad >= 0) {
        return "El grupo ganó " + std::to_string(cantidad) + " de oro.";
    } else {
        return "Se gastaron " + std::to_string(-cantidad) + " de oro.";
    }
}

std::string GrupoJugador::usarItem(int indx, Heroe* heroe) {
	
	heroe->setHp(heroe->getHp() + inventario[indx]->getVida_proporcionada());
	
    	std::string ans = "Se uso " + inventario[indx]->getName() + " en " + heroe->nameGetter() + "y lo curo " + to_string(inventario[indx]->getVida_proporcionada()) + "\n";
		
	inventario.erase(inventario.begin() + indx);
	
	if (!heroe->getVivo()) {
		heroe->setVivo(true);
		ans += heroe->nameGetter() + " volvio a la vida y puede seguir luchando.\n";
	}

    	return ans;    
}

std::string GrupoJugador::equiparArma(int indx, Heroe* heroe) {
    std::string ans = "Se equipo " + armas[indx]->getName() + " a " + heroe->nameGetter();
    return ans;
}

std::string GrupoJugador::equiparArmadura(int indx, Heroe* heroe) {
    std::string ans = "Se equipo " + armaduras[indx]->getName() + " en " + heroe->nameGetter();
    return ans;
}

bool GrupoJugador::getDerrota() {
	
	vector<Heroe*> heroes_muertos;

	for (Heroe* h : this->heroes ) {
		if (!h->getVivo()) {
			heroes_muertos.push_back(h);
		}
	}

	if ((int) heroes_muertos.size() == (int) this->heroes.size()) {
		this->derrotado = false;
	}
    	
	return this->derrotado;
}


std::string GrupoJugador::subirDeNivelElEquipo(int nivel) {
	
	std::string ans = "Tu equipo se siente mas fuerte";


	for (Heroe* h : heroes) {
		h->subirDeNivel(nivel);
	}

	return ans;

}

void GrupoJugador::registrarDañoParaTabla(int daño_total) {
	this->dano_t += daño_total;
}


void GrupoJugador::agregarObjeto(Objeto* objeto) {
    this->inventario.push_back(objeto);
}

void GrupoJugador::limpiarEfectosDelGrupo() {
	for (Heroe* h: this->heroes) {
		h->setEfectos({});		
	}
}

string GrupoJugador::toString() {
	
	std::ostringstream ans;

	ans << std::left << std::setw(15) << "Nombre"
	<< std::setw(15) << "vida"
	<< std::setw(30) << "Arma"
	<< std::setw(25) << "Armadura" << "\n";

	for (Heroe* h : this->heroes ) {
		
		std::string vida = to_string(h->getHp()) + "/" + to_string(h->getHpMax());

		ans << std::left << std::setw(15) << h->nameGetter()
		<< std::setw(15) << vida
		<< std::setw(30) << h->getArma()->getName()
		<< std::setw(25) << h->getArmadura()->getName() << "\n";

	}

	return ans.str();

}
