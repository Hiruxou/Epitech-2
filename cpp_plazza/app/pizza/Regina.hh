//
// Regina.hh for plazza in /home/heitzl_s/rendu/cpp_plazza/app/pizza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 14:46:32 2015 Serge Heitzler
// Last update Fri Apr 24 19:00:22 2015 Nicolas Charvoz
//

#ifndef REGINA_HH_
# define REGINA_HH_

#include "APizza.hh"
#include "../ingredient/AIngredient.hh"

class   Regina : public APizza
{
public:
  Regina(APizza::TaillePizza);
  ~Regina();
  virtual const std::vector<AIngredient *>& getIngredients() const;
  virtual int getTime() const;
  virtual const std::string &getName() const;
  virtual APizza::TaillePizza getSize() const;
};

#endif /* !REGINA_HH_ */
