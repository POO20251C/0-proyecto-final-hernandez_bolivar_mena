#include "Grupo_jugador.h"
#include <string>

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
    std::string ans = "Se uso " + inventario[indx]->getName() + " en " + heroe->nameGetter();
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
    return this->derrotado;
}
