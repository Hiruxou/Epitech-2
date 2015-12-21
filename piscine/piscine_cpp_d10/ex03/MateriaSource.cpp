//
// MateriaSource.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d10/ex03
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Jan 16 17:12:12 2015 Nicolas Charvoz
// Last update Fri Jan 16 17:12:13 2015 Nicolas Charvoz
//

#include "MateriaSource.hh"

MateriaSource::MateriaSource() {
	int i;
	for(i = 0; i < 4; i++) {
		slots[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	int i;
	for(i = 0; i < 4; i++) {
		if (slots[i]) {
			delete slots[i];
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (materia) {
		int i;
		for (i = 0; i < 4; i++) {
			if (!slots[i]) {
				slots[i] = materia;
				return;
			}
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	int i;
	for (i = 0; i < 4; i++) {
		if (slots[i] && slots[i]->getType() == type) {
			return slots[i]->clone();
		}
	}
	return NULL;
}
