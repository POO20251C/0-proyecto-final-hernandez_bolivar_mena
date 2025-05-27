#include "Booster_armas.h"
#include "Efecto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armas::Booster_armas() {
    nombre = "Booster de Armas";
    
    armas.push_back(Arma("Espada de fuego", Efecto::Quemadura(), 50, 1, 1, 150));
    armas.push_back(Arma("Hacha de hielo", Efecto::Congelacion(), 45, 1, 1, 140));
    armas.push_back(Arma("Lanza venenosa", Efecto::Veneno(), 40, 1, 1, 130));
    armas.push_back(Arma("Arco eléctrico", Efecto::Paralisis(), 35, 1, 1, 125));
    armas.push_back(Arma("Martillo de trueno", Efecto::Paralisis(), 55, 1, 1, 160));
    armas.push_back(Arma("Daga sombría", Efecto::Veneno(), 30, 1, 1, 110));
    armas.push_back(Arma("Báculo de luz", Efecto::Quemadura(), 40, 1, 1, 135));
    armas.push_back(Arma("Espada helada", Efecto::Congelacion(), 48, 1, 1, 145));
    armas.push_back(Arma("Lanza de plasma", Efecto::Paralisis(), 52, 1, 1, 155));
}

Arma Booster_armas::abrir() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));    

    int i = std::rand() % armas.size();
    Arma arma_obtenida = armas[i];

    std::cout << "Has obtenido: " << arma_obtenida.getName()
              << " | Efecto: " << arma_obtenida.getEfecto().getname()
              << " | Ataque: " << arma_obtenida.getAtk()
              << " | Precio: " << arma_obtenida.getPrecio() << "\n";

    return arma_obtenida;
}
