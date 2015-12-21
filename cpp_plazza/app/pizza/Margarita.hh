//
// Margarita.hh for Margarita in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 04:39:21 2015 Antoine Garcia
// Last update Fri Apr 24 18:59:59 2015 Nicolas Charvoz
//

#ifndef MARGARITA_HH_
# define MARGARITA_HH_

#include "APizza.hh"
#include "../ingredient/AIngredient.hh"

class	Margarita : public APizza
{
public:
  Margarita(APizza::TaillePizza);
  ~Margarita();
  virtual const std::vector<AIngredient *>& getIngredients() const;
  virtual int getTime() const;
  virtual const std::string &getName() const;
  virtual APizza::TaillePizza getSize() const;
};

#endif /* MARGARITA_HH_ */
