/*
** read_inf.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Thu Mar 19 15:30:32 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:21:40 2015 Nicolas Charvoz
*/

#include "server.h"

void		read_inf(int fd, int size, FILE *file)
{
  char		current[1024];
  size_t	ret;
  int		nmemb;
  int		total;
  int		toto;

  toto = 0;
  total = 0;
  nmemb = (size - total < 1024) ? size - total : 1024;
  bzero(current, 1024);
  while ((ret = read(fd, current, nmemb)) > 0)
    {
      toto += fwrite(current, 1, ret, file);
      memset(current, '\0', 1024);
      total += ret;
      nmemb = (size - total < 1024) ? size - total : 1024;
    }
}
