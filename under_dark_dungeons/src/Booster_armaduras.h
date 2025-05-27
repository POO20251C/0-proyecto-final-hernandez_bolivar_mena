//
// Created by juanj on 07/05/2025.
//

#ifndef BOOSTER_ARMADURAS_H
#define BOOSTER_ARMADURAS_H

#include <string>
#include <vector>
#include "Armadura.h"

class Booster_armaduras {
private:
    std::string nombre;
    std::vector<Armadura> armaduras;

public:
    Booster_armaduras();
    void abrir();
};

#endif //BOOSTER_ARMADURAS_H
