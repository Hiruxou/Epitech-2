/*
** Calculator.h for Calculator in /home/garcia_t/rendu/cpp_abstractvm
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Thu Feb 19 14:00:10 2015 antoine garcia
// Last update Sat Feb 21 15:36:38 2015 antoine garcia
*/

#ifndef _CALCULATOR_HH_
# define _CALCULATOR_HH_

#include <stack>
#include "Operand.hpp"

class	Calculator
{
  typedef IOperand *(Calculator::*funcPtr)(const std::string &);
  funcPtr	_funcs[5];
  std::stack<IOperand *>_operands;

  IOperand	*createInt8(const std::string &value);
  IOperand	*createInt16(const std::string &value);
  IOperand	*createInt32(const std::string &value);
  IOperand	*createFloat(const std::string &value);
  IOperand	*createDouble(const std::string &value);
public:
  IOperand	*createOperand(eOperandType type, const std::string &value);
  void		pop();
  void		push(IOperand *);
  void		add();
  void		sub();
  void		mul();
  void		div();
  void		mod();
  void		dump();
  void		assert(IOperand *);
  void		print();
public:
  Calculator();
  ~Calculator(){};
};

#endif
