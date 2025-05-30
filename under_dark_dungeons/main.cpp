#include <cstddef>
#include <iomanip>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>
#include <time.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

#include "src/Entidad.h"
#include "src/GrupoEnemigo.h"
#include "src/Grupo_jugador.h"
#include "src/Heroe.h"
#include "src/Objeto.h"


using namespace std;

void mostrarBanner() {
    std::cout << R"(

▗▖ ▗▖▗▖  ▗▖▗▄▄▄ ▗▄▄▄▖▗▄▄▖     ▗▄▄▄  ▗▄▖ ▗▄▄▖ ▗▖ ▗▖    ▗▄▄▄ ▗▖ ▗▖▗▖  ▗▖ ▗▄▄▖▗▄▄▄▖ ▗▄▖ ▗▖  ▗▖ ▗▄▄▖
▐▌ ▐▌▐▛▚▖▐▌▐▌  █▐▌   ▐▌ ▐▌    ▐▌  █▐▌ ▐▌▐▌ ▐▌▐▌▗▞▘    ▐▌  █▐▌ ▐▌▐▛▚▖▐▌▐▌   ▐▌   ▐▌ ▐▌▐▛▚▖▐▌▐▌   
▐▌ ▐▌▐▌ ▝▜▌▐▌  █▐▛▀▀▘▐▛▀▚▖    ▐▌  █▐▛▀▜▌▐▛▀▚▖▐▛▚▖     ▐▌  █▐▌ ▐▌▐▌ ▝▜▌▐▌▝▜▌▐▛▀▀▘▐▌ ▐▌▐▌ ▝▜▌ ▝▀▚▖
▝▚▄▞▘▐▌  ▐▌▐▙▄▄▀▐▙▄▄▖▐▌ ▐▌    ▐▙▄▄▀▐▌ ▐▌▐▌ ▐▌▐▌ ▐▌    ▐▙▄▄▀▝▚▄▞▘▐▌  ▐▌▝▚▄▞▘▐▙▄▄▖▝▚▄▞▘▐▌  ▐▌▗▄▄▞▘
                                                                                                
    )" << std::endl;
}

void narrar(const std::string& linea, int milisegundos = 500) {
    std::cout << linea << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
}

void narrarSinEspacio(const std::string& linea, int milisegundos = 3000) {
    std::cout << linea;
    std::this_thread::sleep_for(std::chrono::milliseconds(milisegundos));
}

// INICIO DIALOGOS ===========================================================================================================================
	
Heroe* elegirHeroe(vector<string> dialogos, vector<Heroe*> yaElejidos, string pregunta) {

	Heroe* ans;

	vector<Heroe*> heroes = {
		Heroe::Caballero(),
		Heroe::Mago(),
		Heroe::Ladron(),
		Heroe::Marginado()

	};

	vector<string> nombres_heroes = {
		"Caballero",
		"Mago",
		"Ladron",
		"Marginado"
	}; 

	vector<pair<string, string>> heroe_dialogo;

	for (int i = 0; i < dialogos.size(); i++) {
			heroe_dialogo.push_back(make_pair(nombres_heroes[i], dialogos[i]));
	}

	vector<Heroe*> disponibles;

	for (Heroe* h_d : heroes) {

		bool noEsta = true;
	


		for (Heroe* h_s : yaElejidos) {
			if (h_d->nameGetter() == h_s->nameGetter()) {
				noEsta = false;
			}
		}

		if (noEsta) {
			disponibles.push_back(h_d);
		}

	}
		

	bool eleccion = true;

	while (eleccion) {



		for (int i = 0; i < disponibles.size(); i++) {
			for (const auto& p : heroe_dialogo) {
				if(disponibles[i]->nameGetter() == p.first) {
					narrar(to_string(i+1) + ". " + p.second);
				}
			}
		}

		cout << endl;
		int eleccion_heroe = 0;
		narrarSinEspacio(pregunta, 700);
		cin >> eleccion_heroe;

		cout << endl;

		if (eleccion_heroe > 0 && eleccion_heroe <= disponibles.size()) {

			ans = disponibles[eleccion_heroe - 1];
			eleccion = false;

		}



	
	}
	
	return ans;

}



Heroe* HistoriaI(vector<Heroe*> yaElejidos) {
    // I. El primero
    narrar("Hay quienes son olvidados.");
    narrar("Y hay quienes eligen desaparecer antes de serlo.");
    narrar("");
    narrar("Caminó durante años por caminos que no llevaban a ningún lugar.");
    narrar("Ya no recordaba el motivo…");
    narrar("solo que no podía detenerse sin escuchar los gritos de su propio pasado.");
    narrar("");
    narrar("Una noche sin luna, bajo la sombra de una torre derrumbada, se detuvo.");
    narrar("No porque encontrara algo.");
    narrar("Sino porque ya no quedaba nada que encontrar.");
    narrar("");


      vector<string> dialogos = {
	"Una espada envuelta en paños, rechazada por su reino, bañada en sangre de aliados.",
    	"Un tomo encadenado, sellado con pactos que chillan cuando se abre.",
    	"Una sortija negra, robada de un altar donde dormía algo que aún respira.",
    	"Una carcajada nerviosa, como un eco constante que nadie más oye."
      };

    Heroe* ans = elegirHeroe(dialogos, yaElejidos, "Escoge que lo mantenia atado al mundo: ");

    narrar("");
    narrar("Ese fue el inicio del silencio.");
    narrar("");

    return ans;

}





Heroe* HistoriaII(vector<Heroe*> yaElejidos) {
    // II. El segundo
    narrar("El tiempo se deformó, estirado entre estaciones que ya no tenían color.");
    narrar("Una figura apareció entre la niebla.");
    narrar("No como aparición.");
    narrar("Sino como si hubiera estado allí todo el tiempo, esperando a ser notada.");
    narrar("");
    narrar("No dijo su nombre.");
    narrar("No miró a los ojos.");
    narrar("Solo compartió el calor precario de un fuego improvisado.");
    narrar("");

    narrar("Escoge cómo revelaba su pasado sin palabras:");

	vector<string> dialogos = {
    "Un yelmo agrietado, el blasón arrancado a cuchillo.",
    "Una máscara quemada, pegada a la piel.",
    "Un saco raído, con el tintinear de algo imposible dentro.",
    "Un silbido desafinado que nadie logra recordar después de escucharlo."
	};

    Heroe* ans = elegirHeroe(dialogos, yaElejidos, "Escoge cómo revelaba su pasado sin palabras: ");

    narrar("");
    narrar("No hubo acuerdos.");
    narrar("Solo caminaron juntos al día siguiente.");
    narrar("");

    return ans;

}

Heroe* HistoriaIII(vector<Heroe*> yaElejidos) {
    // III. El tercero
    narrar("Estaba allí.");
    narrar("Simplemente… estaba.");
    narrar("");
    narrar("Sentado sobre un muro roto, mirando un cielo sin estrellas.");
    narrar("No parecía tener edad, ni pasado, ni intención de moverse.");
    narrar("Pero lo hizo.");
    narrar("");
    narrar("Sin hablar.");
    narrar("Sin sonreír.");
    narrar("Solo caminando en el mismo ritmo.");
    narrar("");

    narrar("Escoge su marca:");

	vector<string> dialogos = {
    	"Una hoja oxidada que vibra al contacto de la traición.",
    	"Un pequeño objeto envuelto en vendas, que supura algo invisible.",
    	"Un guante quemado en forma de garra, que no parece querer soltar nada.",
    	"Una voz aguda, como de niño, pero sin ninguna infancia en ella."
	};

    Heroe* ans = elegirHeroe(dialogos, yaElejidos, "Escoge su marca: ");

    narrar("");
    narrar("Y así fueron tres.");
    narrar("");

    return ans;

}


void HistoriaIV() {


    narrar("No formaron un grupo.");
    narrar("No tejieron alianzas.");
    narrar("No compartieron esperanzas.");
    narrar("");
    narrar("Solo descubrieron que el silencio compartido es menos insoportable que el silencio solo.");
    narrar("Que los pasos en conjunto no pesan tanto.");
    narrar("Que la locura es más lenta cuando alguien más también la arrastra.");
    narrar("");
    narrar("Cada uno venía de un lugar distinto del infierno.");
    narrar("Pero el dolor…");
    narrar("era idéntico.");
    narrar("");

    narrar("Primero fue el murmullo.");
    narrar("Luego, los sueños.");
    narrar("Después, el viento cambió de dirección, como si algo respirara desde el subsuelo.");
    narrar("");
    narrar("Y entonces apareció.");
    narrar("Una herida antigua en la carne del mundo.");
    narrar("Un abismo que no se construyó, sino que despertó.");
    narrar("");
    narrar("La Dark Dungeon.");
    narrar("La única cosa que aún crece mientras el mundo se muere.");

}




void inicioNarracion(vector<Heroe*> grupoJugador) {

	narrar("Entoces un dia del cual lluvia fría caia sobre los restos del mundo conocido...");
	narrar("Entre los susurros del viento, una antigua entrada emerge del abismo: la entrada a la Dark Dungeon.");
    	narrar("Dicen que ninguna luz escapa de sus muros, y que quienes entran... rara vez regresan.");
    	narrar("");
   	narrar("Un grupo de gente sin rumbo, marcado por cicatrices físicas y espirituales, se reúne frente a la grieta en la tierra.");
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

void narracionVictoria() {
    narrar("Salimos.");
    narrar("No ilesos, nunca ilesos… pero vivos.");
    narrar("");
    narrar("La dungeon no nos entregó su secreto sin cobrar un precio.");
    narrar("Nos desgarró la carne, torció nuestra cordura, y nos obligó a mirarnos sin máscaras.");
    narrar("Allí abajo, el tiempo se quebraba, y los nombres ya no importaban.");
    narrar("");
    narrar("Pero resistimos.");
    narrar("No por esperanza, sino por terquedad.");
    narrar("Porque algo en nosotros se negó a morir donde tantos lo hicieron.");
    narrar("");
    narrar("La última puerta cayó.");
    narrar("La última sombra huyó de nuestra mirada.");
    narrar("Y cuando el silencio reemplazó al eco de la oscuridad, supimos que habíamos ganado.");
    narrar("");
    narrar("No hay canción para nosotros.");
    narrar("No hay monumentos ni leyendas.");
    narrar("");
    narrar("Solo la certeza de que la oscuridad, por una vez… retrocedió.");
}

// FIN DIALOGOS ==============================================================================================================================

vector<Heroe*> SeleccionDeHeroe() {

	vector<Heroe*> ans = {};

	ans.push_back(HistoriaI(ans));
	ans.push_back(HistoriaII(ans));
	ans.push_back(HistoriaIII(ans));

	HistoriaIV();

	return ans;

	
}

void eventoCofre(GrupoJugador* jugador , int nivel) {

	// logica del cofre
	// 1 objeto ?
	narrar("Felicidades, has temrinado la sala " + to_string(nivel) + "!\n") ;
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
	int total_oro_ganado;

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

	narrar("\nEntraste en combate contra " + mensaje_combate + "\n", 1000);

	while (jugador->getDerrota() && enemigos->getVivios()) {


		for (Heroe* h : grupo_jugador) {
			if (!h->getEfectosActivos().empty()) {
				narrar(h->aplicarEfecto(), 1000);
			}
		}

		for (Entidad* e : grupo_enemigo) {
			if (!e->getEfectosActivos().empty()) {
				narrar(e->aplicarEfecto(), 1000);
			}
		}

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

			 narrar("Turno de " + h->nameGetter() + "\n\n", 500);

			while (!eleccion_valida) {

			bool target_valido = false;
			int eleccion_jugador = 0;

			cout << "1. Atacar\n2. Habilidades\n3. Usar un item\n4. Ver estado del grupo\n";

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

						narrar( h->atacar(posiblesObjetivos[target - 1], jugador), 1500 );
						if (!posiblesObjetivos[target - 1]->getVivo()){
							narrar(posiblesObjetivos[target - 1]->nameGetter() + " cayo muerto.");
							total_oro_ganado += posiblesObjetivos[target - 1]->pGetter();
						}
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

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1, jugador), 1500 );
								if (!posiblesObjetivos[target - 1]->getVivo()){
									narrar(posiblesObjetivos[target - 1]->nameGetter() + " cayo muerto.");
									total_oro_ganado += posiblesObjetivos[target - 1]->pGetter();
								}
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

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1, jugador), 1500 );
								if (!posiblesObjetivos[target - 1]->getVivo()){
									narrar(posiblesObjetivos[target - 1]->nameGetter() + " cayo muerto.");
									total_oro_ganado += posiblesObjetivos[target - 1]->pGetter();
								}
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

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1, jugador), 1500 );
								if (!posiblesObjetivos[target - 1]->getVivo()){
									narrar(posiblesObjetivos[target - 1]->nameGetter() + " cayo muerto.");
									total_oro_ganado += posiblesObjetivos[target - 1]->pGetter();
								}
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

								narrar( h->atacarConHabilidad(posiblesObjetivos[target - 1], eleccion_habilidad - 1, jugador), 1500 );
								if (!posiblesObjetivos[target - 1]->getVivo()){
									narrar(posiblesObjetivos[target - 1]->nameGetter() + " cayo muerto.");
									total_oro_ganado += posiblesObjetivos[target - 1]->pGetter();
								}
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

			else if (eleccion_jugador == 4) {
				cout << jugador->toString() << endl;
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

			narrar( posibleTargetEnemigo[target_enemigo]->recibirAtaque(e->atkGetter()));
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
		narrar(jugador->sumarOro(total_oro_ganado));
	}


	return ans;

}

// FIN COMBATE NORMAL =================================================================================================================================================================================
 
// COMBATES ESPECIALES
bool combateMiniBoss(GrupoJugador* jugador, int nivel) {

	return combate(jugador, GrupoEnemigo::retornarMinibossRandom(nivel), "");
	
}

bool combateBoss(GrupoJugador* jugador) {
	return combate(jugador, GrupoEnemigo::retornarBossRandom(), "");
}

// FIN COMBATES ESPECIALES ============================================================================================================================================================================

// REGISTRAR PUNTAJES Y LEER PUNTAJES ( DAÑO TOTAL DE CADA JUGADOR ) ==================================================================================================================================
 
void registrarPuntaje(string nombre, int daño_total) {
	
	string ans;

	ofstream archivo("../data/ranking.txt", ios::app);
	if (archivo.is_open()) {
		archivo << nombre << " " << daño_total << "\n";
		archivo.close();
	}

	else {
		cerr << "No se pudo abrir 'data/ranking.txt para escribir'";
	}

}

string leerPuntajes() {
	ifstream archivo("../data/ranking.txt");
	vector<pair<string, int>> puntajes;
	ostringstream ans;

	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			istringstream iss(linea);
			string nombre;
			int daño;
			if (iss >> nombre >> daño) {
				puntajes.push_back({nombre, daño});
			}
		}
		archivo.close();
		
		sort(puntajes.begin(), puntajes.end(), [](const auto& a, const auto& b) {return a.second > b.second;
				});


    	ans << "===== RANKING DE UNDER DE DARK DUNGEONS =====\n";
    	ans << left << setw(5) << "#" 
        	<< setw(20) << "Nombre" 
        	<< right << setw(12) << "Daño total" << "\n";

    	for (size_t i = 0; i < puntajes.size(); ++i) {
       	 	ans << left << setw(5) << to_string(i + 1) + "." 
           	 << setw(20) << puntajes[i].first 
            	<< right << setw(12) << puntajes[i].second << "\n";
    	}

	}

	else {
		ans << "No hay datos de ranking\n";
	}

	return ans.str();
}

// FIN REGISTRAR Y LEER PUNTAJES ======================================================================================================================================================================



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


	// PRUEBAS CACORRAS =========================================================================================================================

 	/*	
	GrupoJugador Yura("Yura", 0, 300);
	vector<Heroe*> testCaballero = {
		Heroe::Caballero(),
		Heroe::Mago()
	};
	
	testCaballero[0]->setHp(10);

	cout << to_string(testCaballero[0]->getHp()) << endl;

	Yura.setHeroes(testCaballero);


	
	Objeto brr = Objeto::MegaPocion();

	Yura.agregarObjeto(&brr);

	eventoSantogrial(&Yura);


	cout << to_string(testCaballero[0]->getHp()) << endl;
	
	Yura.subirDeNivelElEquipo(3);

	if (combateMiniBoss(&Yura, 3))
	 {
		narrar("Ganaste el combate.\n");
	 }

	else
	{
		narrar("Perdiste el combate, todo tu equipo fue masacrado.\n");
	}
	*/

	// FIN PRUEBAS ==============================================================================================================================

	// menu de juego principal
	
	
	bool menu_principal = true;
	char eleccion_usuario_menu_p;

	while (menu_principal) 
	{
			
		eleccion_usuario_menu_p = '\0';
		bool juego = false;

		mostrarBanner();

		cout << "Presione ENTER para iniciar (ESC para salir)..." << endl;
		cout << "Ingresa 'T' para ver la tabla de puntuaciones" << endl;
		cin.clear();
		eleccion_usuario_menu_p = cin.get();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (eleccion_usuario_menu_p == 27) {
			menu_principal = false;
		}

		else if (static_cast<char>(tolower(eleccion_usuario_menu_p)) == 't') {
			cout << leerPuntajes() << endl;
		}

		else if (eleccion_usuario_menu_p == '\n' || eleccion_usuario_menu_p == '\0') {
			juego = true;
		}
		
		if (juego) 
		{
			string nombre_jugador;
			cout << "Ingrese su nombre: ";
			cin >> nombre_jugador;

			cout << endl;

			GrupoJugador Jugador(nombre_jugador, 0, 300);

			// Eleccion de heroes
			
			vector<Heroe*> grupo_jugador = SeleccionDeHeroe();	

			bool in_game = true;
			Jugador.setHeroes(grupo_jugador);
			// Loop del juego
			int nivel = 0;
			inicioNarracion(grupo_jugador);
			bool evento_activo = true;
			while (in_game) 
			{
				
				// Sala 4 mini boss
				// Sala 9 mini boss
				// Sala 3 tesoro
				// Sala 10 Boss
				// Sala 6 tesoro
				// Sala 8 santo grial
				
				if (evento_activo == true) {

				if (nivel == 1 || nivel == 2 || nivel == 5 || nivel == 7 && evento_activo == true) {

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

					evento_activo = false;
				}

				else if (nivel == 3 || nivel == 6 && evento_activo == true) {
				
					// TESORO

					eventoCofre(&Jugador, nivel);
					evento_activo = false;

				}

				else if (nivel == 8) {

					// SANTOGRIAL
					eventoSantogrial(&Jugador);
					evento_activo = false;
				}


				else if( nivel == 4 || nivel == 9 && evento_activo == true) {
				
					// MINIBOSS
					if ( combateMiniBoss(&Jugador, nivel) ) {

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

					evento_activo = false;

				}

				else if (nivel == 10 && evento_activo == true) {

					// BOSS
					if ( combateBoss(&Jugador) ) {

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

					evento_activo = false;
				}

				}

				if (nivel == 11) {
					
					//============================
					//
					// Historia de win
					//
					// y salir del juego
					//
					//============================
					narracionVictoria();
					cout << endl;
					in_game = false;
					registrarPuntaje(Jugador.getName(), Jugador.getTotalDamage());
					break;
				}

				int eleccion_in_game;

				
				cout << "1. Avanzar\n2. Ver Armas\n3. Ver Armaduras\n4. Ver inventario\n5. Ver estado de los heroes\n" << endl;

				cout << "Selecciona una opcion: ";
				cin >> eleccion_in_game;
				cout << "\n";

				if (eleccion_in_game == 1) {
					if (nivel > 0) {
						narrar( Jugador.subirDeNivelElEquipo(nivel), 1500 );
					}
					nivel++;
					evento_activo = true;
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
					narrar( Jugador.toString(), 700); 

				}


			}

		} 

	}




	return 0;
}
