#ifndef TIENDA_H
#define TIENDA_H

#include "Arma.h"
#include "Armadura.h"
#include "Booster_armas.h"
#include "Booster_armaduras.h"
#include <vector>
#include <random>
#include <memory>

using namespace std;

class Tienda {
private:
    vector<Arma*> armasOferta;
    vector<Armadura> armadurasOferta;
    unique_ptr<Booster_armas> boosterArmas;
    unique_ptr<Booster_armaduras> boosterArmaduras;
    bool boosterElegido;
    vector<Nivel> niveles;

public:
    Tienda();
    ~Tienda();
    
    void iniciarNiveles(int cantidad);
    bool marcarNivelComoTerminado(int nivel);
    bool puedeEntrar();
    
    void abrirTienda(const vector<Arma*>& todasLasArmas, const vector<Armadura>& todasLasArmaduras);
    void crearOfertas(const vector<Arma*>& todasLasArmas, const vector<Armadura>& todasLasArmaduras);
    void mostrarOfertas() const;
    void elegir();
    void elegirBooster();
    void comprar(int tipo, int cual);
    void aplicarBooster();
};

#endif  // TIENDA_H
