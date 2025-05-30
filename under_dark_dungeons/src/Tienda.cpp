
#include "Tienda.h"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>

// Controlar inicialización de semilla
static bool semilla_inicializada = false;
static std::set<std::string> objetos_comprados;

Tienda::Tienda() {
    // Inicializar semilla una sola vez
    if (!semilla_inicializada) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        semilla_inicializada = true;
    }
    
    inicializarPools();
    booster_arma = new Booster_armas();
    booster_armadura = new Booster_armaduras();
    generarInventarioAleatorio();
}

Tienda::~Tienda() {
    // Limpiar armas disponibles
    for (Arma* arma : armas_disponibles) {
        delete arma;
    }
    
    // Limpiar armaduras disponibles
    for (Armadura* armadura : armaduras_disponibles) {
        delete armadura;
    }
    
    // Limpiar pools
    for (Arma* arma : pool_armas) {
        delete arma;
    }
    
    for (Armadura* armadura : pool_armaduras) {
        delete armadura;
    }
    
    delete booster_arma;
    delete booster_armadura;
}

void Tienda::inicializarPools() {
    try {
        // Inicializar pool de armas
        pool_armas.push_back(Arma::Espada_basica());
        pool_armas.push_back(Arma::Baston_basico());
        pool_armas.push_back(Arma::Daga_basica());
        pool_armas.push_back(Arma::Palo_desgastado());
        pool_armas.push_back(Arma::EspadaFuego());
        pool_armas.push_back(Arma::EspadaHelada());
        pool_armas.push_back(Arma::LanzaPlasma());
        pool_armas.push_back(Arma::ArcoElectrico());
        pool_armas.push_back(Arma::BaculoLuz());
        pool_armas.push_back(Arma::DagaSombría());
        pool_armas.push_back(Arma::HachaHielo());
        pool_armas.push_back(Arma::LanzaVenenosa());
        pool_armas.push_back(Arma::MartilloTrueno());
        
        // Inicializar pool de armaduras
        pool_armaduras.push_back(Armadura::mallaLigera());
        pool_armaduras.push_back(Armadura::Escarcha());
        pool_armaduras.push_back(Armadura::Hielo());
        pool_armaduras.push_back(Armadura::Lava());
        pool_armaduras.push_back(Armadura::Rayo());
        pool_armaduras.push_back(Armadura::Transistora());
        pool_armaduras.push_back(Armadura::Sombra());
        
    } catch (const std::exception& e) {
        std::cout << "Error al inicializar pools de la tienda: " << e.what() << std::endl;
    }
}

void Tienda::generarInventarioAleatorio() {
    // Limpiar inventario anterior
    for (Arma* arma : armas_disponibles) {
        delete arma;
    }
    for (Armadura* armadura : armaduras_disponibles) {
        delete armadura;
    }
    armas_disponibles.clear();
    armaduras_disponibles.clear();
    
    if (pool_armas.empty() || pool_armaduras.empty()) {
        std::cout << "Error: Los pools de items están vacíos." << std::endl;
        return;
    }
    
    // Generar 3 armas aleatorias
    for (int i = 0; i < 3; i++) {
        int indice = std::rand() % pool_armas.size();
        Arma* arma_original = pool_armas[indice];
        if (arma_original) {
            Arma* nueva_arma = new Arma(arma_original->getName(), arma_original->getEfecto(),
                                       arma_original->getAtk(), arma_original->getDes(), 
                                       arma_original->getPrecio());
            armas_disponibles.push_back(nueva_arma);
        }
    }
    
    // Generar 3 armaduras aleatorias
    for (int i = 0; i < 3; i++) {
        int indice = std::rand() % pool_armaduras.size();
        Armadura* armadura_original = pool_armaduras[indice];
        if (armadura_original) {
            Armadura* nueva_armadura = new Armadura(armadura_original->getName(),
                                                   armadura_original->getDef(),
                                                   armadura_original->getVel(),
                                                   armadura_original->getEfectos(),
                                                   armadura_original->getPrecio());
            armaduras_disponibles.push_back(nueva_armadura);
        }
    }
}

void Tienda::menuPrincipal(GrupoJugador* grupo) {
    int opcion;
    do {
        std::cout << "\nOro disponible: " << grupo->getOro() << "\n";
        std::cout << "\n================================\n";
        std::cout << "         TIENDA AVENTURERA      \n";
        std::cout << "================================\n";
        std::cout << "1. Armas\n";
        std::cout << "2. Armaduras\n";
        std::cout << "3. Objetos de curación\n";
        std::cout << "4. Boosters\n";
        std::cout << "0. Salir de la tienda\n";
        std::cout << "================================\n";
        std::cout << "Selecciona una opción: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                menuArmas(grupo);
                break;
            case 2:
                menuArmaduras(grupo);
                break;
            case 3:
                menuObjetos(grupo);
                break;
            case 4:
                menuBoosters(grupo);
                break;
            case 0:
                std::cout << "¡Gracias por visitar la tienda!\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    } while(opcion != 0);
}

void Tienda::menuArmas(GrupoJugador* grupo) {
    int opcion;
    do {
        std::cout << "\nOro disponible: " << grupo->getOro() << "\n";
        std::cout << "\n=== ARMAS DISPONIBLES ===\n";
        for(size_t i = 0; i < armas_disponibles.size(); i++) {
            std::cout << i + 1 << ". " << armas_disponibles[i]->getName() 
                      << " - ATK: " << armas_disponibles[i]->getAtk()
                      << " - DES: " << armas_disponibles[i]->getDes()
                      << " - Precio: " << armas_disponibles[i]->getPrecio() << " oro\n";
        }
        std::cout << "0. Volver al menú principal\n";
        std::cout << "Selecciona un arma (0 para volver): ";
        std::cin >> opcion;
        
        if(opcion > 0 && opcion <= (int)armas_disponibles.size()) {
            comprarArma(opcion - 1, grupo);
        } else if(opcion != 0) {
            std::cout << "Opción inválida.\n";
        }
    } while(opcion != 0);
}

void Tienda::menuArmaduras(GrupoJugador* grupo) {
    int opcion;
    do {
        std::cout << "\nOro disponible: " << grupo->getOro() << "\n";
        std::cout << "\n=== ARMADURAS DISPONIBLES ===\n";
        for(size_t i = 0; i < armaduras_disponibles.size(); i++) {
            std::cout << i + 1 << ". " << armaduras_disponibles[i]->getName() 
                      << " - DEF: " << armaduras_disponibles[i]->getDef()
                      << " - VEL: " << armaduras_disponibles[i]->getVel()
                      << " - Precio: " << armaduras_disponibles[i]->getPrecio() << " oro\n";
        }
        std::cout << "0. Volver al menú principal\n";
        std::cout << "Selecciona una armadura (0 para volver): ";
        std::cin >> opcion;
        
        if(opcion > 0 && opcion <= (int)armaduras_disponibles.size()) {
            comprarArmadura(opcion - 1, grupo);
        } else if(opcion != 0) {
            std::cout << "Opción inválida.\n";
        }
    } while(opcion != 0);
}

void Tienda::menuObjetos(GrupoJugador* grupo) {
    int opcion;
    do {
        std::cout << "\nOro disponible: " << grupo->getOro() << "\n";
        std::cout << "\n=== OBJETOS DE CURACIÓN ===\n";
        
        // Crear objetos para mostrar información correcta
        std::vector<Objeto> objetos_display = {
            Objeto::Pocion(), 
            Objeto::BayaZidra(), 
            Objeto::BayaAranja(), 
            Objeto::HiperPocion(), 
            Objeto::MegaPocion()
        };
        
        for(size_t i = 0; i < objetos_display.size(); i++) {
            std::cout << i + 1 << ". " << objetos_display[i].getName() 
                      << " - Vida: +" << objetos_display[i].getVida_proporcionada()
                      << " - Precio: " << objetos_display[i].getPrecio() << " oro\n";
        }
        
        std::cout << "0. Volver al menú principal\n";
        std::cout << "Selecciona un objeto (0 para volver): ";
        std::cin >> opcion;
        
        if(opcion > 0 && opcion <= 5) {
            comprarObjeto(opcion - 1, grupo);
        } else if(opcion != 0) {
            std::cout << "Opción inválida.\n";
        }
    } while(opcion != 0);
}

void Tienda::menuBoosters(GrupoJugador* grupo) {
    int opcion;
    do {
        std::cout << "\nOro disponible: " << grupo->getOro() << "\n";
        std::cout << "\n=== BOOSTERS ===\n";
        std::cout << "1. Booster de Armas - Precio: 200 oro\n";
        std::cout << "2. Booster de Armaduras - Precio: 250 oro\n";
        std::cout << "0. Volver al menú principal\n";
        std::cout << "Selecciona un booster (0 para volver): ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                comprarBoosterArma(grupo);
                break;
            case 2:
                comprarBoosterArmadura(grupo);
                break;
            case 0:
                break;
            default:
                std::cout << "Opción inválida.\n";
                break;
        }
    } while(opcion != 0);
}

bool Tienda::comprarArma(int indice, GrupoJugador* grupo) {
    if(indice < 0 || indice >= (int)armas_disponibles.size()) {
        std::cout << "Selección inválida.\n";
        return false;
    }
    
    int precio = armas_disponibles[indice]->getPrecio();
    if(grupo->getOro() < precio) {
        std::cout << "No tienes suficiente oro.\n";
        return false;
    }
    
    grupo->sumarOro(-precio);
    grupo->agregarArma(new Arma(*armas_disponibles[indice]));
    
    std::cout << "¡Has comprado " << armas_disponibles[indice]->getName() << "!\n";
    return true;
}

bool Tienda::comprarArmadura(int indice, GrupoJugador* grupo) {
    if(indice < 0 || indice >= (int)armaduras_disponibles.size()) {
        std::cout << "Selección inválida.\n";
        return false;
    }
    
    int precio = armaduras_disponibles[indice]->getPrecio();
    if(grupo->getOro() < precio) {
        std::cout << "No tienes suficiente oro.\n";
        return false;
    }
    
    grupo->sumarOro(-precio);
    grupo->agregarArmadura(new Armadura(*armaduras_disponibles[indice]));
    
    std::cout << "¡Has comprado " << armaduras_disponibles[indice]->getName() << "!\n";
    return true;
}

bool Tienda::comprarObjeto(int indice, GrupoJugador* grupo) {
    std::vector<Objeto> objetos_disponibles = {
        Objeto::Pocion(), 
        Objeto::BayaZidra(), 
        Objeto::BayaAranja(), 
        Objeto::HiperPocion(), 
        Objeto::MegaPocion()
    };
    
    if(indice < 0 || indice >= (int)objetos_disponibles.size()) {
        std::cout << "Selección inválida.\n";
        return false;
    }
    
    int precio = objetos_disponibles[indice].getPrecio();
    if(grupo->getOro() < precio) {
        std::cout << "No tienes suficiente oro.\n";
        return false;
    }
    
    grupo->sumarOro(-precio);
    grupo->agregarObjeto(new Objeto(objetos_disponibles[indice]));
    
    std::cout << "¡Has comprado " << objetos_disponibles[indice].getName() << "!\n";
    return true;
}

bool Tienda::comprarBoosterArma(GrupoJugador* grupo) {
    const int precio = 200;
    
    if(grupo->getOro() < precio) {
        std::cout << "No tienes suficiente oro para comprar el Booster de Armas.\n";
        return false;
    }
    
    grupo->sumarOro(-precio);
    Arma arma_obtenida = booster_arma->abrir();
    grupo->agregarArma(new Arma(arma_obtenida));
    
    std::cout << "¡Has obtenido " << arma_obtenida.getName() << " del booster!\n";
    return true;
}

bool Tienda::comprarBoosterArmadura(GrupoJugador* grupo) {
    const int precio = 250;
    
    if(grupo->getOro() < precio) {
        std::cout << "No tienes suficiente oro para comprar el Booster de Armaduras.\n";
        return false;
    }
    
    grupo->sumarOro(-precio);
    Armadura armadura_obtenida = booster_armadura->abrir();
    grupo->agregarArmadura(new Armadura(armadura_obtenida));
    
    std::cout << "¡Has obtenido " << armadura_obtenida.getName() << " del booster!\n";
    return true;
}

void Tienda::refrescarInventario() {
    generarInventarioAleatorio();
    std::cout << "\n¡El inventario de la tienda ha sido actualizado!" << std::endl;
}

// Métodos de visualización adicionales (compatibilidad)
void Tienda::abrirTienda(GrupoJugador* grupo) {
    menuPrincipal(grupo);
}

void Tienda::mostrarTienda(int oro_jugador) {
    // Implementación vacía para compatibilidad
}

void Tienda::mostrarBoosters(int oro_jugador) {
    // Implementación vacía para compatibilidad
}

void Tienda::mostrarArmas(int oro_jugador) {
    // Implementación vacía para compatibilidad
}

void Tienda::mostrarArmaduras(int oro_jugador) {
    // Implementación vacía para compatibilidad
}

void Tienda::mostrarObjetos(int oro_jugador) {
    // Implementación vacía para compatibilidad
}
