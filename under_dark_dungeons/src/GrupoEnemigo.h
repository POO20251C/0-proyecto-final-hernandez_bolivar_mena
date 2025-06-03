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
		static GrupoEnemigo* retornarMinibossRandom(int nivel);
		static GrupoEnemigo* retornarBossRandom();
		// Getters
		
		std::vector<Entidad*> getEnemigos();
		int getOro();
		bool getVivios();


		// Setters
		


};

#endif
