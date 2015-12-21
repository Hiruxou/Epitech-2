#include <sstream>
#include <iostream>
#include "PizzaGenerator.hh"

PizzaGenerator::PizzaGenerator()
{
  _pizza["Margarita"] = &PizzaGenerator::generatePizza<Margarita>;
  _pizza["Regina"] = &PizzaGenerator::generatePizza<Regina>;
  _pizza["Americaine"] = &PizzaGenerator::generatePizza<Americaine>;
  _pizza["Fantasia"] = &PizzaGenerator::generatePizza<Fantasia>;
  _pizza2[APizza::TypePizza::Margarita] = &PizzaGenerator::generatePizza<Margarita>;
  _pizza2[APizza::TypePizza::Regina] = &PizzaGenerator::generatePizza<Regina>;
  _pizza2[APizza::TypePizza::Americaine] = &PizzaGenerator::generatePizza<Americaine>;
  _pizza2[APizza::TypePizza::Fantasia] = &PizzaGenerator::generatePizza<Fantasia>;
}
PizzaGenerator::~PizzaGenerator()
{

}

APizza	*PizzaGenerator::createForKitchen(std::string order)
{
  Serializer	serial;
  std::istringstream	cmd(order);
  std::string		name;
  std::string		size;

  cmd >> name;
  cmd >> size;
  return _pizza[name](serial.getSizeOfPizza(size));
}

APizza	*PizzaGenerator::createForReception(APizza::TypePizza type, APizza::TaillePizza size)
{
  return (_pizza2[type](size));
}

template<typename T>
APizza	*PizzaGenerator::generatePizza(APizza::TaillePizza size)
{
  return new T(size);
}
