//
// Reception.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Apr 15 16:02:50 2015 Nicolas Charvoz
// Last update Fri Apr 24 12:15:21 2015 Nicolas Charvoz
//

#ifndef INTERFACE_HH_
# define INTERFACE_HH_

# include "Plazza.hh"
# include "Reception.hpp"

class Interface {

public:

  Interface(float, int, int);
  int showUI();

  private:
  float _timeMul;
  int _cooksPerKitchen;
  int _timeReplace;
};

#endif
