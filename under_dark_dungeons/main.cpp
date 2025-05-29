#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <GrupoEnemigo.h>
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
	narrar("Has llegado al santo Grial\n")  ;
	narrar("Una energía invade tu cuerpo\n");

	vector<Heroe*> heroes = jugador->getHeroes();

	for (Heroe* h : heroes) {

		h->setHp(h->getHpMax());
		cout << h->nameGetter()<< " ha sido curado. Ahora su vida actual es: "
		<< h->getHp() << "/" << h->getHpMax() << "\n";
	}

	// Logica del santo grial
	// Cura a todos los heroes
	// aumenta la vida y todos los atributos de las entidades/heroes en un 10%?
	//
	// Entonces por cada heroe -> Heroe.setHp( Heroe.getHp + (Heroe.getHp * (0.10 * 8)) )

}

bool combate(GrupoJugador* jugador, GrupoEnemigo* enemigos) {

	vector<Entidad*> grupo_enemigo = enemigos->getEnemigos();
	vector<Heroe*> grupo_jugador = jugador->getHeroes();

	string mensaje_combate;
	if (enemigos->getEnemigos().size() > 1) {
		mensaje_combate = "un grupo de " + enemigos->getEnemigos()[0]->nameGetter() + "\n";
	}

	else {
		mensaje_combate = "un " + enemigos->getEnemigos()[0]->nameGetter() + "\n";
	}

	cout << "Entraste en combate contra " + mensaje_combate + "\n";

	// HACER COMBATE OTRA FOKIN VEZ
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


			int eleccion_jugador = 0;
			bool eleccion_valida = false;

			cout << "Turno de " + h->nameGetter() + "\n\n";

			while (!eleccion_valida) {
			bool target_valido = false;

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

						narrar( h->atacar(posiblesObjetivos[target - 1]) );
						target_valido = true;
						eleccion_valida = true;

					}



					// VOLVER ESTA ROTO POR AHORA NO SÉ PORQUE.

					if (target == 4) {

						break;

					}





				}



			}

			// CASO DE USAR HABILIDAD
			else if (eleccion_jugador == 2) {



			}

			// CASO DE USAR UN ITEM
			else if (eleccion_jugador == 3) {

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

				narrar(e->nameGetter() + " va a usar una habilidad\n");

			}

			else {

			int target_enemigo = rand() % (int)posibleTargetEnemigo.size();

			narrar( posibleTargetEnemigo[target_enemigo]->recibirAtaque(e->atkGetter()) );


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

	if (!jugador->getDerrota()) {
		ans = false;
	}

	else if (!enemigos->getVivios()) {
		ans = true;
	}


	return ans;

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
		Heroe::Caballero()
	};

	Yura.setHeroes(testCaballero);

	eventoSantogrial(&Yura);


	if ( combate(&Yura, GrupoEnemigo::genGrupoEnemigo(1)) )
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
					combate(&Jugador, GrupoEnemigo::genGrupoEnemigo(nivel));
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
