//
// Exec.cpp for Exec in /home/garcia_t/rendu/cpp_abstractvm
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Feb 21 14:06:39 2015 antoine garcia
// Last update Tue Mar  3 15:57:14 2015 Nicolas Charvoz
//

#include "Exception.hpp"
#include "Exec.hh"

Exec::Exec()
{
  functions["pop"] = &Calculator::pop;
  functions["add"] = &Calculator::add;
  functions["sub"] = &Calculator::sub;
  functions["mod"] = &Calculator::mod;
  functions["mul"] = &Calculator::mul;
  functions["div"] = &Calculator::div;
  functions["dump"] = &Calculator::dump;
  functions["print"] = &Calculator::print;
}

void	Exec::execute(std::list<Parser::t_parse>parse)
{
  Calculator	calculator;

  for (std::list<Parser::t_parse>::const_iterator iterator = parse.begin(), end = parse.end(); iterator != end; ++iterator) {
    try{
    if (iterator->cmd == "push")
      calculator.push(iterator->value);
    else if (iterator->cmd == "assert")
      calculator.assert(iterator->value);
    else
      {
	if (iterator->cmd != "exit")
	  {
	    _ptr = functions[iterator->cmd];
	    (calculator.*_ptr)();
	  }
      }
    }catch(myException &caught){
      std::cerr << caught.what() << std::endl;
      exit(0);
    }
  }
}
