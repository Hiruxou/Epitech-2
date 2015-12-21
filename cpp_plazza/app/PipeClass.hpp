//
// PipeClass.hpp for PipeClass in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri Apr 24 08:15:54 2015 Antoine Garcia
// Last update Sun Apr 26 09:16:17 2015 Antoine Garcia
//

#ifndef PIPECLASS_HPP_
#define PIPECLASS_HPP_

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

class PipeClass
{
private:
  static int _num;
  bool _son;
  bool _open;
  std::string _pipeinstr;
  std::string _pipeoutstr;
  std::ofstream _pipeout;
  std::ifstream _pipein;
public:
  PipeClass();
  ~PipeClass();
  void setSon(bool son);
  void write(std::string const &str);
  std::string const read();
  std::string const getline();
};

#endif
