#include "Booster_armaduras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armaduras::Booster_armaduras() {
    nombre = "Booster de Armaduras";

}

Armadura Booster_armaduras::abrir() {
    std::cout << "Abriendo " << this->nombre << std::endl;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int indice = std::rand() % armaduras.size();
    Armadura armadura_obtenida = armaduras[indice];

    std::cout << "Has obtenido: " << armadura_obtenida.getName()
              << " Defensa: " << armadura_obtenida.getDef()
              << ", Velocidad: " << armadura_obtenida.getVel()
              << ", Precio: " << armadura_obtenida.getPrecio() << " de oro.\n";
    return armadura_obtenida;
}
