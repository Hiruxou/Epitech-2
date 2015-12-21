//
// Operand.tpp for Operand in /home/garcia_t/rendu/cpp_abstractvm
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Sat Feb 21 14:35:12 2015 antoine garcia
// Last update Fri Feb 27 12:25:39 2015 antoine garcia
//

#include <cstdlib>
#include <sstream>
#include "Exception.hpp"
#include "Operand.hpp"

static	t_operand	g_limitOperands[] =
  {
    {INT8, -127, 128, "INT8"},
    {INT16, -32768, 32767, "INT16"},
    {INT32, -2147483648, 2147483647, "INT32"},
    {FLOAT,-32768, 32767, "FLOAT"},
    {DOUBLE,-2147483648,2147483647, "DOUBLE"}
  };

template <typename T>
Operand<T>::Operand(eOperandType type, const double value):_type(type)
{
  if (value < g_limitOperands[type].min_size)
    {
      std::string error = "Underflow on " + g_limitOperands[type].type_str;
      throw myException(error);
      exit(-1);
    }
  if (value > g_limitOperands[type].max_size)
    {
      std::string error = "Overflow on " + g_limitOperands[type].type_str;
      throw myException(error);
      exit(-1);
    }
  _value = value;
  _precision = type;
}

template <typename T>
std::string const &Operand<T>::toString() const
{
  std::ostringstream	toString;
  std::string	*str = new std::string();

  if (_type == INT8)
    toString << (int)_value;
  else
    toString << _value;
  str->append(toString.str());
  return (*str);
}

template <typename T>
int	Operand<T>::getPrecision() const
{
  return (_precision);
}

template <typename T>
eOperandType	Operand<T>::getType() const
{
  return (_type);
}

template <typename T>
T		Operand<T>::getValue() const
{
  return (_value);
}
template<typename T>
eOperandType	Operand<T>::getBestType(eOperandType type) const
{
  eOperandType	bestType;

  bestType = _type;
  if (bestType < type)
    bestType = type;
  return (bestType);
}

template <typename T>
IOperand	*Operand<T>::operator+(const IOperand &rhs) const
{
  eOperandType type;
  double	res;

  type = getBestType(rhs.getType());
  res = _value + atof(rhs.toString().c_str());
  switch(type)
    {
    case INT8:
      return new Operand<char>(INT8, res);
    case INT16:
      return new Operand<short int>(INT16, res);
    case INT32:
      return new Operand<int>(INT32, res);
    case FLOAT:
      return new Operand<float>(FLOAT, res);
    case DOUBLE:
      return new Operand<double>(DOUBLE, res);
    default:
      return NULL;
    }
}

template<typename T>
IOperand	*Operand<T>::operator-(const IOperand &rhs) const
{
  eOperandType type;
  double	res;

  type = getBestType(rhs.getType());
  res = _value - atof(rhs.toString().c_str());
  switch(type)
    {
    case INT8:
      return new Operand<char>(INT8, res);
    case INT16:
      return new Operand<short int>(INT16, res);
    case INT32:
      return new Operand<int>(INT32, res);
    case FLOAT:
      return new Operand<float>(FLOAT, res);
    case DOUBLE:
      return new Operand<double>(DOUBLE, res);
    default:
      return NULL;
    }
}

template<typename T>
IOperand	*Operand<T>::operator*(const IOperand &rhs) const
{
  eOperandType type;
  double	res;

  type = getBestType(rhs.getType());
  res = _value * atof(rhs.toString().c_str());
  switch(type)
    {
    case INT8:
      return new Operand<char>(INT8, res);
    case INT16:
      return new Operand<short int>(INT16, res);
    case INT32:
      return new Operand<int>(INT32, res);
    case FLOAT:
      return new Operand<float>(FLOAT, res);
    case DOUBLE:
      return new Operand<double>(DOUBLE, res);
    default:
      return NULL;
    }
}

template<typename T>
IOperand	*Operand<T>::operator/(const IOperand &rhs) const
{
  eOperandType type;
  double	res;

  type = getBestType(rhs.getType());
  if (atof(rhs.toString().c_str()) == 0)
    throw myException("Math Exception : Division by zero forbidden");
  res = _value / atof(rhs.toString().c_str());
  switch(type)
    {
    case INT8:
      return new Operand<char>(INT8, res);
    case INT16:
      return new Operand<short int>(INT16, res);
    case INT32:
      return new Operand<int>(INT32, res);
    case FLOAT:
      return new Operand<float>(FLOAT, res);
    case DOUBLE:
      return new Operand<double>(DOUBLE, res);
    default:
      return NULL;
    }
}

template<typename T>
IOperand	*Operand<T>::operator%(const IOperand &rhs) const
{
  eOperandType	type;
  double	res;

  type = getBestType(rhs.getType());
  if (atof(rhs.toString().c_str()) == 0)
    throw myException("Math Exception : Modulo by zero is forbidden");
  res = (long)_value % atoi(rhs.toString().c_str());
  switch (type)
    {
    case INT8:
      return new Operand<char>(INT8, res);
    case INT16:
      return new Operand<short int>(INT16, res);
    case INT32:
      return new Operand<int>(INT32, res);
    case FLOAT:
      return new Operand<float>(FLOAT, res);
    case DOUBLE:
      return new Operand<double>(DOUBLE, res);
    default:
      return NULL;
    }
}
