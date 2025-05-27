#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <random>
#include <time.h>

#include "src/Efecto.h"
#include "src/Entidad.h"
#include "src/Grupo_jugador.h"
#include "src/Habilidad.h"
#include "src/Heroe.h"
#include "src/Armadura.h"
#include "src/Arma.h"


using namespace std;






void combate(GrupoJugador* jugador, int nivel) {
	srand(time(nullptr));
	int number_of_enemies = rand() % 3 + 1;
	string nombre_mounstros;
	vector<Entidad*> grupo_enemigo;
	bool derrota_grupo_enemigo = true;

	// Mercado inicial sala 1
	// Cofre sala 3
	// Tesoro sala 6
	// Santo grial y boss final sala 8

	if (nivel == 1 || nivel == 5) {
		grupo_enemigo = Entidad::Goblings(number_of_enemies, nivel);
		if (number_of_enemies != 1) {
			nombre_mounstros = "un grupo de goblings.";
		}
		else {
			nombre_mounstros = "un gobling.";
		}
	}	

	else if (nivel == 2 || nivel == 6) {
		grupo_enemigo = Entidad::Lagartos(number_of_enemies, nivel);
		if (number_of_enemies != 1) {
			nombre_mounstros = "un grupo de lagartos.";
		}
		else {
			nombre_mounstros = "un lagarto.";
		}
	}

	else if (nivel == 3 || nivel == 7) {
		grupo_enemigo = Entidad::Araña_gigantes(number_of_enemies, nivel);
		if (number_of_enemies != 1) {
			nombre_mounstros = "un grupo de arañas.";
		}
		else {
			nombre_mounstros = "una araña.";
		}
	}

	else if (nivel == 4) {
		grupo_enemigo = Entidad::Orcos(number_of_enemies, nivel);
		if (number_of_enemies != 1) {
			nombre_mounstros = "un grupo de orcos.";
		}
		else {
			nombre_mounstros = "un orco.";
		}
	}


	cout << "Has entrado en combate contra " + nombre_mounstros << endl;
	

	while (jugador->getDerrota() && derrota_grupo_enemigo) {
	
	}

}



int main() {


	// Inicializacion de cosas
	

	// prueba de efectos 
	vector<Efecto> efectos_base = { 
		Efecto("Nada", 0, 0, 0, 0), 
		Efecto("Aun nada", 0, 0, 0, 0) 
	};

	// prueba de armas (Sobrecarga)
	
	vector<Arma*> armas_base = {
		Arma::Espada_basica(),
		Arma::Baston_basico(),
		Arma::Daga_basica(),
		Arma::Palo_desgastado()
	};	
	
	// menu de juego principal
	
	cout << "Under dark dugeons" << endl;

	cout << endl;
	
	bool menu_principal = true;

	while (menu_principal) 
	{
	
		char eleccion_usuario_menu_p;
		bool juego = false;

		cout << "Presione una tecla para iniciar (ESC para salir)..." << endl;
		cin.get(eleccion_usuario_menu_p);

		if (eleccion_usuario_menu_p == static_cast<char>(27)) {
			menu_principal = false;
		}

		else {
			juego = true;
		}
		


		
		if (juego) 
		{
			string nombre_jugador;
			cout << "Ingrese su nombre: ";
			cin >> nombre_jugador;

			GrupoJugador Jugador(nombre_jugador, 0, 300);

			// Eleccion de heroes
			
			vector<Heroe*> grupo_jugador;
			
			for (int eleccion_heroes = 0 ; eleccion_heroes < 3; eleccion_heroes++) {
				int p_heroe = 0;
				
				cout << "1. Guerrero\n2. Mago\n3. Ladron\n4. Marginado" << endl;
				cin >> p_heroe;

				if (p_heroe == 1) {
					// Seleccion Guerrero
				}

				else if (p_heroe == 2) {
					// Seleccion Mago
				}

				else if (p_heroe == 3) {
					// Seleccion Ladron
				}

				else if (p_heroe) {
					// Seleccion marginado
				}

			}

			bool in_game = true;

			// Loop del juego

			while (in_game) 
			{
				
				int eleccion_in_game;

				int nivel = 0;

				cout << "1. Avanzar\n2. Ver Armas\n3. Ver Armaduras\n4. Ver equipo" << endl;
				cin >> eleccion_in_game;



				
				

				
			}




		} 



	}
 

	
	





	return 0;
}
