//
// Exception.hpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Apr 21 15:42:08 2015 Nicolas Charvoz
// Last update Tue Apr 21 15:42:15 2015 Nicolas Charvoz
//

#ifndef EXCEPTION_HPP_
# define EXCEPTION_HPP_

# include <cstdlib>
# include <string>
# include <iostream>
# include <exception>

class Exception : public std::exception {

public:

  explicit Exception(const char* message):
    msg_(message) {}
  explicit Exception(const std::string& message):
    msg_(message) {}
  virtual ~Exception() throw (){}
  virtual const char* what() const throw (){
    return msg_.c_str();
  }

protected:

  std::string msg_;

};

#endif
