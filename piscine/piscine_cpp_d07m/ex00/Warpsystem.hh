//
// Warpsystem.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:38:21 2015 Nicolas Charvoz
// Last update Tue Jan 13 10:18:28 2015 Nicolas Charvoz
//

#ifndef WARPSYSTEM_HH_
#define WARPSYSTEM_HH_

#include <string>
#include <iostream>

namespace WarpSystem {
  class QuantumReactor
  {
  private:
    bool _stability;
  public:
    QuantumReactor(bool stability = true);
    ~QuantumReactor();
    bool isStable();
    void setStability(bool);
  };
  class Core {
  public:
    Core(QuantumReactor*);
    ~Core();
    QuantumReactor *checkReactor();

  private:
    QuantumReactor *_coreReactor;
  };
};

#endif
