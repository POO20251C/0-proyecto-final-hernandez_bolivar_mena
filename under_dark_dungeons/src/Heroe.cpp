#include "Heroe.h"

Heroe::Heroe(std::string name, int hp, int atk, int def, int des, int lck, int p,
             std::vector<Habilidad> habilidades,
             std::vector<Efecto> efectos,
             Armadura armadura_inicial,
             Arma arma_inicial) 
	:Entidad(name, hp, atk, def, des, lck, p, habilidades, efectos), armadura(armadura_inicial), arma(arma_inicial) {

		this->arma = arma_inicial;
		this->armadura = armadura_inicial;

    }

