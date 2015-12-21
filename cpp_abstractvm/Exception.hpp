//
// Exception.hpp for Exception in /home/garcia_t/rendu/cpp_abstractvm
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Wed Feb 11 10:41:25 2015 antoine garcia
// Last update Sun Feb 22 20:17:04 2015 Nicolas Charvoz
//

#ifndef _EXCEPTION_HPP_
# define _EXCEPTION_HPP_

# include <exception>
# include <string>

class	myException : public std::exception
{

protected:
  std::string _msg;
public:
  explicit myException(const char *msg):_msg(msg){}
  explicit myException(const std::string& msg):_msg(msg){}
  virtual ~myException() throw() {}
  virtual const char *what() const throw(){
    return _msg.c_str();
  }
};

#endif
