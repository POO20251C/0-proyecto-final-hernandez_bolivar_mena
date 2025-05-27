#ifndef TIENDA_H
#define TIENDA_H

#include <vector>
#include <memory>
using namespace std;

class Arma;
class Armadura;
class Booster_armas;
class Booster_armaduras;

class Nivel {
public:
    int numero;
    bool completado;
    Nivel(int n) : numero(n), completado(false) {}
};

class Tienda {
private:
    vector<Nivel> niveles;
    vector<unique_ptr<Arma>> armasOferta;
    vector<Armadura> armadurasOferta;
    unique_ptr<Booster_armas> boosterArmas;
    unique_ptr<Booster_armaduras> boosterArmaduras;
    bool boosterElegido;

    void crearOfertas(const vector<shared_ptr<Arma>>&, const vector<Armadura>&);
    void mostrarOfertas() const;
    void elegir();
    void elegirBooster();
    void comprar(int tipo, int cual);
    void aplicarBooster();

public:
    Tienda();
    ~Tienda();

    void iniciarNiveles(int cantidad);
    bool marcarNivelComoTerminado(int nivel);
    bool puedeEntrar();
    void abrirTienda(const vector<shared_ptr<Arma>>&, const vector<Armadura>&);
};

#endif
