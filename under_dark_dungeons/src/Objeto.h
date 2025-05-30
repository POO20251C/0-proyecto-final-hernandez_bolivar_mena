#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Objeto {

	private:

		std::string name;
		int precio;
		int vida_proporcionada;

	public:

		Objeto(std::string name, int vida_proporcionada, int precio);

		static Objeto BayaAranja();
		static Objeto BayaZidra();
		static Objeto Pocion();
		static Objeto MegaPocion();
		static Objeto HiperPocion();

		//getters, no se necesitan setters ya que los vamos a sobrecargar directamente en el .cpp

		std::string getName();
		int getVida_proporcionada();
		int getPrecio();

};

#endif