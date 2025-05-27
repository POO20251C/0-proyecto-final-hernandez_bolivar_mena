#include "Tienda.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <random>

using namespace std;

Tienda::Tienda() : boosterElegido(false) {
    iniciarNiveles(8);
}

Tienda::~Tienda() = default;

void Tienda::iniciarNiveles(int cantidad) {
    niveles.clear();
    for (int i = 1; i <= cantidad; i++) {
        niveles.emplace_back(i);
    }
}

bool Tienda::marcarNivelComoTerminado(int nivel) {
    if (nivel < 1 || nivel > (int)niveles.size()) {
        return false;
    }
    niveles[nivel - 1].completado = true;
    return true;
}

bool Tienda::puedeEntrar() {
    return true;
}

void Tienda::abrirTienda(const vector<Arma>& todasLasArmas, const vector<Armadura>& todasLasArmaduras) {
    cout << "\nBienvenido a la Tienda!" << endl;
    crearOfertas(todasLasArmas, todasLasArmaduras);
    mostrarOfertas();
    elegir();
    cout << "\nGracias por visitar la tienda." << endl;
}

void Tienda::crearOfertas(const vector<Arma>& todasLasArmas, const vector<Armadura>& todasLasArmaduras) {
    boosterArmas = Booster_armas();
    boosterArmaduras = Booster_armaduras();
    armasOferta.clear();
    armadurasOferta.clear();

    random_device rd;
    mt19937 g(rd());

    vector<Arma> armasMezcladas = todasLasArmas;
    shuffle(armasMezcladas.begin(), armasMezcladas.end(), g);
    for (size_t i = 0; i < 3 && i < armasMezcladas.size(); ++i) {
        armasOferta.push_back(armasMezcladas[i]);
    }

    vector<Armadura> armadurasMezcladas = todasLasArmaduras;
    shuffle(armadurasMezcladas.begin(), armadurasMezcladas.end(), g);
    for (size_t i = 0; i < 2 && i < armadurasMezcladas.size(); ++i) {
        armadurasOferta.push_back(armadurasMezcladas[i]);
    }
}

void Tienda::mostrarOfertas() const {
    cout << "\nOfertas disponibles:" << endl;
    cout << "Q. Booster de Armas: " << boosterArmas.getNombre() << endl;
    cout << "E. Booster de Armaduras: " << boosterArmaduras.getNombre() << endl;

    for (size_t i = 0; i < armasOferta.size(); ++i) {
        cout << (i + 1) << ". Arma: " << armasOferta[i].getName()
             << " (Atk: " << armasOferta[i].getAtk()
             << ", Des: " << armasOferta[i].getDes()
             << ", Lck: " << armasOferta[i].getLck()
             << ") --> \"" << armasOferta[i].getPrecio() << "\"" << endl;
    }

    if (!armadurasOferta.empty())
        cout << "A. Armadura: " << armadurasOferta[0].getName()
             << " (Def: " << armadurasOferta[0].getDef()
             << ", Vel: " << armadurasOferta[0].getVel()
             << ") --> \"" << armadurasOferta[0].getPrecio() << "\"" << endl;

    if (armadurasOferta.size() > 1)
        cout << "S. Armadura: " << armadurasOferta[1].getName()
             << " (Def: " << armadurasOferta[1].getDef()
             << ", Vel: " << armadurasOferta[1].getVel()
             << ") --> \"" << armadurasOferta[1].getPrecio() << "\"" << endl;

    cout << "0. Salir de la tienda" << endl;
}

void Tienda::elegir() {
    string opcion;
    bool comprado = false;

    do {
        cout << "\nElige una opcion (0 para salir): ";
        cin >> opcion;

        if (opcion.length() != 1) {
            cout << "Entrada no valida." << endl;
            continue;
        }

        char c = tolower(opcion[0]);

        if (c == '0') {
            cout << "Saliendo de la tienda." << endl;
            break;
        } else if (c == 'q' || c == 'e') {
            elegirBooster(c);
            comprado = true;
        } else if (c >= '1' && c <= '3') {
            int indice = c - '1';
            if (indice < (int)armasOferta.size()) {
                comprarArma(indice);
                comprado = true;
            } else {
                cout << "Opcion no valida." << endl;
            }
        } else if (c == 'a' || c == 's') {
            int indice = (c == 'a') ? 0 : 1;
            if (indice < (int)armadurasOferta.size()) {
                comprarArmadura(indice);
                comprado = true;
            } else {
                cout << "Opcion no valida." << endl;
            }
        } else {
            cout << "Opcion no valida." << endl;
        }

        if (comprado) {
            cout << "Compra realizada." << endl;
            break;
        }
    } while (true);
}

void Tienda::elegirBooster(char opcion) {
    if (opcion == 'q') {
        boosterArmas.abrir();
        boosterElegido = true;
    } else if (opcion == 'e') {
        boosterArmaduras.abrir();
        boosterElegido = true;
    } else {
        cout << "Opcion invalida." << endl;
    }

    aplicarBooster();
}

void Tienda::comprarArma(int indice) {
    if (!jugador) {
        cout << "Jugador no asignado." << endl;
        return;
    }
    if (indice >= 0 && indice < (int)armasOferta.size()) {
        int precio = armasOferta[indice].getPrecio();
        if (jugador->getOro() >= precio) {
            jugador->sumarOro(-precio);
            cout << "Compraste: " << armasOferta[indice].getName()
                 << " por --> \"" << precio << "\" de oro." << endl;
            cout << "Oro restante: " << jugador->getOro() << endl;
        } else {
            cout << "No tienes suficiente oro para comprar esa arma." << endl;
        }
    } else {
        cout << "No existe ese objeto." << endl;
    }
}

void Tienda::comprarArmadura(int indice) {
    if (!jugador) {
        cout << "Jugador no asignado." << endl;
        return;
    }
    if (indice >= 0 && indice < (int)armadurasOferta.size()) {
        int precio = armadurasOferta[indice].getPrecio();
        if (jugador->getOro() >= precio) {
            jugador->sumarOro(-precio);
            cout << "Compraste: " << armadurasOferta[indice].getName()
                 << " por --> \"" << precio << "\" de oro." << endl;
            cout << "Oro restante: " << jugador->getOro() << endl;
        } else {
            cout << "No tienes suficiente oro para comprar esa armadura." << endl;
        }
    } else {
        cout << "No existe ese objeto." << endl;
    }
}

void Tienda::aplicarBooster() {
    if (!boosterElegido) {
        cout << "No hay booster seleccionado." << endl;
    }
}
