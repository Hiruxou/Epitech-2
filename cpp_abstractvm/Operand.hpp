//
// Operand.hpp for Operand in /home/garcia_t/rendu/cpp_abstractvm
// 
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
// 
// Started on  Thu Feb 12 10:16:56 2015 antoine garcia
// Last update Fri Feb 27 12:19:44 2015 antoine garcia
//

#ifndef _OPERAND_HPP_
# define _OPERAND_HPP_

# include "IOperand.hpp"

typedef struct	s_operand
  {
    eOperandType	type;
    long		min_size;
    long       		max_size;
    const std::string	&type_str;
  }			t_operand;

template<typename T>
class	Operand : public IOperand
{
  eOperandType _type;
  int	       _precision;
  T		_value;
  eOperandType	getBestType(eOperandType type) const;
public:
  explicit Operand(eOperandType type, const double value);
  virtual std::string const &toString() const;
  virtual int getPrecision() const;
  virtual eOperandType getType() const;
  virtual IOperand	*operator+(const IOperand &rhs) const;
  virtual IOperand	*operator-(const IOperand &rhs) const;
  virtual IOperand	*operator*(const IOperand &rhs) const;
  virtual IOperand	*operator/(const IOperand &rhs) const;
  virtual IOperand	*operator%(const IOperand &rhs) const;
  T	getValue() const;
};

#include "Operand.tpp"
#endif
