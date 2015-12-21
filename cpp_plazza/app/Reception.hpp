//
// Reception.hpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 24 12:04:25 2015 Nicolas Charvoz
// Last update Fri Apr 24 08:45:57 2015 Antoine Garcia
//

#ifndef RECEPTION_HPP_
# define RECEPTION_HPP_

#include <iostream>
#include "IBrun.hh"
#include "Thread.hpp"
#include "Parser.hpp"
#include "pizza/APizza.hh"
#include "pizza/PizzaGenerator.hh"
#include "Kitchen.hh"
#include "Mutex.hpp"

class Reception : public IBrun
{
private:
  Thread	*_thread;
  float _timeMul;
  int _cooksPerKitchen;
  int _timeReplace;
  std::vector<APizza *> _pizzaList;
  std::vector <Kitchen *>_kitchenList;
  void	*manageKitchens();
  void	makePizzaList(Parser::t_pizza pizza);
  void	sendOrder(APizza *);
public:
  Reception(float tM, int cPK, int tR);
  void run(std::list<Parser::t_pizza>);
  void	*backRun(void *Class);
};

#endif
