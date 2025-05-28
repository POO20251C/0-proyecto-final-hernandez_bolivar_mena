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
		static Habilidad MeraMeraNoMi(); // Calcinacion
		static Habilidad GoroGoroNoMi(); // Paralisis
		static Habilidad DokuDokuNoMi(); // Veneno
		static Habilidad OpeOpeNoMi(); // Desangrado
		static Habilidad HieHieNoMi(); // Congelacion


		
		// Getters (No se necesitan setters, solo para usos)

		std::string nameGetter();
		Efecto efectoGetter();
		int multGetter() const;


};

#endif
