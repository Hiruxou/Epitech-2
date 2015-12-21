//
// Fantasia.hh for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 14:52:22 2015 Serge Heitzler
// Last update Fri Apr 24 18:59:50 2015 Nicolas Charvoz
//

#ifndef FANTASIA_HH_
# define FANTASIA_HH_

#include "APizza.hh"
#include "../ingredient/AIngredient.hh"

class   Fantasia : public APizza
{
public:
  Fantasia(APizza::TaillePizza);
  ~Fantasia();
  virtual const std::vector<AIngredient *>& getIngredients() const;
  virtual int getTime() const;
  virtual const std::string &getName() const;
  virtual APizza::TaillePizza getSize() const;
};

#endif /* !FANTASIA_HH_ */
