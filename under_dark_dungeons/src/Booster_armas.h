//
// Created by juanj on 07/05/2025.
//
#ifndef BOOSTER_ARMAS_H
#define BOOSTER_ARMAS_H

#include <string>
#include <vector>
#include "Arma.h"

class Booster_armas {
private:
    std::string nombre;
    std::vector<Arma> armas;

public:
    Booster_armas();
    void abrir();
};

#endif //BOOSTER_ARMAS_H
