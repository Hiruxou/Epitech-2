##
## Makefile for  in /home/nicolaschr/rendu/cpp_santa
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Sun Jan 18 00:23:43 2015 Nicolas Charvoz
## Last update Sun Jan 18 00:33:50 2015 Nicolas Charvoz
##


NAME = Santa_Claus_Factory

SRC = 	main.cpp			\
	Box.cpp				\
	ConveyorBeltPepeNoel.cpp	\
	ElfOfPepeNoel.cpp		\
	GiftPaper.cpp			\
	LittlePony.cpp			\
	Object.cpp			\
	TablePepeNoel.cpp		\
	Teddy.cpp			\
	Toy.cpp				\
	Wrap.cpp

CC = 		g++

RM =            rm -rf

OBJ =		$(SRC:.cpp=.o)

CXXFLAGS += -Wall -Werror -Wextra -W

all:     	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
