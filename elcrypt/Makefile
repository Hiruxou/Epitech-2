##
## Makefile for  in /home/nicolaschr/rendu/elcrypt
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Sun Mar 15 11:50:58 2015 Nicolas Charvoz
## Last update Sun Mar 15 15:41:19 2015 Nicolas Charvoz
##

NAME		=	elcrypt

SRC		=	file.c			\
			key.c			\
			main.c			\
			parse_agv.c		\
			key_gen.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -Werror -ansi -pedantic -D_GNU_SOURCE

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
