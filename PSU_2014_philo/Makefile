##
## Makefile for  in /home/nicolaschr/rendu/PSU_2014_philo
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Mon Feb 23 14:52:00 2015 Nicolas Charvoz
## Last update Mon Feb 23 15:22:46 2015 Nicolas Charvoz
##

NAME		=	philo

SRC		=	philosophe.c		\
			ressources_init.c	\
			main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -lpthread

CC		=	cc

RM		=	rm -f
ECHO		=	echo -e

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

all	: $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@$(ECHO) '\033[0;33m> Compiled\033[0m'

clean	:
	$(RM) $(OBJ)
	@$(ECHO) '\033[0;33m> Directory cleaned\033[0m'

fclean	: clean
	$(RM) $(NAME)
	@$(ECHO) '\033[0;33m> Remove executable\033[0m'

re	: fclean all
