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

#include "src/Entidad.h"
#include "src/GrupoEnemigo.h"
#include "src/Grupo_jugador.h"
#include "src/Heroe.h"
#include "src/Objeto.h"


using namespace std;

void narrar(const std::string& linea, int milisegundos = 3000) {
    std::cout << linea << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
}

// INICIO DIALOGOS ===========================================================================================================================

void inicioNarracion(vector<Heroe*> grupoJugador) {

	

	narrar("Una lluvia fría cae sobre los restos del mundo conocido...");
	narrar("Entre los susurros del viento, una antigua entrada emerge del abismo: la entrada a la Dark Dungeon.");
    	narrar("Dicen que ninguna luz escapa de sus muros, y que quienes entran... rara vez regresan.");
    	narrar("");
   	narrar("Un grupo de guerreros, marcado por cicatrices físicas y espirituales, se reúne frente a la grieta en la tierra.");
    	narrar("No por gloria, no por oro... sino porque ya no tienen nada que perder.");
    	narrar("");
	
	// PRIEMRO

	if (grupoJugador[0]->nameGetter() == "Caballero") {
    		narrar("El primero en entrar es un caballero exiliado, cuyo nombre fue borrado de los libros por traición.");
	}

	else if (grupoJugador[0]->nameGetter() == "Mago") {

    		narrar("El primero en entrar es un Mago que olvido su rostro entre llamas negras y pactos prohibidos.");
	}

	else if (grupoJugador[0]->nameGetter() == "Ladron") {

    		narrar("El primero en entrar es un Ladron que camina sin sombra desde que robó a un dios dormido.");
	}

	else if (grupoJugador[0]->nameGetter() == "Marginado") {

    		narrar("El primero en entrar es un Marginado sin nombre ni historia, que rie cada vez que escucha el llanto de los vivos.");
	}

	// LE SIGUE

	if (grupoJugador[1]->nameGetter() == "Caballero") {
    		narrar("A su lado, un caballero exiliado, cuyo nombre fue borrado de los libros por traición.");
	}

	else if (grupoJugador[1]->nameGetter() == "Mago") {

    		narrar("A su lado, un Mago que olvido su rostro entre llamas negras y pactos prohibidos.");
	}

	else if (grupoJugador[1]->nameGetter() == "Ladron") {

    		narrar("A su lado, un Ladron que camina sin sombra desde que robó a un dios dormido.");
	}

	else if (grupoJugador[1]->nameGetter() == "Marginado") {

    		narrar("A su lado, un Marginado sin nombre ni historia, que rie cada vez que escucha el llanto de los vivos.");
	}

	// POR ULTIMO

	
	if (grupoJugador[2]->nameGetter() == "Caballero") {
    		narrar("Y por ultimo, un caballero exiliado, cuyo nombre fue borrado de los libros por traición.");
	}

	else if (grupoJugador[2]->nameGetter() == "Mago") {

    		narrar("Y por ultimo, un Mago que olvido su rostro entre llamas negras y pactos prohibidos.");
	}

	else if (grupoJugador[2]->nameGetter() == "Ladron") {

    		narrar("Y por ultimo, un Ladron que camina sin sombra desde que robó a un dios dormido.");
	}

	else if (grupoJugador[2]->nameGetter() == "Marginado") {

    		narrar("Y por ultimo, un Marginado sin nombre ni historia, que rie cada vez que escucha el llanto de los vivos.");
	}
	
    	narrar("");
    	narrar("Avanzan por túneles donde la piedra sangra y los ecos devoran los pensamientos.");
    	narrar("Cada nivel los lleva más profundo, no solo en la dungeon... sino en sí mismos.");
    	narrar("La oscuridad no los envuelve... los absorbe.");
    	narrar("");
    	narrar("Bienvenidos a Dark Dungeon.");
    	narrar("Aquí no hay héroes. Solo sobrevivientes.\n");
}

// FIN DIALOGOS ==============================================================================================================================

void eventoCofre(GrupoJugador* jugador ) {

	// logica del cofre
	// 1 objeto ?
	narrar("Felicidades, has temrinado la sala 3! \n") ;
	srand(static_cast<unsigned int>(time(nullptr)));

	vector<Objeto> objetosCofre = {
		Objeto::Pocion(),
		Objeto::MegaPocion(),
		Objeto::HiperPocion(),
		Objeto::BayaZidra(),
		Objeto::BayaAranja()
		};

	int indiceAleatorio = rand() % objetosCofre.size();
	Objeto* objetoObtenido = new Objeto(objetosCofre[indiceAleatorio]);


	cout << "¡Has abierto un cofre y encontrado: " << objetoObtenido->getName() << "!\n";
	cout << "Vida proporcionada: " << objetoObtenido->getVida_proporcionada() << "\n";
	cout << "Precio: " << objetoObtenido->getPrecio() << " monedas\n";

	jugador->agregarObjeto(objetoObtenido);

}




void eventoSantogrial(GrupoJugador* jugador) {

	narrar( "Legendario Heroe, has encontrado una pequeña luz en el grande camino\n")  ;
	narrar( "Han llegado al santo Grial\n", 1500);
	narrar( "Una energía invade su cuerpo\n", 1500);

	vector<Heroe*> heroes = jugador->getHeroes();

	for (Heroe* h : heroes) {

		h->setHp(h->getHpMax());
	}

	narrar("Tu grupo ha sido restaurado por completo");

	// Logica del santo grial
	// Cura a todos los heroes
	// aumenta la vida y todos los atributos de las entidades/heroes en un 10%?
	//
	// Entonces por cada heroe -> Heroe.setHp( Heroe.getHp + (Heroe.getHp * (0.10 * 8)) )

}

// COMBATE NORMAL =====================================================================================================================================================================================

bool combate(GrupoJugador* jugador, GrupoEnemigo* enemigos, string tipo_de_combate) {

	vector<Entidad*> grupo_enemigo = enemigos->getEnemigos();
	vector<Heroe*> grupo_jugador = jugador->getHeroes();
	string mensaje_combate;

	if (tipo_de_combate == "normal") {
		if (enemigos->getEnemigos().size() > 1) {
			mensaje_combate = "un grupo de " + enemigos->getEnemigos()[0]->nameGetter() + "\n";
		}

		else {
			mensaje_combate = "un " + enemigos->getEnemigos()[0]->nameGetter() + "\n";
		}

	}

	else {
		mensaje_combate = enemigos->getEnemigos()[0]->nameGetter();
	}

	cout << "\nEntraste en combate contra " + mensaje_combate + "\n";

	while (jugador->getDerrota() && enemigos->getVivios()) {



		vector<Entidad*> orden;

		for(Heroe* h: grupo_jugador) {
			if (h->getVivo()) {
				orden.push_back(h);
			}
		}

		for (Entidad* e : grupo_enemigo) {
			if (e->getVivo()) {
				orden.push_back(e);
			}
		}

		sort(orden.begin(), orden.end(), [](Entidad* a, Entidad* b) {return a->desGetter() > b->desGetter();
				});


		for (Entidad* e: orden) {
			
			if (!e->getVivo()) {
				continue;
			}

		if (Heroe* h = dynamic_cast<Heroe*>(e))
		{

			// ===========================================================================
			//
			// LOGICA PARA EL JUGADOR
			//
			// 1. Atacar
			// 	|-----> Muestra enemigos y selecciona un objetivo.
			//
			// 2. Habilidades
			// 	|-----> Muestra las habilidades, luego enemigos y selecciona un objetivo.
			//
			// 3. Items
			//	|------> Muestra los items y selecciona a un heroe al cual hacerle efecto.
			//
			// ===========================================================================


				vector<Entidad*> posiblesObjetivos;

				// TODOS LOS OBJETIVOS VALIDOS EN OTRO VECTOR
				for(Entidad* e : grupo_enemigo) {

					if(e->getVivo()) {
						posiblesObjetivos.push_back(e);
					}

				}

				// EN CASO DE QUE SE MUERAN TODOS?
				if (posiblesObjetivos.empty()) {
					break;
				}


			bool eleccion_valida = false;

			cout << "Turno de " + h->nameGetter() + "\n\n";

			while (!eleccion_valida) {

			bool target_valido = false;
			int eleccion_jugador = 0;

			cout << "1. Atacar\n2. Habilidades\n3. Usar un item\n";

			cout << "Vida de " << h->nameGetter() << " " << h->hpGetter() << endl;
			
			cout << "Seleccione una opcion: ";
			cin >> eleccion_jugador;

			cout << endl;


			// CASO DE ATAQUE
			if (eleccion_jugador == 1) {


				while (!target_valido) {

					for(size_t i = 0; i < posiblesObjetivos.size(); i++) {
						cout << to_string(i + 1) << ". " << posiblesObjetivos[i]->nameGetter() << "\t" << posiblesObjetivos[i]->hpGetter() << endl;
					}

					cout << "4. Volver\n";

					int target = 0;
					cout << "Elije un objetivo: ";
					cin.clear();
					cin >> target;

					if (target > 0 && target <= posiblesObjetivos.size()) {

						cout << "\n";

						narrar( h->atacar(posiblesObjetivos[target - 1]), 1500 );
						target_valido = true;
						eleccion_valida = true;

					}

					if (target == 4) {

						break;

					}
				}
			}

			// CASO DE USAR HABILIDAD
			else if (eleccion_jugador == 2) {
				bool menu_habilidades = true;

				while (menu_habilidades) {
					
					int eleccion_habilidad = 0;

					for (int i = 0; i < h->getHabilidades().size(); i++ ) {
						cout << to_string(i + 1) << ". " << h->getHabilidades()[i].nameGetter() << endl;
					}
					
					cout << "5. Salir\n";

					cout << "Seleccina una habilidad: ";
					cin >> eleccion_habilidad;
					
					if (eleccion_habilidad == 1) {
						
						while (!target_valido) {

							for(size_t j = 0; j < posiblesObjetivos.size(); j++) {
								cout << to_string(j + 1) << ". " << posiblesObjetivos[j]->nameGetter() << "\t" << posiblesObjetivos[j]->hpGetter() << endl;
							}

							cout << "4. Volver\n";

							int target = 0;
							cout << "Elije un objetivo: ";
							cin.clear();
							cin >> target;
	
							if (target > 0 && target <= posiblesObjetivos.size()) {
								cout << "\n";

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1), 1500 );
								target_valido = true;
								eleccion_valida = true;
								menu_habilidades = false;

							}

							if (target == 4) {

								break;

							}
						}
					}

					else if (eleccion_habilidad == 2) {
						while (!target_valido) {

							for(size_t j = 0; j < posiblesObjetivos.size(); j++) {
								cout << to_string(j + 1) << ". " << posiblesObjetivos[j]->nameGetter() << "\t" << posiblesObjetivos[j]->hpGetter() << endl;
							}

							cout << "4. Volver\n";

							int target = 0;
							cout << "Elije un objetivo: ";
							cin.clear();
							cin >> target;
	
							if (target > 0 && target <= posiblesObjetivos.size()) {
								cout << "\n";

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1), 1500 );
								target_valido = true;
								eleccion_valida = true;
								menu_habilidades = false;

							}

							if (target == 4) {

								break;

							}
						}
					}

					else if (eleccion_habilidad == 3) {
						while (!target_valido) {

							for(size_t j = 0; j < posiblesObjetivos.size(); j++) {
								cout << to_string(j + 1) << ". " << posiblesObjetivos[j]->nameGetter() << "\t" << posiblesObjetivos[j]->hpGetter() << endl;
							}

							cout << "4. Volver\n";

							int target = 0;
							cout << "Elije un objetivo: ";
							cin.clear();
							cin >> target;
	
							if (target > 0 && target <= posiblesObjetivos.size()) {
								cout << "\n";

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1), 1500 );
								target_valido = true;
								eleccion_valida = true;
								menu_habilidades = false;
								cin.clear();

							}

							if (target == 4) {

								break;

							}
						}
					}

					else if ( eleccion_habilidad == 4) {
						while (!target_valido) {

							for(size_t j = 0; j < posiblesObjetivos.size(); j++) {
								cout << to_string(j + 1) << ". " << posiblesObjetivos[j]->nameGetter() << "\t" << posiblesObjetivos[j]->hpGetter() << endl;
							}

							cout << "4. Volver\n";

							int target = 0;
							cout << "Elije un objetivo: ";
							cin.clear();
							cin >> target;
	
							if (target > 0 && target <= posiblesObjetivos.size()) {
								cout << "\n";

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1), 1500 );
								target_valido = true;
								eleccion_valida = true;
								menu_habilidades = false;
								cin.clear();

							}

							if (target == 4) {

								break;

							}
						}

					}

					else if (eleccion_habilidad == 5) {

						break;

					}
				}
			}

			// CASO DE USAR UN ITEM
			else if (eleccion_jugador == 3) {
					bool eleccion_valida_inventario = true;
					while (eleccion_valida_inventario) {
						int aux_i = 0;
						for (int i = 0; i < jugador->getInventario().size(); i++) {
							cout << to_string(i+1) << ". " << jugador->getInventario()[i]->getName() << " " << to_string(jugador->getInventario()[i]->getVida_proporcionada()) << endl;
							aux_i = i;
						}
						aux_i += 2;
						cout << to_string(aux_i) << ". Volver" << endl;
						int eleccion_usuario_item = 0;
						cout << "Seleccione un item: ";
						cin >> eleccion_usuario_item;

						if(eleccion_usuario_item > 0 && eleccion_usuario_item <= jugador->getInventario().size()) {
								bool seleccion_heroe_inventario = true;
								while (seleccion_heroe_inventario) {
								
									int heroe_item = 0;
									for (int i = 0; i < grupo_jugador.size(); i++) {
										cout << to_string(i+1) << ". " << grupo_jugador[i]->nameGetter() << endl;
									}
									cout << "4. Volver\n";

									cout << "Selecciona un heroe: ";
									cin >> heroe_item;

									if (heroe_item == 4) {
										break;
									}
									else if (heroe_item <= grupo_jugador.size() && heroe_item > 0) {
									
										narrar(jugador->usarItem(eleccion_usuario_item - 1, grupo_jugador[heroe_item - 1]));
										seleccion_heroe_inventario = false;
										eleccion_valida_inventario = false;
										eleccion_valida = true;
										cin.clear();
									}
								}
						}
						else if( eleccion_usuario_item == aux_i) {
							break;
						}
					}
				}
			}

		}	

		else

		{

			// LOGICA PARA LA IA ========================================================
			srand(time(nullptr));
			int prob_hab = 1 + rand() % 100;

			vector<Heroe*> posibleTargetEnemigo;

			for (Heroe* h : grupo_jugador) {
				if (h->getVivo()) {
					posibleTargetEnemigo.push_back(h);
				}
			}

			if (posibleTargetEnemigo.empty()) {
				break;
			}

			if (!e->getHabilidades().empty() && prob_hab < 20) {

				// IA USA UNA HABILIDAD

				narrar(e->nameGetter() + " va a usar una habilidad\n", 1500);

				int habilidad_a_usar = rand() % (int)e->getHabilidades().size();

				int target_enemigo = rand() % (int)posibleTargetEnemigo.size();

				narrar(posibleTargetEnemigo[target_enemigo]->recibirAtaqueHabilidad(e->atkGetter() * e->getHabilidades()[habilidad_a_usar].multGetter() , e->getHabilidades()[habilidad_a_usar].efectoGetter()));
				continue;

			}

			else {

			int target_enemigo = rand() % (int)posibleTargetEnemigo.size();

			narrar( posibleTargetEnemigo[target_enemigo]->recibirAtaque(e->atkGetter()) );
			continue;


			}


		}






	}



		// FIN BUCLE PRINCIPAL DEL COMBATE ==============================================================

	}

	//===========================================================================
	//
	// LOGICA DE QUE RETORNAR
	//
	// jugador->getDerrota() == false -> Derrota del jugador -> devolver false
	//
	// enemigos->getVivos() == false -> Derrota de los enemigos -> devolver true
	//
	// ==========================================================================

	bool ans;

	if (!jugador->getDerrota() && enemigos->getVivios()) {
		ans = false;
	}

	else if (!enemigos->getVivios() && jugador->getDerrota()) {
		ans = true;
	}


	return ans;

}

// FIN COMBATE NORMAL =================================================================================================================================================================================

bool combateMiniBoss(GrupoJugador* jugador, int nivel) {

	combate(jugador, GrupoEnemigo::retornarMinibossRandom(nivel), "");
	
	return true;
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


	// Pruebas cacorras para el combate
	
	
	GrupoJugador Yura("Yura", 0, 300);
	vector<Heroe*> testCaballero = {
		Heroe::Caballero(),
		Heroe::Mago()
	};

	Yura.setHeroes(testCaballero);
	
	Objeto brr = Objeto::MegaPocion();

	Yura.agregarObjeto(&brr);

	// eventoSantogrial(&Yura);
	
	Yura.subirDeNivelElEquipo(3);

	if (combateMiniBoss(&Yura, 3))
	 {
		narrar("Ganaste el combate.\n");
	 }

	else
	{
		narrar("Perdiste el combate, todo tu equipo fue masacrado.\n");
	}

	

	// menu de juego principal
	
	cout << "\nUnder dark dugeons" << endl;

	cout << endl;
	
	bool menu_principal = true;

	while (menu_principal) 
	{
	
		char eleccion_usuario_menu_p;
		bool juego = false;

		cout << "Presione ENTER para iniciar (ESC para salir)..." << endl;
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
				
				cout << "\n1. Caballero\n2. Mago\n3. Ladron\n4. Marginado\n" << endl;
				cin >> p_heroe;

				if (p_heroe == 1) {
					// Seleccionar caballero
					narrar("\n"); 
					narrar("Un caballero se une a tu grupo.\n", 1000);
					grupo_jugador.push_back(Heroe::Caballero());
				}

				else if (p_heroe == 2) {
					// Seleccion Mago
					narrar("\n", 1000);
					narrar("Un mago se une a tu grupo.\n", 1000);
					grupo_jugador.push_back(Heroe::Mago());
				}

				else if (p_heroe == 3) {
					// Seleccion Ladron
					narrar("\n", 1000);
					narrar("Un ladro se une a tu grupo.\n", 1000);
					grupo_jugador.push_back(Heroe::Ladron());
				}

				else if (p_heroe == 4) {
					// Seleccion marginado
					narrar("\n", 1000);
					narrar("Un marginado se une a tu grupo\n", 1000);
					grupo_jugador.push_back(Heroe::Marginado());
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

				// Sala 4 mini boss
				// Sala 9 mini boss
				// Sala 3 tesoro
				// Sala 10 Boss
				// Sala 6 tesoro
				// Sala 8 santo grial
				 
				if (nivel == 1 || nivel == 2 || nivel == 3 || nivel == 5 || nivel == 7 ) {

					if ( combate(&Jugador, GrupoEnemigo::genGrupoEnemigo(nivel), "normal") ) {

						narrar("\nEl grupo salio victorioso...");
						narrar("...\n");

					}

					else {
						narrar("\nEl grupo ha sido masacrado...\n");
						narrar("...");
						narrar("Fin del juego.\n");
						in_game = false;
						break;
					}
				}



				if (nivel == 11) {
					
					//
					// Historia de win
					//
					// y salir del juego
					//

					in_game = false;
				}

				int eleccion_in_game;

				
				cout << "1. Avanzar\n2. Ver Armas\n3. Ver Armaduras\n4. Ver inventario\n5. Ver estado de los heroes\n" << endl;

				cout << "Selecciona una opcion: ";
				cin >> eleccion_in_game;

				if (eleccion_in_game == 1) {
					if (nivel > 0) {
						narrar( Jugador.subirDeNivelElEquipo(nivel), 1500 );
					}
					nivel++;
				}

				else if (eleccion_in_game == 2) {
					
					// Mostrar armas y preguntar si equipar

				}

				else if (eleccion_in_game == 3) {
					
					// Mostrar armaduras y preguntar si equipar

				}

				else if (eleccion_in_game == 4) {

					// mostrar inventario y preguntar si usar un item 

				}

				else if (eleccion_in_game == 5) {

					// Mostrar a todos los heroes y sus estados

				}


			}

		} 

	}




	return 0;
}
