//
// Cook.cpp for Cook in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Sat Apr 18 11:32:50 2015 Antoine Garcia
// Last update Sun Apr 26 14:38:08 2015 Antoine Garcia
//

#include "Thread.hpp"
#include "Cook.hh"
#include <iostream>

Cook::Cook(float mult, Kitchen  *cond, Mutex &mut, Mutex &cook_mutex):_mult(mult)
{
  _kit = cond;
  _mut = mut;
  _cook_mutex = cook_mutex;
  _thread = new Thread(this);
  _stop = false;
  _pizzaWork = NULL;
}

Cook::~Cook()
{}

void	*Cook::run()
{
  while (!_stop)
    {
      _mut.lock();
      if (_kit->_pizzaList.size() != 0 && _pizzaWork == NULL)
	{
	  _cook_mutex.lock();
	  _pizzaWork = _kit->_pizzaList.front();
	  _kit->_pizzaList.erase(_kit->_pizzaList.begin());
	  _mut.unlock();
	  _cook_mutex.unlock();
	  CookPizza();
	}
      _mut.unlock();
      sleep(1);
    }
  return NULL;
}

void	Cook::CookPizza()
{
  Serializer	serial;
  int	time;

  std::cout << "I COOK" << std::endl;
  time = _pizzaWork->getTime();
  sleep(time * _mult);
  std::cout << "Finish To Cook : " << serial.pack(*_pizzaWork) << std::endl;
  _cook_mutex.lock();
  _pizzaWork = NULL;
  _cook_mutex.unlock();
}

void	*Cook::backRun(void *Class)
{
  return ((Cook *)Class)->run();
}

bool	Cook::getStatus() const
{
  if (_pizzaWork == NULL)
    return true;
  return false;
}
