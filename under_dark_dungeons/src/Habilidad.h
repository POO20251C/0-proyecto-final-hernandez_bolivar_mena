#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>

class Habilidad{

	private:

		std::string name;
		std::string tipo;

		int mult;
		int usos;

	public:
		
		// Constructor

		Habilidad(std::string name, std::string tipo, int mult, int usos);
		
		// Getters (No se necesitan setters, solo para usos)

		std::string nameGetter();
		std::string tipoGetter();

		int multGetter();

		void usosSetter(int usos);
		int usosGetter();
};

#endif
