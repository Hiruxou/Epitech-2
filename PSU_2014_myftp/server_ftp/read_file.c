/*
** read_file.c for  in /home/nicolaschr/rendu/PSU_2014_myftp/server_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Tue Mar 17 11:39:04 2015 Nicolas Charvoz
** Last update Sun Mar 22 11:49:17 2015 Nicolas Charvoz
*/

#include "server.h"

char	*read_file(char *filename)
{
  char	*buffer;
  int	string_size;
  int	read_size;
  FILE	*handler ;

  handler = fopen(filename, "r");
  buffer = NULL;
  if (handler)
    {
      fseek(handler,0,SEEK_END);
      string_size = ftell (handler);
      rewind(handler);
      buffer = (char*)xmalloc(sizeof(char) * (string_size + 1));
      read_size = fread(buffer,sizeof(char),string_size,handler);
      buffer[string_size] = '\0';
      if (string_size != read_size)
        {
          free(buffer);
          buffer = NULL;
        }
    }
  return (buffer);
}
