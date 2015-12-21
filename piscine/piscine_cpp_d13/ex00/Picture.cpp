//
// Picture.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 09:54:25 2015 Nicolas Charvoz
// Last update Mon Jan 19 10:33:12 2015 Nicolas Charvoz
//

#include "Picture.h"


Picture::Picture() : data("") {}


Picture::Picture(const std::string &file) {
  getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &file)
{
  std::ifstream is(file.data());

  if (is.is_open())
    {
      std::stringstream buff;
      buff << is.rdbuf();
      data = buff.str();
      is.close();
      return true;
    }
  data = "ERROR";
  return false;
}
