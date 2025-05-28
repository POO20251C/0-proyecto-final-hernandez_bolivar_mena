#ifndef GRUPOENEMIGO_H
#define GRUPOENEMIGO_H

#include "Entidad.h"
#include <vector>

class GrupoEnemigo {

	private:

		std::vector<Entidad*> enemigos;

	public:
		
		// Constructores

		GrupoEnemigo(std::vector<Entidad*> enemigos);
		static GrupoEnemigo* genGrupoEnemigo(int nivel);

		// Getters
		
		std::vector<Entidad*> getEnemigos();
		int getOro();
		bool getVivios();


		// Setters
		


};

#endif
