/*
** Parser.h for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Wed Jan 21 20:37:35 2015 Nicolas Charvoz
** Last update Wed Jan 21 20:37:42 2015 Nicolas Charvoz
*/

#ifndef PARSER_H_
# define PARSER_H_

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class Parser
{
 public:

  Parser();
  Parser(Parser const& other);
  virtual ~Parser();
  Parser& operator=(Parser const& other);
  void feed(std::string const& str);
  int result() const;
  void reset();

 private:

  bool _isOperator(char c) const;
  void _reset_stack();
  void reverseStack(std::stack<std::string>& st) const;
  int _calc(std::stack<int>& st, std::string const& op) const;
  int _result;
  std::stack<char> _operator;
  std::stack<std::string> _operand;
};

#endif
