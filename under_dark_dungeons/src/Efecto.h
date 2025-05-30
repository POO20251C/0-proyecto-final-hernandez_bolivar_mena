#ifndef EFECTO_H
#define EFECTO_H

#include <string>
class Efecto {

	private:

		std::string name;

		int mult_hp;
		int mult_def;
		int mult_vel;
		int mult_lck;

	public:
		
		// Constructores
	
		Efecto(std::string name, int hp, int def, int vel, int lck);

		Efecto();

		static Efecto Nada();

		static Efecto Quemadura();
		static Efecto Congelacion();
		static Efecto Veneno();
		static Efecto Paralisis();
		static Efecto Sangrado();
		static Efecto Miedo();
		static Efecto Lentitud();
		static Efecto Debilidad();
		static Efecto Ceguera();
		static Efecto Desesperacion();


		// Getters
		std::string getname();
		int gethp();
		int getdef();
		int getvel();
		int getlck();


};

#endif
