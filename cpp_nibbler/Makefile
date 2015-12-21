##
## Makefile for nibbler in /home/audibe_l/rendu/cpp_nibbler
## 
## Made by Audibert Louis
## Login   <audibe_l@epitech.net>
## 
## Started on  Thu Mar 26 15:17:32 2015 Audibert Louis
## Last update Sat Apr  4 11:44:06 2015 Audibert Louis
##

CC	=	g++

NAME	=	nibbler

SRC	=	Game.cpp		\
		main.cpp

OBJ	=	$(SRC:.cpp=.o)

LDFLAGS +=	 -ldl -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lSDL -lGL -lGLU -lSDL_image


all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o nibbler $(SRC) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf nibbler

re:		clean fclean all

.PHONY:		all clean fclean re
