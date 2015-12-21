//
// main.cpp for hashcode in /home/audibe_l/rendu/hashcode
//
// Made by Audibert Louis
// Login   <audibe_l@epitech.net>
//
// Started on  Thu Mar 12 19:34:47 2015 Audibert Louis
// Last update Thu Mar 12 22:19:30 2015 Nicolas Charvoz
//


#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <list>
#include "datacenter.h"
#include "server.h"

void	read_file(char *filename)
{
  std::string in;
  int sizeY, sizeX, nbU, nbGroups, nbServ;
  std::ifstream file(filename, std::ios::in);
  DataCenter *dc;
  char **map;
  int i = 0;
  int x = 0, y = 0;
  int size = 0, capacity = 0;
  t_serv *serv;
  std::list<t_serv> servList;
  int tmp = 0;
  int tmp2 = 0;
  serv = (t_serv*)malloc(sizeof(*serv));
  if (file.is_open())
    getline(file, in);
  sscanf(in.c_str(), "%i %i %i %i %i", &sizeY, &sizeX, &nbU,
	 &nbGroups, &nbServ);

  dc = new DataCenter(sizeY, sizeX, nbU, nbGroups, nbServ);
  // std::cout << "| " << dc->getSizeY() << " " << dc->getSizeX() << " "
  // 	    << dc->getNbU()
  // 	    << " " << dc->getNbGroups() << " " << dc->getNbServ()
  // 	    << " |" << std::endl;
  map = (char**)malloc((sizeY + 1) * sizeof(char*));
  memset(map, 0, sizeY + 1);
  while (i <= sizeY)
    {
      map[i] = (char*)malloc((sizeX + 1)* sizeof(char));
      memset(map[i], '3', sizeX +1);
      i++;
    }
  while (nbU > 0)
    {
      getline(file, in);
      sscanf(in.c_str(), "%i %i", &y, &x);
      map[y][x] = '2';
      x = 0;
      y = 0;
      nbU--;
    }
  while (nbServ > 0)
    {
      getline(file, in);
      sscanf(in.c_str(), "%i %i", &size, &capacity);
      serv->size = size;
      serv->capacity = capacity;
      servList.push_back(*serv);
      size = 0;
      capacity = 0;
      nbServ--;
    }
  map[sizeY + 1] = NULL;
  y = 0;
for (std::list<t_serv>::iterator it = servList.begin() ;
     it != servList.end() ; ++it)
  {
    it->x = -1;
    it->y = -1;
  }
  for (std::list<t_serv>::iterator it = servList.begin() ;
       it != servList.end() ; ++it)
    {
      y = 0;
      while (y <= sizeY)
	{
	  x = 0;
	  while (x <= sizeX)
	    {
	      tmp = 0;
	      if (map[y][x] != '2' && map[y] != NULL
		  && map[y][x] != '1')
	      	{
	      	  tmp2 = x;
	      	  while (map[y][x] != '2' && map[y] != NULL
	      		 && map[y][x] != '1')
	      	    {
	      	      x++;
	      	      tmp++;
	      	    }
	      	  x = tmp2;
		  int tmp3 = 0;
	      	  if (tmp >= it->size)
	      	    {
	      	      it->x = x;
	      	      it->y = y;
	      	      it->group = rand() % nbGroups;
		      tmp = 0;
		      while (tmp3 <= it->size)
			{
			  map[y][x] = '1';
			  x++;
			  tmp3++;
			}
		      x = tmp2;
		    }
		  tmp2 = x;
		}
	      x++;
	    }
	  y++;
	}
    }
  std::ofstream outfile("dc.out");
  y = 0;
  // while (map[y])
  //   {
  //     x = 0;
  //     while (map[y][x])
  // 	{
  // 	  printf("%c", map[y][x]);
  // 	  x++;
  // 	}
  //     y++;
  //     printf("\n");
  //   }
  for (std::list<t_serv>::iterator it = servList.begin() ;
       it != servList.end() ; ++it)
    {
      if (it->x == -1 || it->y == -1)
      	outfile << "x" << std::endl;
      else
  	outfile << it->y << " " << it->x << " " << it->group << std::endl;
    }
}

int	main(int ac, char **av)
{
  srand(time(NULL));
  if (ac < 2)
    {
      std::cerr << "Need input file in argument" << std::endl;
      return (-1);
    }
  read_file(av[1]);
  return (0);
}
