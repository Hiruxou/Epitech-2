//
// Lexer.hpp for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Feb 10 16:30:15 2015 Nicolas Charvoz
// Last update Fri Feb 27 14:42:57 2015 Nicolas Charvoz
//

#ifndef _LEXER_HPP_
# define _LEXER_HPP_

# include <string>
# include <iostream>
# include <algorithm>
# include <sstream>
# include <cctype>
# include <list>
# include <iterator>
# include <cctype>
# include "Exception.hpp"

# define MIN(a, b) ( ((a) < (b)) ? (a): (b))

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

class Lexer {

private:

  std::string _string;
  std::list<std::string> _token;

public:
  Lexer(std::string const &string = "");
  Lexer(Lexer const &);
  virtual ~Lexer() {}
  void setToken();
  std::list<std::string> getToken() const;

};

#endif
