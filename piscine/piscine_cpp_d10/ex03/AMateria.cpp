//
// AMateria.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:09:27 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:09:30 2015 Nicolas Charvoz
//

#include "AMateria.hh"

AMateria::AMateria(std::string const & type)
: xp(0), type(type) {

}

AMateria::~AMateria() {

}

unsigned int AMateria::getXP() const {
	return xp;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter & target) {
	xp += 10;
	effect(target);
}

void AMateria::effect(ICharacter& target) {
	(void) target;
}

void AMateria::speak(std::string message) {
	std::cout << message << std::endl;
}
