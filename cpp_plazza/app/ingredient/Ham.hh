//
// Ham.hh for plazza in /home/heitzl_s/rendu/cpp_plazza
//
// Made by Serge Heitzler
// Login   <heitzl_s@epitech.net>
//
// Started on  Thu Apr 23 15:13:48 2015 Serge Heitzler
// Last update Sat Apr 25 12:24:58 2015 Antoine Garcia
//

#ifndef HAM_HH_
# define HAM_HH_

# include "AIngredient.hh"

class		Ham : public AIngredient
{
public:
  Ham(int nbItems = 5);
  ~Ham();
  int		getNbItems() const;
  void		addItem();
  void		takeItem();
  AIngredient::Ingredients	getType() const;
};

#endif /* !HAM_HH_ */
