//
// Steak.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:13:41 2015 Serge Heitzler
// Last update Sat Apr 25 12:26:12 2015 Antoine Garcia
//

#ifndef STEAK_HH_
# define STEAK_HH_

# include "AIngredient.hh"

class		Steak : public AIngredient
{
public:
  Steak(int nbItems = 5);
  ~Steak();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !STEAK_HH_ */
