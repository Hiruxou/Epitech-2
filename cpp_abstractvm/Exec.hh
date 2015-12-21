//
// Exec.hh for Exec in /home/garcia_t/rendu/cpp_abstractvm
// 
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
// 
// Started on  Sat Feb 21 14:04:01 2015 antoine garcia
// Last update Fri Feb 27 15:15:25 2015 antoine garcia
//

#ifndef _EXEC_HH_
# define _EXEC_HH_

#include <map>
#include "IOperand.hpp"
#include "Parser.hpp"
#include "Calculator.hh"

class	Exec
{
  typedef void(Calculator::*funcs)();
  funcs	_ptr;
  typedef std::map<std::string, funcs>map_funcs;
  map_funcs	functions;
public:
  Exec();
  void execute(std::list<Parser::t_parse>);
};

#endif
