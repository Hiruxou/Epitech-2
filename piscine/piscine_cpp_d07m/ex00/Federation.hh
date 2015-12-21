//
// Federation.hh for  in /home/nicolaschr/rendu/piscine_cpp_d07m/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 13 09:25:25 2015 Nicolas Charvoz
// Last update Tue Jan 13 11:49:24 2015 Nicolas Charvoz
//

#ifndef FEDERATION_HH_
#define FEDERATION_HH_

#include <iostream>
#include <string>
#include "Warpsystem.hh"

namespace Federation {
  class Ship
  {
  private:
    int _length;
    int _width;
    std::string _name;
    short _maxWarp;
    WarpSystem::Core *Core;
  public:
    Ship(int, int, std::string);
    ~Ship();
    void setupCore(WarpSystem::Core*);
    void checkCore();
  };
  namespace Starfleet {
    class Ship
    {
    private:
      int _length;
      int _width;
      std::string _name;
      short _maxWarp;
      WarpSystem::Core *Core;
    public:
      Ship(int, int, std::string, short);
      ~Ship();
      void setupCore(WarpSystem::Core*);
      void checkCore();
    };
  };
};

#endif
