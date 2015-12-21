//
// Character.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:10:46 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:10:48 2015 Nicolas Charvoz
//

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>
#include <iostream>

#include "ICharacter.hh"
#include "AMateria.hh"

class Character : public ICharacter {
protected:
	AMateria *slots[4];
	std::string name;

public:
	Character(std::string const & name);
	Character(Character const & perso);
	~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria * materia);
	virtual void unequip(int index);
	virtual void use(int index, ICharacter & target);
};

#endif
