//
// Chieflove.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:15:10 2015 Serge Heitzler
// Last update Sat Apr 25 12:27:17 2015 Antoine Garcia
//

#ifndef CHIEFLOVE_HH_
# define CHIEFLOVE_HH_

# include "AIngredient.hh"

class		Chieflove : public AIngredient
{
public:
  Chieflove(int nbItems = 5);
  ~Chieflove();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !DOE_HH_ */
