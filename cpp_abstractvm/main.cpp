//
// main.cpp for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Feb 10 14:43:27 2015 Nicolas Charvoz
// Last update Mon Feb 23 11:20:50 2015 Nicolas Charvoz
//

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Exception.hpp"
#include "Exec.hh"

int		main(int ac, char **av)
{
  std::string in;
  std::string final;
  Lexer *lex;
  Parser *parse;
  Exec	exec;

  try {
    if (ac > 1)
      {
	std::ifstream file(av[1], std::ios::in);

	if (!file.is_open())
	  throw myException("File is not opened");
	while (in != "exit")
	  {
	    if (file.eof())
	      throw myException("File is not ended with an exit");
	    getline(file, in);
	    if ((strncmp(in.c_str(), ";", 1) != 0))
	      final += in + '\n';
	  }
	lex = new Lexer(final);
	lex->setToken();
	parse = new Parser(lex->getToken());
	parse->grammarChecker();
	parse->fillStruct();
	exec.execute(parse->getListOfCommand());
      }
    else
      {
	while (in != ";;")
	  {
	    getline(std::cin, in);
	    if ((strncmp(in.c_str(), ";;", 2)) == 0)
	      final += in + '\n';
	    else if ((strncmp(in.c_str(), ";", 1) != 0))
	      final += in + '\n';
	  }
	lex = new Lexer(final);
	lex->setToken();
	parse = new Parser(lex->getToken());
	parse->grammarChecker();
	parse->fillStruct();
	exec.execute(parse->getListOfCommand());
      }
  } catch (myException &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }
  return (0);
}
