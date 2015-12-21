//
// Goatcheese.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:14:01 2015 Serge Heitzler
// Last update Sat Apr 25 12:22:47 2015 Antoine Garcia
//

#ifndef GOATCHEESE_HH_
# define GOATCHEESE_HH_

# include "AIngredient.hh"

class		Goatcheese : public AIngredient
{
public:
  Goatcheese(int nbItems = 5);
  ~Goatcheese();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !GOATCHEESE_HH_ */
