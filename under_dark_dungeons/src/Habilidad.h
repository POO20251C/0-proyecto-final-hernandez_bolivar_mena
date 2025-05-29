#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>
#include "Efecto.h"

class Habilidad{

	private:

		std::string name;
		Efecto efecto;
		int mult;


	public:
		
		// Constructores, se necesitan los statics para hacer la sobrecarga

		Habilidad(std::string name, Efecto efecto, int mult);

		static Habilidad HitoHitoNoMi(); // Nada
		static Habilidad MeraMeraNoMi(); // Quemadura
		static Habilidad GoroGoroNoMi(); // Paralisis
		static Habilidad DokuDokuNoMi(); // Veneno
		static Habilidad OpeOpeNoMi(); // Desangrado
		static Habilidad HieHieNoMi(); // Congelacion
		static Habilidad BomuBomuNoMi(); // Quemadura x2
		static Habilidad SunaSunaNoMi(); // Ceguera
		static Habilidad YamiYamiNoMi(); // Miedo
		static Habilidad PikaPikaNoMi(); // Ceguera
		static Habilidad MaguMaguNoMi(); // Quemadura
		static Habilidad NoroNoroNoMi(); // Lentitud
		static Habilidad HoroHoroNoMi(); // Debilidad
		static Habilidad KageKageNoMi(); // Desesperacion


		
		// Getters (No se necesitan setters, solo para usos)

		std::string nameGetter();
		Efecto efectoGetter();
		int multGetter() const;


};

#endif
