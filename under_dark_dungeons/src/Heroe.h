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

class GrupoJugador;

class Heroe: public Entidad {

	private:
		int hp_base;
		int hp_max{};
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
		static Heroe* Mago();
		static Heroe* Ladron();
		static Heroe* Marginado();
		
		// Setters
		
		void setArma(Arma* arma);
		void setArmadura(Armadura* armadura);
		void setHp(int nueva_hp);
		void setHpMax(int max);
		void setHpBase(int base);
		void setVivo(bool estado); 
		void setEfectos(std::vector<Efecto> nuevos_efectos);


		// Getters
		int getHpMax();
		int getHp();
		int getAtk();
		int getDef();
		int getDes();
		Arma* getArma();
		Armadura* getArmadura();


		// Funciones de Heroe
		
		void subirDeNivel(int nivel);
		
		std::string mostrarHabilidades();

		std::string atacar(Entidad* enemigo, GrupoJugador* jugador);
		std::string atacarConHabilidad(Entidad* enemigo, int indx_habilidad, GrupoJugador* jugador);

		std::string recibirAtaque(int dano);

		std::string recibirAtaqueHabilidad(int dano, Efecto posible_efecto);

		std::string aplicarEfecto();



	

};

#endif
