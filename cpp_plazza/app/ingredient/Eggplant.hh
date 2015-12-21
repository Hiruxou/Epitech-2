//
// Eggplant.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:15:27 2015 Serge Heitzler
// Last update Sat Apr 25 12:21:59 2015 Antoine Garcia
//

#ifndef EGGPLANT_HH_
# define EGGPLANT_HH_

# include "AIngredient.hh"

class		Eggplant : public AIngredient
{
public:
  Eggplant(int nbItems = 5);
  ~Eggplant();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !EGGPLANT_HH_ */
