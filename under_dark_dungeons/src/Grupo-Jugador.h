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
    int cantidadInicial;
    int oro;
    vector<Heroe*> heroes;
    vector<Objeto*> inventario;
    vector<Armadura*> armaduras;
    vector<Arma*> armas;

public:
    GrupoJugador();
    GrupoJugador(string name, int cantidadInicial, int oro);

    string getName() const;
    int getOro() const;
    vector<Heroe*> getHeroes() const;
    vector<Objeto*> getInventario() const;
    vector<Armadura*> getArmaduras() const;
    vector<Arma*> getArmas() const;

    void usarItem(int itemIndex, Heroe* heroe);
    void equiparArmadura(int armaduraIndex, Heroe* heroe);
    void equiparArma(int armaIndex, Heroe* heroe);
};

#endif // GRUPOJUGADOR_H
