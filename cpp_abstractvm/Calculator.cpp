//
// Calculator.cpp for Calculator in /home/garcia_t/rendu/cpp_abstractvm
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Thu Feb 19 14:00:15 2015 antoine garcia
// Last update Tue Mar  3 15:59:38 2015 Nicolas Charvoz
//

#include <cstdlib>
#include <sstream>
#include "Exception.hpp"
#include "Calculator.hh"

Calculator::Calculator()
{
  _funcs[0] = &Calculator::createInt8;
  _funcs[1] = &Calculator::createInt16;
  _funcs[2] = &Calculator::createInt32;
  _funcs[3] = &Calculator::createFloat;
  _funcs[4] = &Calculator::createDouble;
}

IOperand	*Calculator::createInt8(const std::string &value)
{
  try
    {
      if (value.find(".") != std::string::npos)
	throw myException("Cannot create this value for a Int");
      return (new Operand<char>(INT8, atof(value.c_str())));
    }catch(myException &caught)
    {
      std::cout << caught.what() << std::endl;
      exit(-1);
    }
}

IOperand	*Calculator::createInt16(const std::string &value)
{
  try
    {
      if (value.find(".") != std::string::npos)
	throw myException("Cannot create this value for a Int");
       return (new Operand<short int>(INT16, atof(value.c_str())));
    }catch(myException &caught)
    {
      std::cout << caught.what() << std::endl;
      exit(-1);
    }
}

IOperand	*Calculator::createInt32(const std::string &value)
{
  try
    {
      if (value.find(".") != std::string::npos)
	throw myException("Cannot create this value for a Int");
      return (new Operand<int>(INT32, atof(value.c_str())));
    }catch(myException &caught)
    {
      std::cout << caught.what() << std::endl;
      exit(-1);
    }
}

IOperand	*Calculator::createFloat(const std::string &value)
{
  return (new Operand<float>(FLOAT, atof(value.c_str())));
}

IOperand	*Calculator::createDouble(const std::string &value)
{
  return (new Operand<double>(DOUBLE, atof(value.c_str())));
}

IOperand	*Calculator::createOperand(eOperandType type, const std::string &value)
{
  return ((this->*_funcs[type])(value));
}

void		Calculator::pop()
{
  if (_operands.size() == 0)
    throw myException("Error: Stack is empty !");
  _operands.pop();
}

void		Calculator::push(IOperand *op)
{
  _operands.push(op);
}

void		Calculator::add()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_operands.size() < 2)
    throw myException ("Less than 2 values in the stack !");
  nb1 = _operands.top();
  pop();
  nb2 = _operands.top();
  pop();
  push(*nb1 + *nb2);
}

void		Calculator::sub()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_operands.size() < 2)
    throw myException ("Less than 2 values in the stack !");
  nb1 = _operands.top();
  pop();
  nb2 = _operands.top();
  pop();
  push(*nb1 - *nb2);
}

void		Calculator::mul()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_operands.size() < 2)
    throw myException ("Less than 2 values in the stack !");
  nb1 = _operands.top();
  pop();
  nb2 = _operands.top();
  pop();
  push(*nb1 * *nb2);
}

void		Calculator::div()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_operands.size() < 2)
    throw myException ("Less than 2 values in the stack !");
  nb1 = _operands.top();
  pop();
  nb2 = _operands.top();
  pop();
  push(*nb1 / *nb2);
}

void		Calculator::mod()
{
  IOperand	*nb1;
  IOperand	*nb2;

  if (_operands.size() < 2)
    throw myException ("Less than 2 values in the stack !");
  nb1 = _operands.top();
  pop();
  nb2 = _operands.top();
  pop();
  push(*nb1 % *nb2);
}

void		Calculator::dump()
{
  std::stack<IOperand *>copy;
  int	i;

  copy = _operands;
  i = copy.size();
  while (i > 0)
    {
      std::cout << copy.top()->toString() << std::endl;
      copy.pop();
      i--;
    }
}

void		Calculator::assert(IOperand *op)
{
  if (_operands.size() < 1)
    {
      throw myException("Assert is not verified");
      exit (-1);
    }
  if (_operands.top()->toString() != op->toString())
    {
      throw myException("Assert is not verified");
      exit (-1);
    }
    }

void		Calculator::print()
{
  char	letter;
  double	value;
  std::istringstream	string;

  if (_operands.top()->getPrecision() == INT8)
    {
      string.str(_operands.top()->toString());
      string >> value;
      letter = value;
      std::cout << letter << std::endl;
    }
  else
    throw myException("Cannot print this value");
}
