//
// IOperand.hh for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 26 00:02:44 2015 Nicolas Charvoz
// Last update Thu Feb 12 16:33:15 2015 antoine garcia
//

#ifndef _IOPERAND_HPP_
# define _IOPERAND_HPP_

# include <iostream>
# include <string>

enum eOperandType {
  INT8,
  INT16,
  INT32,
  FLOAT,
  DOUBLE
};

class IOperand {

public:

  virtual std::string const &toString() const = 0; // Renvoie une string representant l'instance

  virtual int getPrecision() const = 0; // Renvoie la précision du type de l'instance
  virtual eOperandType getType() const = 0; // Renvoie le type de l'instance ; Voir plus bas

  virtual IOperand *operator+(const IOperand &rhs) const = 0; // Somme
  virtual IOperand *operator-(const IOperand &rhs) const = 0; // Différence
  virtual IOperand *operator*(const IOperand &rhs) const = 0; // Mul
  virtual IOperand *operator/(const IOperand &rhs) const = 0; // Div
  virtual IOperand *operator%(const IOperand &rhs) const = 0; // Modulo

  virtual ~IOperand() {}

};

#endif
