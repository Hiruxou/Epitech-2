//
// Serializer.hh for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Thu Apr 23 12:47:52 2015 Nicolas Charvoz
// Last update Sun Apr 26 10:55:34 2015 Antoine Garcia
//

#ifndef SERIALIZER_HH_
# define SERIALIZER_HH_

#include "Parser.hpp"
#include "./pizza/APizza.hh"

class Serializer {

private:
  std::list<std::string> _essentialList;
  std::list<Parser::t_pizza> _finalList;
  std::string _pizzaName;
  std::string _pizzaSize;
  std::stringstream  _pizzaNum;
  std::stringstream _pizzaStream;
  std::string _pizzaString;

  public:
  Serializer() {};

  void buildEssentialList(std::string &s)
  {
    std::string delim = ";";
    std::string token;
    size_t last = 0;
    size_t next = 0;

    while ((next = s.find(delim, last)) != std::string::npos)
      {
	token = s.substr(last, next - last);
	_essentialList.push_back(token);
	last = next + 1;
      }
    token = s.substr(last);
    _essentialList.push_back(token);
  }

  void eraseNullElement()
  {
    std::list<std::string>::iterator it = _essentialList.begin();

    while (it != _essentialList.end())
      {
	if (*it == "")
	  _essentialList.erase(it++);
	else
	  ++it;
      }
  }

  APizza::TypePizza getTypeOfPizza(std::string &s) const
  {
    if (s == "REGINA")
      return APizza::Regina;
    else if (s == "MARGARITA")
      return APizza::Margarita;
    else if (s == "AMERICAINE")
      return APizza::Americaine;
    else if (s == "AMERICANA")
      return APizza::Americaine;
    return APizza::Fantasia;
  }


  APizza::TaillePizza getSizeOfPizza(std::string &s) const
  {
    if (s == "S")
      return APizza::S;
    else if (s == "M")
      return APizza::M;
    else if (s == "L")
      return APizza::L;
    else if (s == "XL")
      return APizza::XL;
    return APizza::XXL;
  }

  int getNumOfPizza(std::string &s) const
  {
    s.erase(0, 1);
    return atoi(s.c_str());
  }

  void buildList(std::list<std::string> &list)
  {
    Parser::t_pizza p;
    std::list<std::string>::iterator it = list.begin();
    int i = 0;

    while (it != list.end())
      {
	if (i == 0)
	  p.name = this->getTypeOfPizza(*it);
	if (i == 1)
	  p.size = this->getSizeOfPizza(*it);
	if (i == 2)
	  p.num = this->getNumOfPizza(*it);
	++it;
	i++;
      }
    _finalList.push_back(p);
  }

  void buildFinalList(std::string &s)
  {
    std::string delim = " ";
    std::string token;
    size_t last = 0;
    size_t next = 0;
    std::list<std::string> tmpList;

    while ((next = s.find(delim, last)) != std::string::npos)
      {
	token = s.substr(last, next - last);
	tmpList.push_back(token);
	last = next + 1;
      }
    token = s.substr(last);
    tmpList.push_back(token);
    this->buildList(tmpList);
  }

  std::list<Parser::t_pizza> &unpack(std::string &s) {
    this->buildEssentialList(s);
    this->eraseNullElement();
    for (std::list<std::string>::iterator it = _essentialList.begin() ;
     	 it != _essentialList.end() ; ++it)
      this->buildFinalList(*it);
    return _finalList;
  }

  void getTypeOfPizzaString(int name)
  {
    switch (name)
      {
      case APizza::Regina:
	_pizzaName = "REGINA";
	break;
      case  APizza::Margarita:
	_pizzaName = "MARGARITA";
	break;
      case APizza::Americaine:
	_pizzaName = "AMERICAINE";
	break;
      default:
	_pizzaName = "FANTASIA";
	break;
      }
  }

  void getSizeOfPizzaString(int size)
  {
    switch (size)
      {
      case APizza::S:
	_pizzaSize = "S";
	break;
      case  APizza::M:
	_pizzaSize = "M";
	break;
      case APizza::L:
	_pizzaSize = "L";
	break;
      case APizza::XL:
	_pizzaSize = "XL";
	break;
      default :
	_pizzaSize = "XXL";
	break;
      }
  }

  void getNumOfPizzaString(int num)
  {
    _pizzaNum.str("");
    _pizzaNum << "X" << num;
  }

  std::string &pack(std::list<Parser::t_pizza> const &list)
  {
    std::list<Parser::t_pizza>::const_iterator it;

    for (it = list.begin() ; it != list.end() ; ++it)
      {
	getTypeOfPizzaString((*it).name);
	getSizeOfPizzaString((*it).size);
	getNumOfPizzaString((*it).num);
	_pizzaStream << _pizzaName << " " << _pizzaSize << " "
		     << _pizzaNum.str() << ";" ;
      }
    _pizzaString = _pizzaStream.str();
    return _pizzaString;
  }

  std::string &pack(APizza const &pizza)
  {
    getSizeOfPizzaString(pizza.getSize());
    _pizzaStream << "PIZZA " << pizza.getName() << " "
		 << _pizzaSize;
    _pizzaString = _pizzaStream.str();
    return _pizzaString;
  }
};

#endif
