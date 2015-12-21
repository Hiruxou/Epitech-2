/*
** parse_agv.c for parse_argv in /home/garcia_t/elcrypt
**
** Made by antoine garcia
** Login   <garcia_t@epitech.net>
**
** Started on  Sat Mar 14 11:26:47 2015 antoine garcia
** Last update Sun Mar 15 15:37:39 2015 Nicolas Charvoz
*/

#include "elcrypt.h"

static void get_actions(char c, t_opt *opt)
{
  if (c == 'd')
    {
      if (opt->action == UNDEFINED)
	opt->action = CRYPT;
      else
	printf("Error : Vous devez choisir entre cryptage et decryptage.\n");
    }
  if (c == 'e')
    {
      if (opt->action == UNDEFINED)
	opt->action = CRYPT;
      else
	printf("Error : Vous devez choisir entre cryptage et decryptage.\n");
    }
}

static void get_arguments(char c, t_opt *opt)
{
  if (c == 'f')
      opt->src = strdup(optarg);
  if (c == 'o')
    opt->dest = strdup(optarg);
  if (c == 'k')
    convert_key(opt, optarg);
}

void	init_opt(t_opt *opt)
{
  opt->d = 0;
  opt->e = 0;
  opt->f = 0;
  opt->o = 0;
  opt->k = 0;
  opt->action = UNDEFINED;
}

void	get_options(int ac, t_opt *opt, char **av)
{
  char	*opts = "def:o:k:";
  char	c;

  while ((c = getopt(ac, av, opts)) != -1)
    {
      get_actions(c, opt);
      get_arguments(c, opt);
    }
}

void	parse_argv(int ac,t_opt *opt, char **av)
{
  init_opt(opt);
  get_options(ac, opt, av);
}
