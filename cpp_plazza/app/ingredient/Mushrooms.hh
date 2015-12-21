//
// Mushrooms.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:15:43 2015 Serge Heitzler
// Last update Sat Apr 25 12:25:35 2015 Antoine Garcia
//

#ifndef MUSHROOMS_HH_
# define MUSHROOMS_HH_

# include "AIngredient.hh"

class		Mushrooms : public AIngredient
{
public:
  Mushrooms(int nbItems = 5);
  ~Mushrooms();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !MUSHROOMS_HH_ */
