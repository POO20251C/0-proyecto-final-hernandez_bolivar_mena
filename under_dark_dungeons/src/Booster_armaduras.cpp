#include "Booster_armaduras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armaduras::Booster_armaduras() {
    nombre = "Booster de Armaduras";

    armaduras.push_back(Armadura("Armadura de Escarcha", 50, -10, {Efecto::Congelacion()}, 150));
    armaduras.push_back(Armadura("Armadura de Lava", 60, -15, {Efecto::Quemadura()}, 180));
    armaduras.push_back(Armadura("Armadura Transistora", 40, 5, {Efecto::Paralisis()}, 130));
    armaduras.push_back(Armadura("Armadura de Rayo", 55, 0, {Efecto::Paralisis()}, 170));
    armaduras.push_back(Armadura("Armadura de Hielo", 45, -5, {Efecto::Congelacion()}, 140));
    armaduras.push_back(Armadura("Armadura de Sombra", 35, 8, {}, 120));
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
