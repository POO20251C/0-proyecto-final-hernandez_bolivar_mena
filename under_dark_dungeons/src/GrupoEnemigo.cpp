#include "GrupoEnemigo.h"
#include <ctime>
#include <vector>



// Constructores

GrupoEnemigo::GrupoEnemigo(std::vector<Entidad*> enemigos) {

	this->enemigos = enemigos;

}


GrupoEnemigo* GrupoEnemigo::genGrupoEnemigo(int nivel) {
	
	std::vector<Entidad*> ans;
	srand(time(nullptr));
	
	int cantidad_enemigos = 1 + rand() % 3;
	int enemigos = 1 + rand() % 4;

	if (enemigos == 1) {
		
		for (int i = 0; i < cantidad_enemigos; i++) {
			
			ans.push_back(Entidad::generarGoblin(nivel));
			
		}
		
	}


	else if (enemigos == 2) {
	
		for (int i = 0; i < cantidad_enemigos; i++) {
			
			ans.push_back(Entidad::generarAraña(nivel));
			
		}
		
	}

	else if (enemigos == 3) {
	
		for (int i = 0; i < cantidad_enemigos; i++) {
			
			ans.push_back(Entidad::generarLagarto(nivel));
			
		}
		
	}

	else if (enemigos == 4) {
	
		for (int i = 0; i < cantidad_enemigos; i++) {
			
			ans.push_back(Entidad::generarOrco(nivel));
			
		}
		
	}

	
	return new GrupoEnemigo(ans);
}


GrupoEnemigo* GrupoEnemigo::retornarMinibossRandom(int nivel) {
	
	srand(time(nullptr));
	
	std::vector<Entidad*> pool = {
		
		Entidad::Toxsydra(nivel),
		Entidad::Frostbane(nivel),
		Entidad::Razorbleed(nivel),
		Entidad::Voltstryx(nivel),
		Entidad::CianotipoElMounstroCopiador(nivel),
		Entidad::MiguelDavidArroyo(nivel),
		Entidad::JimboElPayasoAsesino(nivel)

	};

	std::vector<Entidad*> ans;

	int miniboss_random = rand() % 7;

	ans.push_back(pool[miniboss_random]);

	return new GrupoEnemigo(ans);
	

}


GrupoEnemigo* GrupoEnemigo::retornarBossRandom() {
	
	srand(time(nullptr));

	std::vector<Entidad*> pool = {
		Entidad::AshkarIncandescente(),
		Entidad::GelumdraSilente(),
		Entidad::VarkhemSangrante(),
		Entidad::VoltumnDevorasínapsis(),
		Entidad::DiosDesesperacion(),
		Entidad::XyrothInfecto()
	};
	
	std::vector<Entidad*> ans;

	int boss_random = rand() % (int) pool.size();
	
	ans.push_back(pool[boss_random]);

	return new GrupoEnemigo(ans);

}


// Getters

std::vector<Entidad*> GrupoEnemigo::getEnemigos() {
	return this->enemigos;
}

int GrupoEnemigo::getOro() {
	
	int oro_total = 0;

	for(Entidad* e : this->enemigos) {
		oro_total += e->pGetter();
	}

	return oro_total;

}

bool GrupoEnemigo::getVivios() {
	
	bool vivos = true;
	int muertos = 0;
	
	for(Entidad* e : this->enemigos) {
		if (!e->getVivo()) {
			muertos += 1;
		}
	}

	if (muertos == this->enemigos.size()) {
		vivos = false;
	}

	return vivos;

}


