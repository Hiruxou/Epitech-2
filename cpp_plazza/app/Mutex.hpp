//
// Mutex.hpp for Mutex in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Thu Apr 16 02:59:29 2015 Antoine Garcia
// Last update Wed Dec  2 18:52:28 2015 Nicolas Charvoz
//

#include <pthread.h>

#ifndef MUTEX_HPP_
# define MUTEX_HPP_

class	Mutex
{
  pthread_mutex_t	_lock;
  bool			_is_locked;
public:
  Mutex()
  {
    _is_locked = false;
  }
  void init()
  {
    pthread_mutex_init(&_lock, NULL);
  }
  void lock()
  {
    pthread_mutex_lock(&_lock);
    _is_locked = true;
  }
  void unlock()
  {
    pthread_mutex_unlock(&_lock);
    _is_locked = false;
  }
  pthread_mutex_t	*getMutex()
  {
    return &_lock;
  }
};

#endif
