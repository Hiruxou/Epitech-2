##
## Makefile for  in /home/nicolaschr/rendu/PSU_2014_lemipc
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Sat Mar  7 14:07:23 2015 Nicolas Charvoz
## Last update Sat Mar  7 14:33:48 2015 Nicolas Charvoz
##

NAME		=	lemipc

SRC		=	check_death.c		\
			graphics.c		\
			init_lemipc.c		\
			launch_game.c		\
			main.c			\
			move.c			\
			utilis_functions.c	\
			catch.c			\
			free_ipc.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -lSDL -lSDL_image

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
