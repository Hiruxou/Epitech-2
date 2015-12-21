/*
** elcrypt.h for elcrypt in /home/garcia_t/elcrypt
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Mar 14 11:24:10 2015 antoine garcia
** Last update Sun Mar 15 12:07:37 2015 Nicolas Charvoz
*/

#ifndef _ELCRYPT_H_
# define _ELCRYPT_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>
#include <signal.h>
#include <inttypes.h>

typedef enum e_action
  {
    CRYPT,
    DECRYPT,
    UNDEFINED
  }		e_action;

typedef struct s_opt
{
  char	d;
  char	e;
  char	f;
  char	o;
  char	k;
  char	action;
  char	*src;
  char	*dest;
  int	fd_in;
  int	fd_out;
  char	*key;
  int current_byte;
  char *first32;
}		t_opt;

void	parse_argv(int, t_opt*, char**);
void	convert_key(t_opt*, char*);
char	*my_encrypt(char*, char*);
void	init(t_opt*);
void	leftRotate(char*, int);

#endif
