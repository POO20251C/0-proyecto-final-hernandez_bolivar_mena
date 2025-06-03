#include "Booster_armaduras.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armaduras::Booster_armaduras() {
    nombre = "Booster de Armaduras";
    
    // Inicializar con armaduras usando los métodos estáticos existentes
    armaduras.push_back(*Armadura::mallaLigera());
    armaduras.push_back(*Armadura::capa_basica());
    armaduras.push_back(*Armadura::peto_de_cuero());
    armaduras.push_back(*Armadura::Piel_de_oso());
    armaduras.push_back(*Armadura::Escarcha());
    armaduras.push_back(*Armadura::Hielo());
    armaduras.push_back(*Armadura::Lava());
    armaduras.push_back(*Armadura::Rayo());
    armaduras.push_back(*Armadura::Sombra());
    armaduras.push_back(*Armadura::Transistora());
}

Armadura Booster_armaduras::abrir() {
    std::cout << "Abriendo " << this->nombre << std::endl;

    // Verificar que hay armaduras disponibles
    if (armaduras.empty()) {
        std::cout << "Error: No hay armaduras en el booster!" << std::endl;
        return *Armadura::mallaLigera(); // Retornar armadura por defecto
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int indice = std::rand() % armaduras.size();
    Armadura armadura_obtenida = armaduras[indice];

    std::cout << "Has obtenido: " << armadura_obtenida.getName()
              << " Defensa: " << armadura_obtenida.getDef()
              << ", Velocidad: " << armadura_obtenida.getVel()
              << ", Precio: " << armadura_obtenida.getPrecio() << " de oro.\n";
    return armadura_obtenida;
}
