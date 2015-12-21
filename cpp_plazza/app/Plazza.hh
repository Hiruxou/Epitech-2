//
// Plazza.hh for  in /home/nicolaschr/rendu/cpp_plazza
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Apr 15 15:09:34 2015 Nicolas Charvoz
// Last update Fri Apr 24 12:05:59 2015 Nicolas Charvoz
//

#ifndef PLAZZA_HH_
# define PLAZZA_HH_

# include <string>
# include <iostream>
# include "../core/MyWidget.hh"
# include "../core/MyApplication.hpp"
# include "Interface.hh"
# include "Exception.hpp"

class Plazza {

public:

  Plazza(int, char**);
  int run();

private:

  int _ac;
  float _timeMul;
  int _cooksPerKitchen;
  int _timeReplace;

};

#endif
