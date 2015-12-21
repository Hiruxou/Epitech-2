//
// ex05.hpp for  in /home/nicolaschr/rendu/piscine_cpp_d15/ex05
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Jan 20 22:43:33 2015 Nicolas Charvoz
// Last update Wed Jan 21 18:18:44 2015 Nicolas Charvoz
//

#ifndef EX05_HPP_
#define EX05_HPP_

#include <string>
#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>

class array {

private:
  unsigned int _size;
  T *tab;

public:

  array() {
    _size = 0;
    tab = NULL;
  }

  array(unsigned int n) {
    _size = n;
    tab = new T[_size];
  }

  array(const array<T> &other) {
    _size = other._size;

    tab = new T[_size];
    unsigned int i = 0;
    while (i < _size)
      {
	tab[i] = other.tab[i];
	i++;
      }
  }

  virtual ~array() {
    if (tab)
      delete[] tab;
  }

  array<T> &operator=(const array<T> &other)
  {
    if (tab)
      delete[] tab;

    _size = other._size;
    tab = new T[_size];
    unsigned int i = 0;
    while (i < _size)
      {
	tab[i] = other.tab[i];
	i++;
      }
    return *this;
  }

  T &operator[](unsigned int index) {
    if (index >= _size)
      {
	T *copy = new T[index + 1];
	unsigned int i = 0;
	while (i < _size)
	  {
	    copy[i] = tab[i];
	    i++;
	  }
	delete[] tab;
	tab = copy;
	_size = index + 1;
      }
    return tab[index];
  }

  T &operator[](unsigned int i) const
  {
    if (i >= _size)
      throw std::exception();
    return tab[i];
  }

  void dump () const
  {
    unsigned int i = 0 ;

    std::cout << "[";
    while (i < _size)
      {
	std::cout << tab[i];
	i++;
	if (i != _size)
	  std::cout << ", ";
      }
    std::cout << "]" << std::endl;
  }

  unsigned int size() const
  {
    return _size;
  }

  template <typename U>
  array<U> convertTo(U(*convert)(const T&)) const  {
    array<U> duplicate(_size);

    unsigned int i = 0;
    while (i < _size)
      {
	duplicate[i] = (*convert)(tab[i]);
	i++;
      }
    return duplicate;
  }

};


  template <>
  void array<bool>::dump () const
  {
    unsigned int i = 0 ;

    std::cout << "[";
    while (i < _size)
      {
	std::cout << (tab[i] ? "true" : "false");
	i++;
	if (i != _size)
	  std::cout << ", ";
      }
    std::cout << "]" << std::endl;
  }


#endif
