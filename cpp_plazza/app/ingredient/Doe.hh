//
// Doe.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:14:11 2015 Serge Heitzler
// Last update Sat Apr 25 12:20:52 2015 Antoine Garcia
//

#ifndef DOE_HH_
# define DOE_HH_

# include "AIngredient.hh"

class		Doe : public AIngredient
{
public:
  Doe(int nbItems = 5);
  ~Doe();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !DOE_HH_ */
