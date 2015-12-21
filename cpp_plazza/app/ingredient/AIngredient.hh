//
// AIngredient.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:14:27 2015 Serge Heitzler
// Last update Sat Apr 25 12:28:39 2015 Antoine Garcia
//

#ifndef INGREDIENT_HH_
# define INGREDIENT_HH_

class		AIngredient
{
public:
  typedef enum Ingredients {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOATCHEESE,
    CHIEFLOVE
  }Ingredients;
  virtual	~AIngredient(){};
  virtual int	getNbItems() const = 0;
  virtual void	addItem() = 0;
  virtual void	takeItem() = 0;
  virtual AIngredient::Ingredients getType() const = 0;
protected:
  int		_nbItems;
  AIngredient::Ingredients _type;
};

#endif /* !INGREDIENT_HH_ */
