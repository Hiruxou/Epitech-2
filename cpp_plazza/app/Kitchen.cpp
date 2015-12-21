//
// Kitchen.cpp for Kitchen in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Thu Apr 23 05:58:02 2015 Antoine Garcia
// Last update Sun Apr 26 09:16:02 2015 Antoine Garcia
//

#include <iostream>
#include "Kitchen.hh"

Kitchen::Kitchen(int nb_cooks, float mult, int time_ing):_nb_cooks(nb_cooks), _mult(mult), _time_ing(time_ing)
{
  int	i = 0;
  _pipe = new PipeClass();
  _fork = new Fork();
  if (_fork->isSon())
    {
      _pipe->setSon(true);
      _run = true;
      _cond = new Condvar();
      _stock.push_back(new Tomato(5));
      _stock.push_back(new Doe(5));
      _stock.push_back(new Steak(5));
      _stock.push_back(new Chieflove(5));
      _stock.push_back(new Gruyere(5));
      _stock.push_back(new Ham(5));
      _stock.push_back(new Eggplant(5));
      _stock.push_back(new Goatcheese(5));
      _stock.push_back(new Mushrooms(5));
      cook_mutex.init();
      ingr_mutex.init();
      list_mutex.init();
      while (i < _nb_cooks)
	{
	  _cooks.push_back(new Cook(mult, this, list_mutex, cook_mutex));
	  i++;
	}
      _thread = new Thread(this);
      std::cout << "New Kitchen" << std::endl;
      run();
    }
  else
    _pipe->setSon(false);
}

void	*Kitchen::checkIngredients()
{
  ingrIt	it;
  void		*s = NULL;

  while (_run)
    {
      usleep(_time_ing);
      ingr_mutex.lock();
      for(it = _stock.begin(); it != _stock.end() ; ++it)
	(*it)->addItem();
      ingr_mutex.unlock();
    }
  return s;
}

void	*Kitchen::backRun(void *Class)
{
  return ((Kitchen *)Class)->checkIngredients();
}

bool	Kitchen::acceptPizza(APizza &pizza)
{
  Serializer	serial;
  std::string	pizzaString;
  std::string	rep;

  pizzaString = serial.pack(pizza);
  _pipe->write(pizzaString);
  rep = _pipe->read();
  if (rep.compare("KO") == 0)
    return false;
  return true;
}

void	Kitchen::run()
{
  std::string	order;
  std::map<std::string, void (Kitchen::*)()>cmd;

  cmd["PIZZA"] = &Kitchen::doPizza;

  while (_run)
    {
      order = _pipe->read();
      if (cmd.find(order) != cmd.end())
	(this->*cmd[order])();
    }
}

void	Kitchen::doPizza()
{
  PizzaGenerator	gen;
  std::string	order;
  APizza	*pizza;
  std::vector<AIngredient *>pizzaIngr;
  bool	check;

  std::cout << "I do the pizza" << std::endl;
  order = _pipe->getline();
  pizza = gen.createForKitchen(order);
  pizzaIngr = pizza->getIngredients();
  if ((check = checkIngredients(pizzaIngr)) == false)
    {
      _pipe->write("KO");
      return;
    }
  else if (checkCooks() + _pizzaList.size() <= (unsigned int)(2 * _nb_cooks))
    {
      removeIngredientsFromStock(pizzaIngr);
      list_mutex.lock();
      _pizzaList.push_back(pizza);
      list_mutex.unlock();
      _pipe->write("OK");
    }
  else
    _pipe->write("KO");
}

void	Kitchen::removeIngredientsFromStock(std::vector<AIngredient *>  &pizzaIngr)
{
  ingr_mutex.lock();
    for (ingrIt it = _stock.begin() ; it != _stock.end() ; ++it)
      {
	for (ingrIt it2 = pizzaIngr.begin() ; it2 != pizzaIngr.end() ; ++it2)
	  {
	    if ((*it)->getType() == (*it2)->getType())
	      (*it)->takeItem();
	  }
      }
  ingr_mutex.unlock();
}

bool	Kitchen::checkIngredients(std::vector<AIngredient *> &pizzaIngr)
{
  ingr_mutex.lock();
  for (ingrIt it = _stock.begin() ; it != _stock.end() ; ++it)
    {
      for (ingrIt it2 = pizzaIngr.begin() ; it2 != pizzaIngr.end() ; ++it2)
	{
	  if ((*it)->getType() == (*it2)->getType())
	    {
	      if ((*it)->getNbItems() <= 0)
		{
		  ingr_mutex.unlock();
		  return false;
		}
	    }
	}
    }
  ingr_mutex.unlock();
  return true;
}

int	Kitchen::checkCooks()
{
  int	nb = 0;

  cook_mutex.lock();
  for(cooksIt it = _cooks.begin() ; it != _cooks.end() ; ++it)
    {
      if ((*it)->getStatus() == false)
	nb++;
    }
  cook_mutex.unlock();
  return nb;
}
