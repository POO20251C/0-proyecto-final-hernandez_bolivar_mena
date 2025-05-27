#include "Booster_armaduras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armaduras::Booster_armaduras() {
    nombre = "Booster de Armaduras";

    armaduras.push_back(Armadura("Armadura de Escarcha", 50, -10, {Efecto::Congelacion()}, 150));
    armaduras.push_back(Armadura("Armadura de Lava", 60, -15, {Efecto::Quemadura()}, 180));
    armaduras.push_back(Armadura("Armadura Transistora", 40, 5, {Efecto::Paralisis()}, 130));
    armaduras.push_back(Armadura("Malla ligera", 30, 10, {}, 100));
    armaduras.push_back(Armadura("Armadura de Rayo", 55, 0, {Efecto::Electrocucion()}, 170));
    armaduras.push_back(Armadura("Armadura de Hielo", 45, -5, {Efecto::Congelacion()}, 140));
    armaduras.push_back(Armadura("Armadura de Sombra", 35, 8, {Efecto::Invisibilidad()}, 120));
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
              << ", Velocidad: " << armadura_obtenida.getVel()
              << ", Precio: " << armadura_obtenida.getPrecio() << " de oro.\n";
}
