//
// Cure.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:10:56 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:10:57 2015 Nicolas Charvoz
//

#include "Cure.hh"

Cure::Cure()
: AMateria("cure") {

}

Cure::Cure(Cure const & cure)
: AMateria("cure") {
	this->xp = cure.xp;
}

Cure::~Cure() {

}

AMateria * Cure::clone() const {
	return new Cure(*this);
}

void Cure::effect(ICharacter & target) {
	speak(std::string("* heals ") + target.getName() + "'s wounds *");
}
