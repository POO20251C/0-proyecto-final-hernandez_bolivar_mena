#ifndef HEROE_H
#define HEROE_H

#include "Entidad.h"

#include <string>
#include <vector>

#include "Arma.h"
#include "Armadura.h"
#include "Habilidad.h"
#include "Entidad.h"
#include "Efecto.h"


class Heroe: public Entidad {

	private:
		Armadura armadura;
		Arma arma;
	
	public:
		
		// Constructor
    		Heroe(std::string name, int hp, int atk, int def, int des, int lck, int p,
          	std::vector<Habilidad> habilidades,
          	std::vector<Efecto> efectos,
          	Armadura armadura_inicial,
          	Arma arma_inicial);

		
		// Setters
		
		void setArma(Arma arma);

		void setArmadura(Armadura armadura);

		// Funciones de Heroe

		std::string mostrarHabilidades();
	

};

#endif
