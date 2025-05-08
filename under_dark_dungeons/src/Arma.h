#ifndef ARMA_H
#define ARMA_H 

#include <string>

class Arma {

	private:
		
		std::string name;
		std::string efecto;

		int atk_p;
	
	public:

		Arma(std::string name, std::string efecto, int atk);


	// Getters
	std::string getName() const;
	std::string getEfecto() const;
	int getAtk() const;
};

#endif
