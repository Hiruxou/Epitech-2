/*
** read_write_inf.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
OB**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Sat Mar 21 18:25:28 2015 Nicolas Charvoz
** Last update Sun Mar 29 17:46:22 2015 Nicolas Charvoz
*/

#include "client.h"

void		read_write_inf(int fd, FILE *file, int size)
{
  char		current[4096];
  size_t	ret;
  int		total;
  int		nmemb;
  int		tmp;

  tmp = 0;
  total = 0;
  nmemb = (size - total < 4096) ? size - total : 4096;
  bzero(current, 4096);
  while ((ret = fread(current, 1, nmemb, file)) > 0)
    {
      if ((tmp = write(fd, current, ret)) != (ssize_t) ret)
	{
	  printf("Erro on write fort write of %ld\n", ret);
	}
      printf("|");
      fflush(stdout);
      bzero(current, 4096);
      total += ret;
      nmemb = (size - total < 4096) ? size - total : 4096;
    }
  fclose(file);
}
