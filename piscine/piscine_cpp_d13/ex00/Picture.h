/*
** Picture.h for  in /home/nicolaschr/rendu/piscine_cpp_d13/ex00
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Jan 19 09:46:03 2015 Nicolas Charvoz
** Last update Mon Jan 19 10:35:14 2015 Nicolas Charvoz
*/

#ifndef PICTURE_H_
#define PICTURE_H_

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

class Picture {

public:

  Picture();
  Picture(const std::string &file);

  std::string data;
  bool getPictureFromFile(const std::string &file);


};

#endif
