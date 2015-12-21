//
// Picture.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 19 09:54:25 2015 Nicolas Charvoz
// Last update Mon Jan 19 11:01:28 2015 Nicolas Charvoz
//

#include "Picture.h"


Picture::Picture() : data("") {}


Picture::Picture(Picture const &picture)
{
  data = picture.data;
}

Picture& Picture::operator=(Picture const &picture)
{
  data = picture.data;
  return *this;
}

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
