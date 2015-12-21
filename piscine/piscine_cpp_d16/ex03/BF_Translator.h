/*
** BF_Translator.h for  in /home/nicolaschr/rendu/piscine_cpp_d16/ex03
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Jan 22 03:40:37 2015 Nicolas Charvoz
** Last update Thu Jan 22 03:40:37 2015 Nicolas Charvoz
*/

#ifndef __BF_TRANSLATOR_H__
# define __BF_TRANSLATOR_H__

# include <string>
# include <iostream>
# include <map>
# include <fstream>
# include <exception>

class BF_Translator
{
public:
  BF_Translator(void);
  ~BF_Translator(void);

  int	translate(std::string in, std::string out);
  typedef void	(BF_Translator::*bf_commands)();

private:
  std::fstream				_in;
  std::fstream				_out;
  std::map<unsigned char, bf_commands>	_commands;

  void	header();
  void  footer();
  void  inc();
  void  desc();
  void  next();
  void  prev();
  void  write();
  void  read();
  void  jump();
  void  back();
};

#endif /*!_BF_TRANSLATOR_H_*/
