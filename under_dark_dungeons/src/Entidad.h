#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>
#include <vector>
#include "Habilidad.h"
#include "Efecto.h"

class Entidad {

	protected:
		
		std::string name;

		std::vector<Habilidad> habilidades;
		std::vector<Efecto> efectos;

		int hp;
		int atk;
		int def;
		int des;
		int lck;

		int p;
		
	public:

		// Constructor

		Entidad(std::string name, int hp, int atk, int def, int des, int lck, int p, std::vector<Habilidad> habilidades, std::vector<Efecto> efectos);
		
		// Getters - Setters

		void nameSetter(std::string name);
		std::string nameGetter();

		void hpSetter(int hp);
		int hpGetter();

		void atkSetter(int atk);
		int atkGetter();

		void defSetter(int def);
		int defGetter();

		void desSetter(int des);
		int desGetter();

		void lckSetter(int lck);
		int lckGetter();

		void pSetter(int p);
		int pGetter();

		// Funciones de ENTIDAD
		
		// std::string atacar(Heroe* objetivo);
		
		std::string mostrarHabilidades();
		std::string usarHabilidad(int habilidad);


};

#endif
