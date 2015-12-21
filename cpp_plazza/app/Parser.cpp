//
// Parser.cpp for  in /home/nicolaschr/rendu/cpp_plazza/app
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Fri Apr 17 11:09:02 2015 Nicolas Charvoz
// Last update Sun Apr 26 22:40:08 2015 Nicolas Charvoz
//

#include "Parser.hpp"

Parser::Parser(std::string const &order) : _order(order)
{}

bool isJunk(char c)
{
  return isspace(c);
}

std::string trim_string(std::string s)
{
  std::ostringstream result;
  trim(s.begin(), s.end(), std::ostream_iterator<char>(result, ""), isJunk);
  return result.str();
}

bool Parser::checkRegex(std::string const &stringToCheck) const
{
  std::regex rgx("\\b(REGINA|MARGARITA|AMERICAINE|FANTASIA|AMERICANA)\\b\\s*(S|L|M|XL|XXL)\\b\\s*X([1-9]*[0-9]*)");

  if (std::regex_match(stringToCheck, rgx))
    return true;
  return false;
}

void Parser::dumpList() const
{
  std::cout << "------------------" << std::endl;
  for (std::list<std::string>::const_iterator it = _orderList.begin() ;
       it != _orderList.end() ; ++it)
    std::cout << "|" << *it << "|" << std::endl;
  std::cout << "------------------" << std::endl;
}

void Parser::buildEssentialList()
{
  std::string delim = ";";
  std::string token;
  size_t last = 0;
  size_t next = 0;

  while ((next = _order.find(delim, last)) != std::string::npos)
    {
      token = trim_string(_order.substr(last, next - last));
      _orderList.push_back(token);
      last = next + 1;
    }
  token = trim_string(_order.substr(last));
  _orderList.push_back(token);
}

APizza::TypePizza Parser::getTypeOfPizza(std::string &s) const
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

APizza::TaillePizza Parser::getSizeOfPizza(std::string &s) const
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

int Parser::getNumOfPizza(std::string &s) const
{
  int nb;

  s.erase(0, 1);
  if ((nb = atoi(s.c_str())) > 0)
    return nb;
  else
    throw Exception("You must enter a valid number of pizza >= 0");
}


void Parser::buildList(std::list<std::string> &list)
{
  t_pizza p;
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
  p.status = 0;
  _finalList.push_back(p);
}

void Parser::buildFinalList(std::string &s)
{
  std::string delim = " ";
  std::string token;
  size_t last = 0;
  size_t next = 0;
  std::list<std::string> tmpList;

  while ((next = s.find(delim, last)) != std::string::npos)
    {
      token = trim_string(s.substr(last, next - last));
      tmpList.push_back(token);
      last = next + 1;
    }
  token = trim_string(s.substr(last));
  tmpList.push_back(token);
  this->buildList(tmpList);
}

void Parser::eraseNullElement()
{
  std::list<std::string>::iterator it = _orderList.begin();

  while (it != _orderList.end())
    {
      if (*it == "")
	_orderList.erase(it++);
      else
	++it;
    }
}

void Parser::setStatusToList()
{
  t_pizza p;

  p.status = 1;
  _finalList.push_back(p);
}

void Parser::parseOrder()
{
  std::stringstream ss;

  std::transform(_order.begin(), _order.end(), _order.begin()
		 , ::toupper);
  _order = trim_string(_order);
  if (_order == "STATUS")
    {
      setStatusToList();
      return ;
    }
  if (_order == "")
    std::cerr << "You must enter an order .." << std::endl;
  else
    {
      this->buildEssentialList();
      this->eraseNullElement();
      for (std::list<std::string>::iterator it = _orderList.begin() ;
	   it != _orderList.end(); ++it)
	{
	  if (!(this->checkRegex(*it)))
	    {
	      std::cerr << "You must enter a valid order in the form : "
			<< "[TYPE OF PIZZA] [SIZE OF PIZZA] [NUMBER OF PIZZA]"
			<< std::endl;
	      _finalList.clear();
	    }
	  else
	    this->buildFinalList(*it);
	}
    }
}

std::list<Parser::t_pizza> Parser::getFinalList() const
{
  return _finalList;
}
