//
// Created by juanj on 07/05/2025.
//
#include "Booster_armaduras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armaduras::Booster_armaduras() {
    nombre = "Booster de Armaduras";


    Efecto hielo("Hielo");
    Efecto fuego("Fuego");
    Efecto magia("Magia");


    armaduras.push_back(Armadura("Armadura de Escarcha", 50, -10, {hielo}));
    armaduras.push_back(Armadura("Armadura de Lava", 60, -15, {fuego}));
    armaduras.push_back(Armadura("Túnica de Hechicero", 40, 5, {magia}));
    armaduras.push_back(Armadura("Malla ligera", 30, 10, {}));
}

void Booster_armaduras::abrir() {
    std::cout << "Abriendo " << nombre << std::endl;

    if (armaduras.empty()) {
        std::cout << "No hay armaduras en el booster.\n";
        return;
    }

    static bool seed_inicializada = false;
    if (!seed_inicializada) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seed_inicializada = true;
    }

    int indice = std::rand() % armaduras.size();
    Armadura armadura_obtenida = armaduras[indice];

    std::cout << "Has obtenido: " << armadura_obtenida.getName()
              << " Defensa: " << armadura_obtenida.getDef()
              << ", Velocidad: " << armadura_obtenida.getVel() << "\n";
}
