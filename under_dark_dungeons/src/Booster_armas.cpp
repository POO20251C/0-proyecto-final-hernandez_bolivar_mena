#include "Booster_armas.h"
#include "Efecto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armas::Booster_armas() {
    nombre = "Booster de Armas";

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
