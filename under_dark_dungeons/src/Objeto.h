#ifndef OBJETO_H
#define OBJETO_H

#include <string>

class Objeto {

	private:
		
		std::string name;


	public:

		Objeto(std::string name);
		
		std::string getName();

};


#endif
