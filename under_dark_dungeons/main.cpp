#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>

#include "src/Efecto.h"
#include "src/Entidad.h"
#include "src/Grupo_jugador.h"
#include "src/Heroe.h"
#include "src/Arma.h"


using namespace std;

void narrar(const std::string& linea, int milisegundos = 3000) {
    std::cout << linea << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
}

void inicioNarracion(vector<Heroe*> grupoJugador) {
	narrar("Una lluvia fría cae sobre los restos del mundo conocido...");
	narrar("Entre los susurros del viento, una antigua entrada emerge del abismo: la entrada a la Dark Dungeon.");
    	narrar("Dicen que ninguna luz escapa de sus muros, y que quienes entran... rara vez regresan.");
    	narrar("");
   	narrar("Un grupo de guerreros, marcado por cicatrices físicas y espirituales, se reúne frente a la grieta en la tierra.");
    	narrar("No por gloria, no por oro... sino porque ya no tienen nada que perder.");
    	narrar("");
    	narrar("El primero en entrar es un caballero exiliado, cuyo nombre fue borrado de los libros por traición.");
    	narrar("A su lado, un mago que olvidó su rostro entre llamas negras y pactos prohibidos.");
    	narrar("Les sigue un ladrón, que camina sin sombra desde que robó de un dios dormido.");
    	narrar("Y por último, un marginado sin nombre ni historia, que ríe cada vez que escucha el llanto de los vivos.");
    	narrar("");
    	narrar("Avanzan por túneles donde la piedra sangra y los ecos devoran los pensamientos.");
    	narrar("Cada nivel los lleva más profundo, no solo en la dungeon... sino en sí mismos.");
    	narrar("La oscuridad no los envuelve... los absorbe.");
    	narrar("");
    	narrar("Bienvenidos a Dark Dungeon.");
    	narrar("Aquí no hay héroes. Solo sobrevivientes.\n");
}

void eventoCofre(GrupoJugador* jugador ) {

	// logica del cofre
	// 1 objeto ?
	std::cout<< "Felicidades, has temrinado la sala 3! \n";


}


void eventoSantogrial(GrupoJugador* jugador, int nivel) {

	// Logica del santo grial
	// Cura a todos los heroes
	// aumenta la vida y todos los atributos de las entidades/heroes en un 10%?
	//
	// Entonces por cada heroe -> Heroe.setHp( Heroe.getHp + (Heroe.getHp * (0.10 * nivel)) )




}

void combate(GrupoJugador* jugador, int nivel) {
	srand(time(nullptr));
	int number_of_enemies = rand() % 3 + 1;
	string nombre_mounstros;
	vector<Entidad*> grupo_enemigo;
	bool derrota_grupo_enemigo = true;

	// Mercado inicial sala 1
	// Cofre sala 3
	// Miniboss sala 4
	// Tesoro sala 6
	// Miniboss Sala 7
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

	else if (nivel == 2) {
		grupo_enemigo = Entidad::Lagartos(number_of_enemies, nivel);
		if (number_of_enemies != 1) {
			nombre_mounstros = "un grupo de lagartos.";
		}
		else {
			nombre_mounstros = "un lagarto.";
		}
	}

	else if (nivel == 3) {
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
	
	vector<Entidad*> orden;

	for (Heroe* h : jugador->getHeroes()) {
		orden.push_back(static_cast<Entidad*>(h));
	}

	orden.insert(orden.end(), grupo_enemigo.begin(), grupo_enemigo.end());

	narrar("Has entrado en combate contra " + nombre_mounstros);
	
	while (jugador->getDerrota() && derrota_grupo_enemigo) {

		orden.erase(
    		remove_if(orden.begin(), orden.end(), [](Entidad* e) { return !e->getVivo(); }),
    		orden.end());

		sort(orden.begin(), orden.end(), [](Entidad* a, Entidad* b) {
		return a->desGetter() > b->desGetter();
					});
	
		for (Entidad* e : orden) {
			
			Heroe* h = dynamic_cast<Heroe*>(e);
			
			if (h != nullptr) {
			// ES UN HEROE
			// Logica del combate para el heroe
			int jugador_eleccion_combate;
			bool eleccion_valida = false;

			while (!eleccion_valida) {

				cout << "Estas usando a " + h->nameGetter() + " que deseas hacer?\n";

				cout << "1. Atacar\n2. Usar habilidad\n3. Usar un item\n";
			
				cout << "Selecciona una opcion: ";
				cin >> jugador_eleccion_combate;

				if (jugador_eleccion_combate == 1) {
				
					while (!eleccion_valida) {

						// Verificar muertos
						
						grupo_enemigo.erase(remove_if(grupo_enemigo.begin(), grupo_enemigo.end(),[](Entidad* e) {return !e->getVivo(); }));

						// Mostrar y seleccionar enemigo/s
						cout << "#	Nombre		Vida\n";
						for (int i = 0; i < grupo_enemigo.size(); i++) {

							cout << to_string(i+1) + ". \t" + grupo_enemigo[i]->nameGetter() + " \t" + to_string(grupo_enemigo[i]->hpGetter()) << endl; 
						}
						
						cout << endl;
						cout << "Selecciona un objetivo: ";
						cin >> jugador_eleccion_combate;
						if (jugador_eleccion_combate > grupo_enemigo.size() || jugador_eleccion_combate < 0) {
						
							cout << "Selecciona un objetivo valido!!\n";
						
						}

						else {

							narrar( h->atacar(grupo_enemigo[jugador_eleccion_combate - 1], nivel) );
							eleccion_valida = true;

						}

					
					}
				

				}

				else if (jugador_eleccion_combate == 2) {
	
					// Mostrar habilidades, seleccionar habilidad, Mostrar y seleccionar enemigo/s

				}

				else if (jugador_eleccion_combate == 3) {

					// Mostrar items y seleccionar heroe al cual afectar

				}

			}



			}

			else {

				// ES UNA ENTIDAD
				// Logica para el combate de la IA
			
				int hab_atk_enemigo = 1 + rand() % 100;

				if (!e->getHabilidades().empty() && hab_atk_enemigo < 20) {

					narrar("No hizo nada " + e->nameGetter());

				}
				
				else {

					int target = rand() % jugador->getHeroes().size();
					
					narrar(jugador->getHeroes()[target]->recibirAtaque(e->atkGetter()));

				}




			}
		}



			grupo_enemigo.erase(
    				remove_if(
        				grupo_enemigo.begin(),
        				grupo_enemigo.end(),
        				[](Entidad* e) { return !e->getVivo(); }
    				),
   	 			grupo_enemigo.end()
		);	
		
		if (grupo_enemigo.empty()) {
			derrota_grupo_enemigo = false;
		}
		
	
	}

}

// MAIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIN ACA ESTA EL PROGRAMA PRINCIPAL
//
//
//
//
//
//
//
//
//
//
// =====================================================================

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
				
				cout << "1. Caballero\n2. Mago\n3. Ladron\n4. Marginado" << endl;
				cin >> p_heroe;

				if (p_heroe == 1) {
					// Seleccionar caballero
					narrar("");
					narrar("Un caballero se ha unido a tu grupo");
					narrar("\n");
					grupo_jugador.push_back(Heroe::Caballero());
				}

				else if (p_heroe == 2) {
					// Seleccion Mago
				}

				else if (p_heroe == 3) {
					// Seleccion Ladron
				}

				else if (p_heroe == 4) {
					// Seleccion marginado
				}

			}

			bool in_game = true;
			Jugador.setHeroes(grupo_jugador);
			// Loop del juego
			int nivel = 0;
			while (in_game) 
			{
				
				// Historia de como llegaron a la dungeon
				if(nivel == 0) {
					inicioNarracion(grupo_jugador);	
				}

				if (nivel == 1) {
					combate(&Jugador, nivel);
				}


				int eleccion_in_game;

				
				cout << "1. Avanzar\n2. Ver Armas\n3. Ver Armaduras\n4. Ver equipo\n5. Ver inventario\n6. Ver estado de los heroes" << endl;
				cin >> eleccion_in_game;

				if (eleccion_in_game == 1) {
					nivel++;
				}


				
				if (nivel == 8 && Jugador.getDerrota()) {
					in_game = false;
				}
	




			}

		} 

	}

	return 0;
}
