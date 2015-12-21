//
// Ice.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:11:14 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:11:15 2015 Nicolas Charvoz
//

#include "Ice.hh"

Ice::Ice()
: AMateria("ice") {

}

Ice::Ice(Ice const & ice)
: AMateria("ice") {
	this->xp = ice.xp;
}

Ice::~Ice() {

}

AMateria * Ice::clone() const {
	return new Ice(*this);
}

void Ice::effect(ICharacter & target) {
	speak(std::string("* shoots an ice bolt at ") + target.getName() + " *");
}
