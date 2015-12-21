//
// MainClass.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr 18 10:15:58 2015 Nicolas Charvoz
// Last update Sun Apr 26 22:46:29 2015 Nicolas Charvoz
//

#include "MainClass.hh"

MainClass::MainClass(float timeMul, int cooksPerKitchen,
		     int timeReplace, std::string const &order,
		     Reception *r)
  : _timeMul(timeMul), _cooksPerKitchen(cooksPerKitchen),
    _timeReplace(timeReplace), _order(order), _r(r)
{
}

int MainClass::main()
{
  if (_timeMul <= 0.0 || _cooksPerKitchen <= 0 || _timeReplace <= 0)
    throw Exception("You must enter 3 valid arguments");
  Parser parser(_order);
  parser.parseOrder();
   _r->run(parser.getFinalList());
  return 0;
}
