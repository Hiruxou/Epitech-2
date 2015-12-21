//
// PipeClass.cpp for PipeClass in /home/antgar/rendu/cpp_plazza/app
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Fri Apr 24 08:16:03 2015 Antoine Garcia
// Last update Sun Apr 26 14:14:43 2015 Antoine Garcia
//

#include "PipeClass.hpp"

int PipeClass::_num = 0;

PipeClass::PipeClass()
{
  std::stringstream stream;
  std::stringstream stream2;

  _son = false;
  _open = false;
  stream << "/tmp/plazzain" << PipeClass::_num;
  _pipeinstr = stream.str();
  stream2 << "/tmp/plazzaout" << PipeClass::_num;
  _pipeoutstr = stream2.str();
  PipeClass::_num++;

  mkfifo(_pipeinstr.c_str(), 0666);
  mkfifo(_pipeoutstr.c_str(), 0666);
}

PipeClass::~PipeClass()
{
  if (_son)
    {
      _pipein.close();
      _pipeout.close();
    }
  else
    {
      _pipein.close();
      _pipeout.close();
      unlink(_pipeinstr.c_str());
      unlink(_pipeoutstr.c_str());
    }
}

void PipeClass::setSon(bool son)
{
  _son = son;
  _open = true;
  if (_son)
    {
      _pipeout.open(_pipeoutstr.c_str(), std::ostream::out);
      _pipein.open(_pipeinstr.c_str(), std::ostream::in);
    }
  else
    {
      _pipein.open(_pipeoutstr.c_str(), std::ostream::in);
      _pipeout.open(_pipeinstr.c_str(), std::ostream::out);
    }
}

void PipeClass::write(std::string const &str)
{
  if (_open)
    _pipeout << str << std::endl;
}

std::string const PipeClass::read()
{
  std::string str;

  str = "";
  if (_open)
    _pipein >> str;
  return str;
}

std::string const PipeClass::getline()
{
  std::string cmd;

  cmd = "";
  if (_open)
    std::getline(_pipein, cmd);
  return cmd;
}
