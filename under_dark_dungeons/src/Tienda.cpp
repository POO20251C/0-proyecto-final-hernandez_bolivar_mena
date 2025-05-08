//
// Created by juanj on 07/05/2025.
//
#include "Tienda.h"
#include <iostream>

void Tienda::seleccionar() {
    std::cout << "Seleccionando un booster desde la tienda..." << std::endl;

    booster_armas.abrir();
    booster_armaduras.abrir();
}