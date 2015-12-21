//
// Tomato.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:13:36 2015 Serge Heitzler
// Last update Sat Apr 25 12:26:40 2015 Antoine Garcia
//

#ifndef TOMATO_HH_
# define TOMATO_HH_

# include "AIngredient.hh"

class		Tomato : public AIngredient
{
public:
  Tomato(int nbItems = 5);
  ~Tomato();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !TOMATO_HH_ */
