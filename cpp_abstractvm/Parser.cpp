//
// Parser.cpp for  in /home/nicolaschr/rendu/cpp_abstractvm
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Feb 11 20:21:32 2015 Nicolas Charvoz
// Last update Fri Feb 27 14:47:53 2015 Nicolas Charvoz
//

#include "Parser.hpp"

const static  std::string g_cmd[] = {
"push",
"pop",
"dump",
"assert",
"add",
"sub",
"mul",
"div",
"mod",
"print",
"exit",
""
};

const static std::string g_type[] = {
  "int8",
  "int16",
  "int32",
  "float",
  "double",
  ""
};

Parser::Parser()
{
}

Parser::Parser(std::list<std::string> const &token) : _token(token)
{}

int Parser::checkPar(std::string const &nb)
{
  std::size_t first, last;
  std::string newNb;

  try {
    if (nb[nb.size() - 1] != ')')
      {
	_error += "AbstractVM: '" + nb + "' -> Bad Token\n";
	throw myException(_error);
      }
    first = nb.find('(') + 1;
    last = nb.find_last_of(')');
    newNb = nb.substr(first, last-first);
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }
  return 0;
}

void Parser::checkNum(std::string const &num)
{
  for (std::string::const_iterator it = num.begin() ; it != num.end() ; ++it)
    {
      try {
	if (isdigit(*it) || *it == '.' || *it == '-');
	else
	  {
	    _error += "AbstractVM: You must enter a valid number";
	    throw myException(_error);
	  }
      } catch (myException &e) {
	std::cerr << e.what()<< std::endl;
	exit(0);
      }

    }
}

void Parser::transformIOperand(std::string const &token)
{
  int i = 0;
  std::string nb, type;
  std::size_t first, last;
  std::string newNb;

  try {
    first = token.find('(') + 1;
    last = token.find_last_of(')');
    newNb = token.substr(first, last-first);
    _nb.clear();
    this->checkNum(newNb);
    _nb = newNb;
  }
  catch (const std::exception &e) {
    _error +=  "AbstractVM: '" + token + "' : Not a valid command\n";
    std::cerr << _error;
    exit(0);
  }
  while (i < (int)first - 1)
    {
      type += token[i];
      i++;
    }
  _type.clear();
  _type = type;
}

int Parser::getEnumType(std::string const &type) const
{
  if (type == "int8")
    return 0;
  else if (type == "int16")
    return 1;
  else if (type == "int32")
    return 2;
  else if (type == "float")
    return 3;
  else if (type == "double")
    return 4;
  else
    return -1;
}

std::list<Parser::t_parse> Parser::getListOfCommand() const
{
  return _parse;
}

void		Parser::fillStruct()
{
  Calculator	c;

  for (std::list<std::string>::iterator it = _token.begin() ;
       it != _token.end() ; ++it)
    {
      _p = new t_parse;
      if (*it == "push" || *it == "assert")
	{
	  std::list<std::string>::iterator tmp = it;
	  ++tmp;
	  _p->cmd = *it;
	  this->transformIOperand(*tmp);
	  _p->value = c.createOperand((eOperandType)getEnumType(_type), _nb);
	  _parse.push_back(*_p);
	  ++it;
	}
      else
	{
	  _p->cmd = *it;
	  _p->value = NULL;
	  _parse.push_back(*_p);
	}
    }
}

int Parser::grammarChecker2(std::string const &token)
{
  int i = 0, j = 0;
  bool check = false;
  std::string nb, type;
  std::size_t pos;

  try {
    pos = token.find("(");
    nb = token.substr(pos);
  }
  catch (const std::exception &e) {
    _error +=  "AbstractVM: '" + token + "' : Not a valid command\n";
    std::cerr << _error;
    exit(0);
  }
  while (i < (int)pos)
    {
      type += token[i];
      i++;
    }
  while (g_type[j] != "")
    {
      if (type == g_type[j])
	check = true;
      j++;
    }
  try {
    if (checkPar(nb) == -1)
      {
	_error += "AbstractVM: '" + nb + "' -> Bad Token\n";
	throw myException(_error);
      }
  } catch (myException &e) {
    std::cerr << e.what() << std::endl;
    exit(0);
  }
  if (check == true)
    return 0;
  return -1;
}

void Parser::grammarChecker()
{
  int i;
  bool check = false;
  std::string error;

  for (std::list<std::string>::iterator it = _token.begin() ;
       it != _token.end() ; ++it)
    {
      check = false;
      i = 0;
      while (g_cmd[i] != "")
	{
	  if (*it == g_cmd[i])
	    check = true;
	  i++;
	}
      if (check == false)
	{
	  try {
	    if (grammarChecker2(*it) == 0)
	      continue;
	    _error += "AbstractVM: '" + *it + "' unimplemented\n";
	    throw myException(_error);
	  } catch (myException &e) {
	    std::cerr  << e.what() << std::endl;
	    exit(0);
	  }
	}
    }
}
