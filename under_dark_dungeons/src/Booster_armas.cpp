//
// Created by juanj on 07/05/2025.
//
#include "Booster_armas.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armas::Booster_armas() {
    nombre = "Booster de Armas";


    armas.push_back(Arma("Espada de fuego", "Quemadura", 50));
    armas.push_back(Arma("Hacha de hielo", "Congelación", 45));
    armas.push_back(Arma("Lanza venenosa", "Veneno", 40));
    armas.push_back(Arma("Arco eléctrico", "Parálisis", 35));
}

void Booster_armas::abrir() {
    std::cout << "Abriendo... " << nombre << std::endl;

    static bool seed_inicializada = false;
    if (!seed_inicializada) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seed_inicializada = true;
    }

    int i = std::rand() % armas.size();
    Arma arma_obtenida = armas[i];

    std::cout << "Has obtenido: " << arma_obtenida.getName()
              << " Efecto: " << arma_obtenida.getEfecto()
              << "Ataque: " << arma_obtenida.getAtk() << "\n";
}
