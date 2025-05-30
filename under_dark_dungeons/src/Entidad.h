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

		bool vivo;
		
	public:

		// Destructor

		virtual ~Entidad() {};

		// Constructores

		Entidad(std::string name, int hp, int atk, int def, int des, int lck, int p, std::vector<Habilidad> habilidades, std::vector<Efecto> efectos);


		// Enemigos_simples
		
		static Entidad* generarGoblin(int nivel);
		static Entidad* generarAraña(int nivel);
		static Entidad* generarOrco(int nivel);
		static Entidad* generarLagarto(int nivel);
			 
		static std::vector<Entidad*> Goblings(int cantidad, int nivel);
		static std::vector<Entidad*> Lagartos(int cantidad, int nivel);
		static std::vector<Entidad*> Araña_gigantes(int cantidad, int nivel);
		static std::vector<Entidad*> Orcos(int cantidad, int nivel);

		// Mini Bosses

		static Entidad* MiguelDavidArroyo(int nivel);
		static Entidad* Frostbane(int nivel);
		static Entidad* Toxsydra(int nivel);
		static Entidad* Voltstryx(int nivel);
		static Entidad* Razorbleed(int nivel);
		static Entidad* JimboElPayasoAsesino(int nivel);
		static Entidad* CianotipoElMounstroCopiador(int nivel);
		
		static std::vector<Entidad*> retornarMinibossRandom(int nivel);

		// Bosses

		static Entidad* AshkarIncandescente();
		static Entidad* GelumdraSilente();
		static Entidad* XyrothInfecto();
		static Entidad* VoltumnDevorasínapsis();
		static Entidad* VarkhemSangrante();
		static Entidad* DiosDesesperacion();

		static std::vector<Entidad*> retornarBossRandom();




		/* 
			ejemplo:

			static entidad* nombre_del_boss()

			// en el cpp
			
			 entidad* entidad::nombre_del_boss(argumentos si tiene) {
			 return new entidad("nombre", hp, atk, def, des, lck, p (puntos o oro que da), {Habilidades que hagan daño, apliquen efectos y invoquen a mas aliados}, {} )
			 }

		 */

		// Fin constructores

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

		bool getVivo();

		std::vector<Efecto> getEfectosActivos();

		std::vector<Habilidad> getHabilidades();

		// Funciones de ENTIDAD
		
		// std::string atacar(Heroe* objetivo);
		
		std::string mostrarHabilidades();
		std::string usarHabilidad(int habilidad);
		
		virtual std::string recibirAtaque(int dano, Efecto posible_efecto);

		virtual std::string aplicarEfecto();

}; 

#endif
