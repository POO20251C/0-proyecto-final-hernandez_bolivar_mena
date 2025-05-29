#include "Entidad.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

#include "Efecto.h"
#include "Habilidad.h"


// Constructor

Entidad::Entidad(std::string name, int hp, int atk, int def, int des, int lck, int p, std::vector<Habilidad> habilidades, std::vector<Efecto> efectos) {
	this->name = name;

	this->habilidades = habilidades;
	this->efectos = efectos;

	this->hp = hp;
	this->atk = atk;
	this->def = def;
	this->des = des;
	this->lck = lck;

	this->p = p;

	this->vivo = true;
}

// Enemigos

Entidad* Entidad::generarGoblin(int nivel) {
    int hp = 40 + (nivel * 20);
    int atk = 15 + (nivel * 20);
    int def = 5 + (nivel * 20);
    int des = 20 + (nivel * 20);
    int lck = 10 + (nivel * 7);
    int p = 100 + (nivel * 20);
    return new Entidad("Goblin", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarLagarto(int nivel) {
	int hp = 60 + (nivel * 20);
	int atk = 22 + (nivel * 20);
	int def = 10 + (nivel * 20);
	int des = 12 + (nivel * 20);
    int lck = 6 + (nivel * 7);
    int p = 200 + (nivel * 20);
    return new Entidad("Lagarto", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarAraña(int nivel) {
    int hp = 80 + (nivel * 20);
    int atk = 20 + (nivel * 20);
    int def = 15 + (nivel * 20);
    int des = 15 + (nivel * 20);
    int lck = 10 + (nivel * 7);
    int p = 200 + (nivel * 20);
    return new Entidad("Araña", hp, atk, def, des, lck, p, {}, {});
}

Entidad* Entidad::generarOrco(int nivel) {
    int hp = 100 + (nivel * 20);
    int atk = 25 + (nivel * 20);
    int def = 20 + (nivel * 20);
    int des = 28 + (nivel * 20);
    int lck = 3 + (nivel * 7);
    int p = 400 + (nivel * 20);
    return new Entidad("Orco", hp, atk, def, des, lck, p, {}, {});
}

std::vector<Entidad*> Entidad::Goblings(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarGoblin(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Lagartos(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarLagarto(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Araña_gigantes(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarAraña(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

std::vector<Entidad*> Entidad::Orcos(int cantidad, int nivel ) {
	std::vector<Entidad*> grupo;
	for (int i = 0; i < cantidad; i++) {
		grupo.push_back(generarOrco(nivel));
		grupo[i]->nameSetter(grupo[i]->nameGetter() + " " + std::to_string(i+1));
	}
	return grupo;
}

//MINIBOSSES

Entidad* Entidad::Toxsydra(int nivel) {

	int hp = 80 + (nivel * 40);
	int atk = 30 + (nivel * 20);
	int def = 35 + (nivel * 20);
	int des = 45 + (nivel * 20);
	int lck = 60 + (nivel * 20);
	int p = 400 + (nivel * 20);

	return new Entidad("Toxysdra", hp, atk, def, des, lck, p, {Habilidad::DokuDokuNoMi()}, {} );
}

Entidad* Entidad::Frostbane(int nivel) {

	int hp = 120 + (nivel * 40);
	int atk = 40 + (nivel * 20);
	int def = 20 + (nivel * 20);
	int des = 40 + (nivel * 20);
	int lck = 55 + (nivel * 20);
	int p = 350 + (nivel * 20);

	return new Entidad("Frostbane", hp, atk, def, des, lck, p, {Habilidad::HieHieNoMi()}, {} );

}

Entidad* Entidad::Razorbleed(int nivel) {

	int hp = 130 + (nivel * 40);
	int atk = 15 + (nivel * 20);
	int def = 60 + (nivel * 20);
	int des = 10 + (nivel * 20);
	int lck = 75 + (nivel * 20);
	int p = 300 + (nivel * 20);

	return new Entidad("Razorbleed", hp, atk, def, des, lck, p, {Habilidad::OpeOpeNoMi()}, {} );
}

Entidad* Entidad::Voltstryx(int nivel) {

	int hp = 70 + (nivel * 40);
	int atk = 50 + (nivel * 20);
	int def = 15 + (nivel * 20);
	int des = 50 + (nivel * 20);
	int lck = 65 + (nivel * 20);
	int p = 450 + (nivel * 20);

	return new Entidad("Voltstryx", hp, atk, def, des, lck, p, {Habilidad::GoroGoroNoMi()}, {} );
}


Entidad* Entidad::CianotipoElMounstroCopiador(int nivel) {


	int hp = 110 + (nivel * 40);
	int atk = 45 + (nivel * 20);
	int def = 36 + (nivel * 20);
	int des = 45 + (nivel * 20);
	int lck = 60 + (nivel * 20);
	int p = 200 + (nivel * 20);

	return new Entidad("Cianotipo El Mounstro Copiador", hp, atk, def, des, lck, p, {Habilidad::HitoHitoNoMi()}, {} );
}

Entidad* Entidad::MiguelDavidArroyo(int nivel) {

	int hp = 70 + (nivel * 40);
	int atk = 35 + (nivel * 20);
	int def = 25 + (nivel * 20);
	int des = 65 + (nivel * 20);
	int lck = 72 + (nivel * 20);
	int p = 450 + (nivel * 20);

	return new Entidad("Miguel D. Kuzan", hp, atk, def, des, lck, p, {Habilidad::HieHieNoMi()}, {} );;
}

Entidad* Entidad::JimboElPayasoAsesino(int nivel) {

	int hp = 140 + (nivel * 40);
	int atk = 20 + (nivel * 20);
	int def = 40 + (nivel * 20);
	int des = 10 + (nivel * 20);
	int lck = 55 + (nivel * 20);
	int p = 300 + (nivel * 20);

	return new Entidad("Cianotipo El Mounstro Copiador", hp, atk, def, des, lck, p, {Habilidad::HitoHitoNoMi()}, {} );
}


std::vector<Entidad*> Entidad::retornarMinibossRandom(int nivel) {
	
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

	return ans;
	

}

// BOSSES MAYORES

Entidad* Entidad::AshkarIncandescente() {

	return new Entidad("Ashkar, el Corazón Incandescente", 250, 80, 80, 40, 80, 700, {Habilidad::MeraMeraNoMi(), Habilidad::MaguMaguNoMi()}, {} );
}

Entidad* Entidad::GelumdraSilente() {
	return new Entidad("Gelumdra, Reina del Hielo Silente ", 200, 100,50,75,85,800, {Habilidad::HieHieNoMi(), Habilidad::SunaSunaNoMi()}, {});
}

Entidad *Entidad::VarkhemSangrante() {
	return new Entidad("Varkhem, el Desollado Sangrante ", 350, 90,90,45,85,900, {Habilidad::OpeOpeNoMi(), Habilidad::BomuBomuNoMi()}, {});
}

Entidad* Entidad::VoltumnDevorasínapsis() {
	return new Entidad("Voltumn, el Devorasínapsis ", 150, 100,80,90,90,850, {Habilidad::GoroGoroNoMi(), Habilidad::PikaPikaNoMi()}, {});
}

Entidad* Entidad::DiosDesesperacion() {
	return new Entidad("Dios la Desesperacion", 400, 100,100,100,90,2000, {Habilidad::HoroHoroNoMi(), Habilidad::YamiYamiNoMi(), 
			Habilidad::BomuBomuNoMi(), Habilidad::PikaPikaNoMi(), Habilidad::GoroGoroNoMi(), Habilidad::HieHieNoMi(), Habilidad::SunaSunaNoMi(), 
			Habilidad::OpeOpeNoMi(), Habilidad::DokuDokuNoMi(), Habilidad::KageKageNoMi(), Habilidad::MaguMaguNoMi(), Habilidad::MeraMeraNoMi(),
			Habilidad::NoroNoroNoMi()}, {});
}

Entidad *Entidad::XyrothInfecto() {
	return new Entidad("Xyroth, el Jardín Infecto ", 200, 100,50,85,90,750, {Habilidad::DokuDokuNoMi(), Habilidad::NoroNoroNoMi()}, {});
}


std::vector<Entidad*> Entidad::retornarBossRandom() {
	
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

	return ans;

}


// Getters - Setters

void Entidad::nameSetter(std::string name) {
	this->name = name;
}

std::string Entidad::nameGetter() {
	return this->name;
}


void Entidad::hpSetter(int hp) {
	this->hp = hp;
}

int Entidad::hpGetter() {
	return this->hp;
}

void Entidad::atkSetter(int atk) {
	this->atk = atk;
}

int Entidad::atkGetter() {
	return this->atk;
}

void Entidad::defSetter(int def) {
	this->def = def;
}

int Entidad::defGetter() {
	
	int trueDef = this->def;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueDef += efectos[i].getdef();
		}
	}

	return trueDef;
}

void Entidad::desSetter(int des) {
	this->des = des;
}

int Entidad::desGetter() {
	int trueDes = this->des;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueDes += efectos[i].getvel();
		}
	}

	return trueDes;
}

void Entidad::lckSetter(int lck) {
	this->lck = lck;	
}

int Entidad::lckGetter() {
	int trueLck = this->lck;

	if (!this->efectos.empty()) {

		for (int i = 0; i < this->efectos.size(); i++ ) {
			trueLck += efectos[i].getlck();
		}
	}

	return trueLck;
}

void Entidad::pSetter(int p) {
	this->p = p;
}

int Entidad::pGetter() {
	return this-> p;
}

bool Entidad::getVivo() {
	bool ans = true;
	if (this->hp <= 0) {
		if (this->hp < 0) {
			this->hp = 0;
		}
		ans = false;
	}
	return ans;
}


std::vector<Habilidad> Entidad::getHabilidades() {
	return this->habilidades;
}

// Funciones generales de identidad


std::string Entidad::recibirAtaque(int dano, Efecto posible_efecto) {

	// def es un porcentaje -> dano - (dano * (def/100))
	// lck es un una probabilidad de que no se aplique el efecto


	srand(time(nullptr));
	std::string ans;
	int dano_total = dano - (this->defGetter() * 0.3);
	if(this->hpGetter() - dano_total <= 0) {
		this->hp = 0;
		ans = this->name + " cayó muerto.\n";
	}
	
	else {

		// RECIBE EL DAÑOOOO

		this->hp -= dano_total;

		int prob = 1 + rand() % 100;
		if (prob > lck) {
			this->efectos.push_back(posible_efecto);
			ans  = this->name + " recibio " +  posible_efecto.getname();
		}
	}

	return ans;

}

std::string Entidad::aplicarEfecto() {

	int dano_total = 0;
	std::string ans;

	for (Efecto e : this->efectos) {
		
		dano_total += e.gethp();
		ans = this->name + " recibio " + std::to_string(e.gethp()) + " por "  + e.getname() + "\n";

		if (this->hpGetter() + dano_total <= 0) 
		{
			ans += this->name + " murio por " + e.getname() + "\n";
		}

	}

	return ans;

}




// ESTA FUNCION ES PARA HEROE NO PARA ENTIDAD
//
// QUIEN HIZO ESTO AQUI??
//
// AAAAH NO, Los minibosses y los bosses tambien usan habilidades MLP.

std::string Entidad::mostrarHabilidades() {

	std::string ans = "";

	for (int i = 0; i < this->habilidades.size(); i++) {
		ans += std::to_string(i+1) + ". " + habilidades[i].nameGetter() + "\n"; 
	}

	return ans;
}



