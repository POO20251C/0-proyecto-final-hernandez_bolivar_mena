//
// Created by juanj on 07/05/2025.
//
#include "Booster_armas.h"
#include "Efecto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armas::Booster_armas() {
    nombre = "Booster de Armas";

    armas.push_back(Arma("Espada de fuego", Efecto::Quemadura(), 50, 1, 1));
    armas.push_back(Arma("Hacha de hielo", Efecto::Congelacion(), 45, 1, 1));
    armas.push_back(Arma("Lanza venenosa", Efecto::Veneno(), 40, 1, 1));
    armas.push_back(Arma("Arco eléctrico", Efecto::Paralisis(), 35, 1, 1));
    armas.push_back(Arma("Martillo de trueno", Efecto::Electrocucion(), 55, 1, 1));
    armas.push_back(Arma("Daga sombría", Efecto::Veneno(), 30, 1, 1));
    armas.push_back(Arma("Báculo de luz", Efecto::Quemadura(), 40, 1, 1));
    armas.push_back(Arma("Espada helada", Efecto::Congelacion(), 48, 1, 1));
    armas.push_back(Arma("Lanza de plasma", Efecto::Paralisis(), 52, 1, 1));

}

void Booster_armas::abrir() {


    static bool seed_inicializada = false;
    if (!seed_inicializada) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seed_inicializada = true;
    }

    int i = std::rand() % armas.size();
    Arma arma_obtenida = armas[i];

    std::cout << "Has obtenido: " << arma_obtenida.getName()
              << " Efecto: " << arma_obtenida.getEfecto().getname()
              << "Ataque: " << arma_obtenida.getAtk() << "\n";
}
