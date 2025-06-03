#ifndef GRUPOJUGADOR_H
#define GRUPOJUGADOR_H

#include <string>
#include <vector>
#include "Heroe.h"
#include "Objeto.h"
#include "Armadura.h"
#include "Arma.h"

using namespace std;

class GrupoJugador {
private:
    string name;
    int dano_t;
    int oro;
    vector<Heroe*> heroes;
    vector<Objeto*> inventario;
    vector<Armadura*> armaduras;
    vector<Arma*> armas;
    bool derrotado = true;

public:

    // Constructor
    GrupoJugador(string name, int dano_t, int oro);

    // getters
    string getName();
    int getOro();
    vector<Heroe*> getHeroes();
    vector<Objeto*> getInventario();
    vector<Armadura*> getArmaduras();
    vector<Arma*> getArmas();
    void setHeroes(vector<Heroe*> grupo);
    bool getDerrota();
    int getTotalDamage();
    string toString();

    // Acciones
    void sumarDano_t(int dano);
    void agregarObjeto(Objeto* objeto);
    void agregarArma(Arma* arma);
    void agregarArmadura(Armadura* armadura);
    void removerObjeto(int index);
    std::string sumarOro(int cantidad);
    std::string sumarOroC(int oro);

    void limpiarEfectosDelGrupo();
    std::string usarItem(int itemIndex, Heroe* heroe);
    std::string equiparArmadura(int armaduraIndex, Heroe* heroe);
    std::string equiparArma(int armaIndex, Heroe* heroe);
    std::string subirDeNivelElEquipo(int nivel);


    void registrarDañoParaTabla(int daño_total);

};

#endif // GRUPOJUGADOR_H
