//
// ex06.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Jan 21 15:45:16 2015 Nicolas Charvoz
// Last update Wed Jan 21 15:48:39 2015 Nicolas Charvoz
//

#ifndef EX06_HPP__
#define EX06_HPP__

#include <string>
#include <sstream>
#include <iostream>


template<typename T>
std::string print(T) {
  return std::string("???");
}

template<>
std::string print(int a) {
  std::stringstream oss;
  oss << a;
  return std::string("int:") + oss.str();
}

template<>
std::string print(float a) {
  std::stringstream oss;
  oss << a;
  return std::string("float:") + oss.str();
}

template<>
std::string print(std::string a) {
  return std::string("string:\"") + a + "\"";
}


template<typename T1, typename T2 = T1>

class Tuple {

public:
  T1 a;
  T2 b;
  std::string toString() {
    return std::string("[TUPLE [") + print(a)
      + "] [" + print(b) + "]]";
  }
};

#endif
