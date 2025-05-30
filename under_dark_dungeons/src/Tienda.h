
#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <string>

#include "Arma.h"
#include "Armadura.h"
#include "Booster_armas.h"
#include "Booster_armaduras.h"
#include "Grupo_jugador.h"
#include "Objeto.h"

class Tienda {
private:
    // Pools de items disponibles
    std::vector<Arma*> pool_armas;
    std::vector<Armadura*> pool_armaduras;
    
    // Inventario actual de la tienda
    std::vector<Arma*> armas_disponibles;
    std::vector<Armadura*> armaduras_disponibles;
    
    // Boosters
    Booster_armas* booster_arma;
    Booster_armaduras* booster_armadura;

public:
    // Constructor y destructor
    Tienda();
    ~Tienda();
    
    // Métodos principales
    void abrirTienda(GrupoJugador* grupo);
    void menuPrincipal(GrupoJugador* grupo);
    void refrescarInventario();
    
    // Métodos de menú específicos
    void menuArmas(GrupoJugador* grupo);
    void menuArmaduras(GrupoJugador* grupo);
    void menuObjetos(GrupoJugador* grupo);
    void menuBoosters(GrupoJugador* grupo);
    
    // Métodos de compra
    bool comprarBoosterArma(GrupoJugador* grupo);
    bool comprarBoosterArmadura(GrupoJugador* grupo);
    bool comprarArma(int indice, GrupoJugador* grupo);
    bool comprarArmadura(int indice, GrupoJugador* grupo);
    bool comprarObjeto(int indice, GrupoJugador* grupo);
    
    // Métodos de visualización
    void mostrarTienda(int oro_jugador);
    void mostrarBoosters(int oro_jugador);
    void mostrarArmas(int oro_jugador);
    void mostrarArmaduras(int oro_jugador);
    void mostrarObjetos(int oro_jugador);

private:
    // Métodos de inicialización
    void inicializarPools();
    void generarInventarioAleatorio();
};

#endif
