/*
** Skat.h for  in /home/nicolaschr/rendu/piscine_cpp_d07a/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Jan 13 16:27:30 2015 Nicolas Charvoz
** Last update Tue Jan 13 17:31:12 2015 Nicolas Charvoz
*/

#ifndef SKAT_H_
#define SKAT_H_

# include <string>
# include <iostream>

class Skat
{
public:
  Skat(std::string const& name, int stimPaks);
  Skat(std::string const& name);
  Skat(int stimPaks);
  Skat();
  ~Skat();

public:
  int &stimPaks();
  const std::string& name();

public:
  void shareStimPaks(int number, int& stock);
  void addStimPaks(unsigned int number);
  void useStimPaks();

 public:
  void status();

private:
  std::string _name;
  int _stimPaks;
};

#endif
