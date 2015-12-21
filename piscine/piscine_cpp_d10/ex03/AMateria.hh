//
// AMateria.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:09:40 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:15:52 2015 Nicolas Charvoz
//

#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include <iostream>

class AMateria;

#include "ICharacter.hh"

class AMateria {
protected:
	unsigned int xp;
	std::string type;

	void speak(std::string message);

public:
	AMateria(std::string const & type);
	virtual ~AMateria();

	std::string const & getType() const;
	unsigned int getXP() const;

	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter & target);
	virtual void effect(ICharacter & target);

};

#endif
