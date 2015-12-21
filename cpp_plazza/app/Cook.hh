//
// Cook.hh for Cook in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 10:17:32 2015 Antoine Garcia
// Last update Sun Apr 26 08:48:36 2015 Antoine Garcia
//

#ifndef COOK_H_
# define COOK_H_

#include <vector>
#include "Condvar.hpp"
#include "pizza/APizza.hh"
#include "IBrun.hh"
#include "Mutex.hpp"
#include "Thread.hpp"
#include "Kitchen.hh"
#include "Serializer.hpp"

class	Kitchen;
class	Cook : IBrun
{
  Thread	*_thread;
  APizza *_pizzaWork;
  int	_mult;
  Mutex		_mut;
  Mutex		_cook_mutex;
  bool	_stop;
  Kitchen	*_kit;
  void		CookPizza();
public:
  Cook(float mul, Kitchen  *cond, Mutex &mut, Mutex &cook_mutex);
  ~Cook();
  virtual void *backRun(void *Class);
  void	*run();
  bool	getStatus() const;
};

#endif
