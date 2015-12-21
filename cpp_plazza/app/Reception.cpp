//
// Reception.cpp for Reception in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri Apr 24 03:30:29 2015 Antoine Garcia
// Last update Sun Apr 26 22:36:04 2015 Nicolas Charvoz
//

#include "Reception.hpp"

Reception::Reception(float tM, int cPK, int tR) : _timeMul(tM), _cooksPerKitchen(cPK),
					 _timeReplace(tR)
{
  _thread = new Thread(this);
}

void	*Reception::manageKitchens()
{
  std::cout << "ok" << std::endl;
  return NULL;
}

void	*Reception::backRun(void *Class)
{
  return ((Reception *)Class)->manageKitchens();
}

void	Reception::makePizzaList(Parser::t_pizza pizza)
{
  PizzaGenerator	gen;
  int	i = 0;

  while (i < pizza.num)
    {
      _pizzaList.push_back(gen.createForReception(pizza.name, pizza.size));
      i++;
    }
}

void Reception::run(std::list<Parser::t_pizza> list)
{
  for (std::list<Parser::t_pizza>::iterator it = list.begin() ; it != list.end() ; ++it)
    {
      if ((*it).status == 0)
	makePizzaList(*it);
    }
  for (std::vector<APizza *>::iterator it = _pizzaList.begin() ; it != _pizzaList.end() ; ++it)
    {
      sendOrder(*it);
    }
  _pizzaList.clear();
}

void	Reception::sendOrder(APizza *pizza)
{
  Mutex	mut;

  mut.init();
  mut.lock();
  for(std::vector<Kitchen *>::iterator it = _kitchenList.begin() ; it != _kitchenList.end() && pizza != NULL ; ++it)
    {
      if ((*it)->acceptPizza(*pizza))
	pizza = NULL;
    }
  mut.unlock();
  if (pizza != NULL)
    {
      Kitchen	*kitchen = new Kitchen(_cooksPerKitchen, _timeMul, _timeReplace);
      mut.lock();
      _kitchenList.push_back(kitchen);
      mut.unlock();
      if (kitchen->acceptPizza(*pizza))
	pizza = NULL;
    }
}
