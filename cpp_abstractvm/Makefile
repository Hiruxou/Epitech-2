##
## Makefile for  in /home/nicolaschr/rendu/cpp_abstractvm
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Mon Feb 23 12:49:28 2015 Nicolas Charvoz
## Last update Fri Feb 27 14:29:56 2015 Nicolas Charvoz
##

NAME 		= 	avm

CC		= 	g++

RM		= 	rm -Rf

ECHO		=  	echo -e

CPPFLAGS	+= 	-W -Wall -Wextra -Werror
CPPFLACS	+=	-o3

SRC		= 	main.cpp		\
			Calculator.cpp		\
			Exec.cpp		\
			Lexer.cpp		\
			Parser.cpp		\

OBJ		= 	$(SRC:.cpp=.o)

$(NAME)		: 	$(OBJ)
	  		$(CC) -o $(NAME) $(SRC)
	  		-@$(ECHO) '\033[0;32m> Binary created\033[0m'

all		: 	$(NAME)

clean		:
	  		-@$(RM) $(OBJ) *~ *#
	  		-@$(RM) *.o
			-@$(ECHO) '\033[0;31m> Directory cleaned\033[0m'

fclean		: 	clean
	  		-@$(RM) $(NAME)
	  		-@$(ECHO) '\033[0;31m> Binary removed\033[0m'

re		: 	fclean all clean

.PHONY		:	 clean fclean all re
