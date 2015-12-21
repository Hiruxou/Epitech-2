//
// Kitchen.hh for Kitchen in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Tue Apr 21 10:16:33 2015 Antoine Garcia
// Last update Sun Apr 26 05:28:10 2015 Antoine Garcia
//

#ifndef KITCHEN_HH_
# define KITCHEN_HH_

#include <map>
#include <string>
#include <vector>
#include "IBrun.hh"
#include "ingredient/AIngredient.hh"
#include "ingredient/AllIngredient.hh"
#include "pizza/APizza.hh"
#include "pizza/PizzaGenerator.hh"
#include "Cook.hh"
#include "Mutex.hpp"
#include "Thread.hpp"
#include "Fork.hpp"
#include "Condvar.hpp"
#include "PipeClass.hpp"
#include "Serializer.hpp"

class	Cook;
class	Kitchen : public IBrun
{
  Fork	*_fork;
  Thread	*_thread;
  PipeClass	*_pipe;
  Mutex	cook_mutex;
  Mutex	ingr_mutex;
  Mutex	list_mutex;
  Condvar	*_cond;
  int	_nb_cooks;
  float	_mult;
  int	_time_ing;
  bool	_run;
  std::vector<Cook *> _cooks;
  std::vector<AIngredient *> _stock;

  typedef std::vector<Cook *>::iterator cooksIt;
  typedef std::vector <AIngredient *>::iterator ingrIt;
  void	*checkIngredients();
  void	run();
  void	doPizza();
  bool	checkIngredients(std::vector<AIngredient *>  &pizzaIngr);
  int	checkCooks();
  void	removeIngredientsFromStock(std::vector<AIngredient *>  &pizzaIngr);
public:
  std::vector<APizza *>_pizzaList;
  Kitchen(int nb_cooks, float mult, int time_ing);
  virtual void *backRun(void *Class);
  bool	acceptPizza(APizza &);
};

#endif
