#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <string>
#include "Arma.h"
#include "Armadura.h"
#include "Booster_armas.h"
#include "Booster_armaduras.h"
#include "Grupo_jugador.h"

class Tienda {
private:
    struct Nivel {
        int numero;
        bool completado;
        Nivel(int n) : numero(n), completado(false) {}
    };
    std::vector<Nivel> niveles;

    bool boosterElegido;

    Booster_armas boosterArmas;
    Booster_armaduras boosterArmaduras;

    std::vector<Arma> armasOferta;
    std::vector<Armadura> armadurasOferta;

    GrupoJugador* jugador = nullptr;

public:
    Tienda();
    ~Tienda();

    void iniciarNiveles(int cantidad);
    bool marcarNivelComoTerminado(int nivel);
    bool puedeEntrar();

    void abrirTienda(const std::vector<Arma>& todasLasArmas, const std::vector<Armadura>& todasLasArmaduras);

    void crearOfertas(const std::vector<Arma>& todasLasArmas, const std::vector<Armadura>& todasLasArmaduras);
    void mostrarOfertas() const;
    void elegir();

    void elegirBooster(char opcion);
    void comprarArma(int indice);
    void comprarArmadura(int indice);
    void aplicarBooster();

    void setJugador(GrupoJugador* jugadorPtr) { jugador = jugadorPtr; }
};

#endif // TIENDA_H
