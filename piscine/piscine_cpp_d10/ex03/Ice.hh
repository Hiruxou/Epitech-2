//
// Ice.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:11:22 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:11:24 2015 Nicolas Charvoz
//

#ifndef __ICE_H__
#define __ICE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "ICharacter.hh"

class Ice : public AMateria {
protected:

public:
	Ice();
	Ice(Ice const & ice);
	~Ice();

	virtual AMateria * clone() const;
	virtual void effect(ICharacter & target);

};

#endif
