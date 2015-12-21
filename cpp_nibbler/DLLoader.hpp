//
// DLLoader.hpp for DLLoader in /home/garcia_t/rendu/cpp_nibbler
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Tue Mar 24 13:36:59 2015 antoine garcia
// Last update Sat Apr  4 11:06:52 2015 Antoine Garcia
//

#include <cstdlib>
#include <string>
#include <iostream>
#include <dlfcn.h>
#include <exception>

#ifndef DLLoader_H_
# define DLLoader_H_

class	DLLException: public std::exception
{
public:
  explicit DLLException(const char* message):
    msg_(message)
  {}
  explicit DLLException(const std::string& message):
    msg_(message)
  {}
  virtual ~DLLException() throw (){}
  virtual const char* what() const throw (){
    return msg_.c_str();
  }

protected:
  std::string msg_;
};

template<typename T>
class DLLoader
{
  void	*_handle;
  T	_func;
public:
  explicit DLLoader(const std::string &lib)
  {
    T (*ptr)();
    char	*err;
    std::string lib_name = "./";

    lib_name += lib;
    _handle = dlopen(lib_name.c_str(), RTLD_NOW);
    if (!_handle)
      throw DLLException(dlerror());
    ptr = reinterpret_cast<T (*)()>(dlsym(_handle, "call"));
    if ((err = dlerror()) != NULL)
      throw DLLException("Symbol wasn't found.\n");
    _func = ptr();
  }
  IDisplayModule *getInstance() const
  {
    return (_func);
  }
  ~DLLoader()
  {
    dlclose(_handle);
  }
};

#endif
