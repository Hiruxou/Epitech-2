//
// LibException.hpp for  in /home/nicolaschr/rendu/cpp_nibbler/plugin/OpenGL
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:04:45 2015 Nicolas Charvoz
// Last update Sat Apr  4 20:08:15 2015 Nicolas Charvoz
//

#ifndef LIBEXCEPTION_HPP_
# define LIBEXCEPTION_HPP_

# include <cstdlib>
# include <string>
# include <iostream>
# include <exception>

class LibException : public std::exception
{

public:

  explicit LibException(const char* message):
    msg_(message) {}
  explicit LibException(const std::string& message):
    msg_(message) {}
  virtual ~LibException() throw (){}
  virtual const char* what() const throw (){
    return msg_.c_str();
  }

protected:

  std::string msg_;

};

#endif
