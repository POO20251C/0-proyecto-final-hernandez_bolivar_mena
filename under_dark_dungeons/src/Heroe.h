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
		int hp_base;	
		Armadura* armadura;
		Arma* arma;

	public:
		
		// Constructores
    		Heroe(std::string name, int hp, int hp_base, int atk, int def, int des, int lck, int p,
          	std::vector<Habilidad> habilidades,
          	std::vector<Efecto> efectos,
          	Armadura* armadura_inicial,
          	Arma* arma_inicial);

		static Heroe* Caballero();
		
		// Setters
		
		void setArma(Arma* arma);
		void setArmadura(Armadura* armadura);
		void setHp(int hp_base, int nivel);


		// Getters
		int getHp();
		int getAtk();
		int getDef();

		// Funciones de Heroe
		
		void subirDeNivel(int nivel);
		
		std::string mostrarHabilidades();

		std::string atacar(Entidad* enemigo, int nivel);

		std::string recibirAtaque(int dano);

		std::string recibirAtaqueHabilidad(int dano, Efecto posible_efecto);

		std::string aplicarEfecto();



	

};

#endif
