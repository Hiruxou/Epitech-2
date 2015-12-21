/*
** key.c for key in /home/garcia_t/elcrypt
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Mar 14 13:20:32 2015 antoine garcia
** Last update Sun Mar 15 12:07:58 2015 Nicolas Charvoz
*/

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include "elcrypt.h"

char	*convert_binary(intmax_t key)
{
  char	*str;
  int	i;

  str = malloc(65 * sizeof(char));
  i = 0;
  while (i < 64)
    {
      str[64 - 1 - i] = ((key >> i) & 1) + 48;
      i++;
    }
  return (str);
}

char	*key_56bits(char *str)
{
  int	i;
  char	*tmp;
  int	j;
  int	k;

  tmp = malloc(65 * sizeof(char));
  i = 0;
  j = 0;
  k = 0;
  while (i < 64)
    {
      if (k == 7)
	{
	  k = 0;
	  i++;
	  continue;
	}
      k++;
      tmp[j++] = str[i++];
    }
  tmp[j] = '\0';
  return (tmp);
}

char	*my_encrypt(char *key, char *read)
{
  char	*right;
  char	left[4];
  char	*tmp;
  char	*tmp2;
  int	i;
  int	n;
  int	z;

  right = &read[4];
  for (z = 0; z < 4 ; z++)
    left[z] = read[z];
  tmp = calloc(5, sizeof(*tmp));
  tmp2 = calloc(5, sizeof(*tmp2));
  n = i = -1;
  while (++n < 8)
    {
      while (right[++i])
	tmp[i] = right[i] ^ key[i];
      i = -1;
      while (left[++i])
	tmp2[i] = left[i] ^ tmp[i];
      leftRotate(&key[0], n);
    }
  return(tmp);
}

void		convert_key(t_opt *opt, char *key)
{
  intmax_t	key2;
  char		*str_key;
  char		*tmp;

  key2 = strtoimax(key, NULL, 16);
  str_key = convert_binary(key2);
  tmp = key_56bits(str_key);
  opt->first32 = &tmp[24];
}
