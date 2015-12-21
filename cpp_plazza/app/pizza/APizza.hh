//
// Pizza.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 17 11:14:59 2015 Nicolas Charvoz
// Last update Sat Apr 25 12:17:48 2015 Antoine Garcia
//

#ifndef PIZZA_HH_
# define PIZZA_HH_

#include <vector>
#include <string>
#include "../ingredient/AIngredient.hh"

class APizza {

public:
  typedef enum TaillePizza {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
  }TaillePizza;

  typedef enum TypePizza {
    Regina = 1,
    Margarita = 2,
    Americaine = 3,
    Fantasia = 8,
  }TypePizza;

  virtual ~APizza(){};
  virtual const std::vector<AIngredient *>& getIngredients() const = 0;
  virtual int getTime() const = 0;
  virtual const std::string &getName() const = 0;
  virtual APizza::TaillePizza getSize() const = 0;
protected:
  std::vector<AIngredient *>_ingredients;
  int	_time;
  std::string	_name;
  APizza::TaillePizza _size;
};

#endif
