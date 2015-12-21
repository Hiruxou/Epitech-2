//
// MainClass.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr 18 10:14:13 2015 Nicolas Charvoz
// Last update Fri Apr 24 12:17:14 2015 Nicolas Charvoz
//

#ifndef MAINCLASS_HH_
# define MAINCLASS_HH_

#include "Plazza.hh"
#include "Parser.hpp"
#include "Reception.hpp"

class MainClass {

public:
  MainClass(float timeMul = 0, int cooksPerKitchen = 0,
	    int timeReaplce = 0, std::string const &order = "",
	    Reception *r = 0);
  int main();


private:
  float _timeMul;
  int _cooksPerKitchen;
  int _timeReplace;
  std::string _order;
  Reception *_r;
};

#endif
