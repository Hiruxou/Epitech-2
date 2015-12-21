//
// IMateriaSource.hh for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:11:47 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:15:02 2015 Nicolas Charvoz
//

#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include <string>
#include "AMateria.hh"

class IMateriaSource {
protected:

public:
	virtual ~IMateriaSource() {}

	virtual void learnMateria(AMateria *materia) = 0;
	virtual AMateria * createMateria(std::string const & type) = 0;

};

#endif
