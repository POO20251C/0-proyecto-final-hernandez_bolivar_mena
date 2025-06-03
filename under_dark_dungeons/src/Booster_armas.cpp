#include "Booster_armas.h"
#include "Efecto.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Booster_armas::Booster_armas() {
    nombre = "Booster de Armas";
    
    // Inicializar con armas usando los métodos estáticos existentes
    armas.push_back(*Arma::Espada_basica());
    armas.push_back(*Arma::Baston_basico());
    armas.push_back(*Arma::Daga_basica());
    armas.push_back(*Arma::Palo_desgastado());
    armas.push_back(*Arma::EspadaFuego());
    armas.push_back(*Arma::EspadaHelada());
    armas.push_back(*Arma::LanzaPlasma());
    armas.push_back(*Arma::ArcoElectrico());
    armas.push_back(*Arma::BaculoLuz());
    armas.push_back(*Arma::DagaSombría());
    armas.push_back(*Arma::HachaHielo());
    armas.push_back(*Arma::LanzaVenenosa());
    armas.push_back(*Arma::MartilloTrueno());
}

Arma Booster_armas::abrir() {
    // Verificar que hay armas disponibles
    if (armas.empty()) {
        std::cout << "Error: No hay armas en el booster!" << std::endl;
        return *Arma::Espada_basica(); // Retornar arma por defecto
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));    

    int i = std::rand() % armas.size();
    Arma arma_obtenida = armas[i];

    std::cout << "Has obtenido: " << arma_obtenida.getName()
              << " | Efecto: " << arma_obtenida.getEfecto().getname()
              << " | Ataque: " << arma_obtenida.getAtk()
              << " | Precio: " << arma_obtenida.getPrecio() << "\n";
    return arma_obtenida;
}
