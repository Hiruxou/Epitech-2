//
// Gruyere.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:15:36 2015 Serge Heitzler
// Last update Sat Apr 25 12:24:00 2015 Antoine Garcia
//

#ifndef GRUYERE_HH_
# define GRUYERE_HH_

# include "AIngredient.hh"

class		Gruyere : public AIngredient
{
public:
  Gruyere(int nbItems = 5);
  ~Gruyere();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !GRUYERE_HH_ */
