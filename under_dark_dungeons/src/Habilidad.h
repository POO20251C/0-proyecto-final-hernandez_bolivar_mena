#ifndef HABILIDAD_H
#define HABILIDAD_H

#include <string>
#include <vector>
#include "Efecto.h"

class Habilidad{

	private:

		std::string name;
		Efecto efecto;
		float mult;


	public:
		
		// Constructores, se necesitan los statics para hacer la sobrecarga

		Habilidad(std::string name, Efecto efecto, float mult);
		

		// HABILIDADES MINIBOSSES/BOSSES
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


		
		// HABILIDADES PARA EL CABALLERO
		static Habilidad Corte();
		static Habilidad Mandoble();
		static Habilidad Tajada();
		static Habilidad Amputacion();

		static std::vector<Habilidad> Habilidades_caballero();

		// HABILIDADES PARA EL LADRON
		static Habilidad Golpe_rapido();
		static Habilidad Tajo_preciso();
		static Habilidad Desgarro();
		static Habilidad Rodillazo();

		static std::vector<Habilidad> Habilidades_ladron();

		// HABILIDADES PARA EL MARGINADO
		static Habilidad Grito_de_furia();
		static Habilidad Recuerdos_de_guerra();
		static Habilidad Golpetazo();
		static Habilidad Pisoton();

		static std::vector<Habilidad> Habilidades_marginado();

		// HABILIDADES MAGO
		static Habilidad Bola_de_fuego();
		static Habilidad Escarcha();
		static Habilidad Rayo();
		static Habilidad Charco_venenoso(); 

		static std::vector<Habilidad> Habilidades_mago();

		// Getters (No se necesitan setters, solo para usos)

		std::string nameGetter();
		Efecto efectoGetter();
		int multGetter() const;


};

#endif
