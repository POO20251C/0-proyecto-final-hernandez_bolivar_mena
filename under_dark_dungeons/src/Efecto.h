#ifndef EFECTO_H
#define EFECTO_H

#include <string>
class Efecto {

	private:

		std::string name;

		int mult_hp;
		int mult_def;
		int mult_vel;
		int mult_lck;

	public:

		Efecto(std::string name, int hp, int def, int vel, int lck);


};

#endif
