//
// sickkoala.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex02
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 11:29:31 2015 Nicolas Charvoz
// Last update Mon Jan 12 20:08:56 2015 Nicolas Charvoz
//

#include <iostream>
#include <cstring>
#include "sickkoala.h"

SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala::~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" << std::endl;
}

bool SickKoala::takeDrug(std::string string)
{
  if (strcasecmp(string.c_str(), "mars") == 0)
    {
      std::cout << "Mr." << this->name << ": Mars, et ca kreog !" <<std::endl;
      return true;
    }
  else if (string == "Buronzand")
    {
      std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" << std::endl;
      return true;
    }
  else
    {
      std::cout << "Mr." << this->name << ": Goerkreog !" << std::endl;
      return false;
    }
}

void SickKoala::poke()
{
  std::cout << "Mr."<< this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

void SickKoala::overDrive(std::string string)
{
  while (string.find("Kreog !") != std::string::npos)
    string.replace(string.find("Kreog !"), 7, "1337 !");
  std::cout << "Mr."<< this->name << ": "  << string << std::endl;
}
