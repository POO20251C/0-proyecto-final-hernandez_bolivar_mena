#ifndef GRUPOJUGADOR_H
#define GRUPOJUGADOR_H

#include <string>
#include <vector>
#include "Heroe.h"
#include "Objeto.h"
#include "Armadura.h"
#include "Arma.h"

using namespace std;

class GrupoJugador {
private:
    string name;
    int dano_t;
    int oro;
    vector<Heroe*> heroes;
    vector<Objeto*> inventario;
    vector<Armadura*> armaduras;
    vector<Arma*> armas;

public:
    GrupoJugador();
    GrupoJugador(string name, int dano_t, int oro);

    string getName();
    int getOro();
    vector<Heroe*> getHeroes();
    vector<Objeto*> getInventario();
    vector<Armadura*> getArmaduras();
    vector<Arma*> getArmas();

    void setHeroes(vector<Heroe*> grupo);
    
    void sumarDano_t(int dano);
    std::string sumarOro(int oro);

    std::string usarItem(int itemIndex, Heroe* heroe);
    std::string equiparArmadura(int armaduraIndex, Heroe* heroe);
    std::string equiparArma(int armaIndex, Heroe* heroe);
};

#endif // GRUPOJUGADOR_H
