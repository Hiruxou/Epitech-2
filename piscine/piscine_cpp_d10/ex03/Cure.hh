//
// Cure.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:11:03 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:11:05 2015 Nicolas Charvoz
//

#ifndef __CURE_H__
#define __CURE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "ICharacter.hh"

class Cure : public AMateria {
protected:

public:
	Cure();
	Cure(Cure const & cure);
	~Cure();

	virtual AMateria * clone() const;
	virtual void effect(ICharacter & target);

};

#endif
