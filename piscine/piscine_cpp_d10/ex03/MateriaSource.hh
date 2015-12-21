//
// MateriaSource.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:12:21 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:12:22 2015 Nicolas Charvoz
//

#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include <string>
#include <iostream>

#include "AMateria.hh"
#include "IMateriaSource.hh"

class MateriaSource : public IMateriaSource {
protected:
	AMateria *slots[4];

public:
	MateriaSource();
	~MateriaSource();

	virtual void learnMateria(AMateria *materia);
	virtual AMateria * createMateria(std::string const & type);
};

#endif
