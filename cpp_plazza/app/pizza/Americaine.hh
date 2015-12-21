//
// Americaine.hh for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 14:53:21 2015 Serge Heitzler
// Last update Fri Apr 24 18:59:27 2015 Nicolas Charvoz
//

#ifndef AMERICAINE_HH_
# define AMERICAINE_HH_

#include "APizza.hh"
#include "../ingredient/AIngredient.hh"

class   Americaine : public APizza
{
public:
  Americaine(APizza::TaillePizza);
  ~Americaine();
  virtual const std::vector<AIngredient *>& getIngredients() const;
  virtual int getTime() const;
  virtual const std::string &getName() const;
  virtual APizza::TaillePizza getSize() const;
};

#endif /* !AMERICAINE_HH_ */
