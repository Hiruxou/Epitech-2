//
// Condvar.hpp for Condvar in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri Apr 17 03:35:19 2015 Antoine Garcia
// Last update Sat Apr 25 13:45:13 2015 Antoine Garcia
//

#ifndef CONDVAR_HPP_
#define CONDVAR_HPP_

#include "Mutex.hpp"

class Condvar
{
  pthread_cond_t m_cond_var;
  Mutex	_mut;
public:
  Condvar()
  {
    _mut.init();
    pthread_cond_init(&m_cond_var, NULL);
  }
  ~Condvar()
  {
    pthread_cond_destroy(&m_cond_var);
  }
  void wait()
  {
    _mut.lock();
    pthread_cond_wait(&m_cond_var, _mut.getMutex());
    _mut.unlock();
  }
  void signal()
  {
    pthread_cond_signal(&m_cond_var);
  }
  void broadcast()
  {
    pthread_cond_broadcast(&m_cond_var);
  }
};

#endif
