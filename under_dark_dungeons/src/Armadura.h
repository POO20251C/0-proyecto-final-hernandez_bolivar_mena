#ifndef ARMADURA_H
#define ARMADURA_H

#include <string>
#include <vector>

#include "Efecto.h"

class Armadura {

	private:

		std::string name;

		int def_p;
		int vel_n;

		std::vector<Efecto> invulnerable;

	public:

		Armadura(std::string name, int def_p, int vel_n, std::vector<Efecto> inv);

};

#endif
