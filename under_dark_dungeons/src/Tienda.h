#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <string>
#include "Objeto.h"
#include "Booster_armas.h"
#include "Booster_armaduras.h"

using namespace std;

class Tienda {
private:
    vector<Objeto*> objetos;
    Booster_armas booster_armas;
    Booster_armaduras booster_armaduras;

public:
    Tienda();
    void seleccionar();
};

#endif
