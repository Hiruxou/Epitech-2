//
// main.cpp for  in /home/nicolaschr/rendu/piscine_cpp_d06/ex00
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Jan 12 09:59:11 2015 Nicolas Charvoz
// Last update Tue Jan 13 08:55:55 2015 Nicolas Charvoz
//

#include <iostream>
#include <fstream>

int		main(int ac, char **av)
{
  int i = 1;
  std::ifstream file;
  std::string line;
  std::streambuf *buf;

  if (ac == 1)
      std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  else
    {
      while (i < ac)
	{
	  file.open(av[i]);
	  if (file.is_open())
	    {
	      buf = file.rdbuf();
	      std::cout << buf;
	      file.close();
	    }
	  else
	    std::cerr << "my_cat: <" << av[i] << ">: No such file or directory" << std::endl;
	  i++;
	}
    }
  return 0;
}
