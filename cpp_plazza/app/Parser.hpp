//
// Parser.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 17 11:08:23 2015 Nicolas Charvoz
// Last update Thu Apr 23 14:42:38 2015 Nicolas Charvoz
//

#ifndef PARSER_HH_
# define PARSER_HH_

#include <list>
#include <regex>
#include <algorithm>
#include <iterator>
#include <cctype>
#include <locale>
#include <sstream>
#include <iostream>
#include "Exception.hpp"
#include "pizza/APizza.hh"

template <class ForwardIterator, class OutputIterator, class UnaryPredicate>
void trim (
           ForwardIterator first, ForwardIterator last, OutputIterator result,
	   UnaryPredicate pred
           ) {
  for (; first != last && pred(*first); first++);
  for (ForwardIterator p = last; first != last; first++) {
    if (pred(*first))
      p = first;
    else {
      if (p != last) {
        *result = *p;
        p = last;
      }
      *result = *first;
    }
  }
}

class Parser {

public:
  typedef struct s_pizza {
    APizza::TypePizza name;
    APizza::TaillePizza size;
    int num;
    int status;
  } t_pizza;

public:

  Parser(std::string const &);
  void parseOrder();
  void buildEssentialList();
  bool checkRegex(std::string const &) const;
  void dumpList() const;
  void eraseNullElement();
  std::list<Parser::t_pizza> getFinalList() const;
  void buildFinalList(std::string&);
  void buildList(std::list<std::string>&);
  APizza::TypePizza getTypeOfPizza(std::string&) const;
  APizza::TaillePizza getSizeOfPizza(std::string &) const;
  int getNumOfPizza(std::string &) const;
  void setStatusToList();

private:
  std::string _order;
  std::list<std::string> _orderList;
  std::list<Parser::t_pizza> _finalList;
};

#endif
