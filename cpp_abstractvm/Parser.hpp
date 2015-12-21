//
// Parser.hpp for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Feb 11 20:18:03 2015 Nicolas Charvoz
// Last update Fri Feb 27 14:47:58 2015 Nicolas Charvoz
//

#ifndef _PARSER_HPP_
# define _PARSER_HPP_

# include <cctype>
# include <cstdlib>
# include <algorithm>
# include "Lexer.hpp"
# include "IOperand.hpp"
# include "Calculator.hh"

class Parser {

public:
  typedef struct	s_parse {
    std::string		cmd;
    IOperand		*value;
  }			t_parse;

private:

  std::string _error;
  std::list<std::string> _token;
  std::list<t_parse> _parse;
  std::string _type;
  std::string _nb;
  t_parse *_p;

  int grammarChecker2(std::string const &);
  int checkPar(std::string const &);
  void transformIOperand(std::string const &);
  int getEnumType(std::string const&) const;
  void checkNum(std::string const &);

public:

  Parser();
  Parser(std::list<std::string> const &);
  virtual ~Parser() {}
  void grammarChecker();
  void fillStruct();
  std::list<t_parse> getListOfCommand() const;
};

#endif
