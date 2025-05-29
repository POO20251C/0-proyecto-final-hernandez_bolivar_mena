#include "Heroe.h"
#include "Entidad.h"
#include "Armadura.h"
#include "Arma.h"
#include "Habilidad.h"
#include <time.h>
#include "Efecto.h"
#include <string>
#include <vector>

// Constructores

Heroe::Heroe(std::string name, int hp, int hp_base, int atk, int def, int des, int lck, int p,
             std::vector<Habilidad> habilidades,
             std::vector<Efecto> efectos,
             Armadura* armadura_inicial,
             Arma* arma_inicial) 
	     :Entidad(name, hp, atk, def, des, lck, p, habilidades, efectos), armadura(armadura_inicial), arma(arma_inicial) {

		this->arma = arma_inicial;
		this->armadura = armadura_inicial;
		this->hp = hp;
		this->vivo = true;
		this->hp_max = hp_base;

    }

Heroe* Heroe::Caballero() {
	return new Heroe("Caballero", 120, 120, 30, 40, 40, 30, 0, Habilidad::Habilidades_caballero(), {}, Armadura::mallaLigera(), Arma::Espada_basica());
}

Heroe* Heroe::Mago() {
	return new Heroe("Mago", 70, 70, 15, 15, 30, 80, 0, Habilidad::Habilidades_mago(), {}, Armadura::capa_basica(), Arma::Baston_basico());
}

Heroe* Heroe::Ladron() {
	return new Heroe("Ladron", 70, 70, 40, 20, 50, 60, 0, Habilidad::Habilidades_ladron(), {}, Armadura::peto_de_cuero(), Arma::Daga_basica());
}

Heroe* Heroe::Marginado() {
	return new Heroe("Marginado", 101, 100, 35, 35, 40, 20, 0, Habilidad::Habilidades_marginado(), {},  Armadura::Piel_de_oso(), Arma::Palo_desgastado());
}

// Fin constructores

// Setters

void Heroe::setArma(Arma* arma) {
	this->arma = arma;
}

void Heroe::setArmadura(Armadura* armadura) {
	this->armadura = armadura;
}

void Heroe::setHp(int nueva_hp) {
	this->hp = std::min(nueva_hp,hp_max);
}

void Heroe::setHpMax(int max) {
	this->hp_max = max;
}

void Heroe::setHpBase(int base) {
	this->hp_base = base;
}

void Heroe::setVivo(bool estado) {
	this->vivo = estado;
}

// Getters

int Heroe::getHpMax() {
	return this->hp_max;
}

int Heroe::getHp() {
	return this->hp;
}


int Heroe::getAtk() {
	int dano = this->atk  + this->arma->getAtk();
	return dano;
}

int Heroe::getDes() {
	return this->des;
}



int Heroe::getDef() {

	int trueDef = this->def;
	
	trueDef += armadura->getDef();

	for (Efecto e : this->efectos ) {
		trueDef += e.getdef();
	}
	 
	return trueDef;
}


// Funciones heroe

std::string Heroe::atacar(Entidad* enemigo) {
	
	std::string ans;

	if (this->getVivo()) 
	{
		int dano = getAtk() + this->arma->getAtk();
		

		enemigo->recibirAtaque(dano, this->arma->getEfecto());
		ans = this->name + " Ataco a " + enemigo->nameGetter() + " con " + this->arma->getName() + " y le hizo " + std::to_string(int(dano - (enemigo->defGetter() * 0.3)) ) + " de daño\n";

	}

	return ans;
}

std::string Heroe::atacarConHabilidad(Entidad* enemigo, int indx_habilidad) {
	
	std::string ans;

	if (this->getVivo()) 
	{
		int dano = getAtk() * habilidades[indx_habilidad].multGetter();
		

		enemigo->recibirAtaque(dano, this->habilidades[indx_habilidad].efectoGetter());
		ans = this->name + " Ataco a " + enemigo->nameGetter() + " con " + this->habilidades[indx_habilidad].nameGetter() + " y le hizo " + std::to_string(int(dano - (enemigo->defGetter() * 0.3)) ) + " de daño\n";

	}

	return ans;
}

std::string Heroe::recibirAtaque(int dano) {

	// def es un porcentaje -> dano - (dano * (def/100))
	// lck es un una probabilidad de que no se aplique el efecto


	std::string ans;
	int dano_total = dano -  ( this->getDef() * 0.2);
	if(this->hp - dano_total <= 0) {
		this->hp = 0;
		this->vivo = false;
		ans = this->name + " recibio " + std::to_string(dano_total) +" de daño y cayó muerto.\n";
	}
	
	else {

		this->hp -= dano_total;
		ans = this->name + " recibio " + std::to_string(dano_total) + " de daño.\n"; 

	}
	
	return ans;
}



std::string Heroe::recibirAtaqueHabilidad(int dano, Efecto posible_efecto) {
	
	// def es un porcentaje -> dano - (dano * (def/100))
	// lck es un una probabilidad de que no se aplique el efecto


	srand(time(nullptr));
	std::string ans;
	int dano_total = dano - (dano * (this->getDef()/100));
	if(this->hp - dano_total <= 0) {
		this->hp = 0;
		ans = this->name + " recibio " + std::to_string(dano_total) +" de daño y cayó muerto.\n";
	}
	
	else {
		int prob = 1 + rand() % 100;
		if (prob > lck) {
			this->efectos.push_back(posible_efecto);
			ans  = this->name + " recibio " + std::to_string(dano_total) + " de daño y se le aplicó" +  posible_efecto.getname() + "\n";
		}

		else {

			ans = this->name + " recibio " + std::to_string(dano_total) + " de daño.\n"; 

		}
	}

	return ans;

}

std::string Heroe::aplicarEfecto() {

	int dano_total = 0;
	std::string ans;
	std::vector<Efecto> efectos_validos;
	for (Efecto e : this->efectos) {
		if (e.getname() != "Nada" ) {
			efectos_validos.push_back(e);
		}
	}

	for (Efecto e : efectos_validos) {
		
		dano_total += e.gethp();
		ans = this->name + " recibio " + std::to_string(e.gethp()) + " por "  + e.getname() + "\n";

		if (this->hp + dano_total <= 0)
		{
			ans += this->name + " murio por " + e.getname() + "\n";
			break;
		}

	}

	return ans;

}

void Heroe::subirDeNivel(int nivel) {

	// Entonces por cada heroe -> Heroe.setHp( Heroe.getHp + (Heroe.getHp * (0.10 * nivel)) )
	 
	this->hp = this->hp + (this->hp * (0.10 * nivel));
	this->atk = this->atk + (nivel * 25);
	this->des = this->des + (nivel * 25); 
	this->lck = this->lck + (nivel * 2.5);
}

