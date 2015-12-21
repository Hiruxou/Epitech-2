##
## Makefile for nibbler in /home/audibe_l/rendu/cpp_nibbler/plugin
## 
## Made by Audibert Louis
## Login   <audibe_l@epitech.net>
## 
## Started on  Thu Mar 26 15:44:37 2015 Audibert Louis
## Last update Sun Apr  5 12:35:22 2015 Nicolas Charvoz
## Last update Thu Mar 26 16:53:35 2015 Antoine Garcia
##

CC              =               g++

CFLAGS          =               -fPIC -Wall -Wextra
CFLAGS          =               -fPIC -rdynamic -Wall -Wextra
LDFLAGS         =               -shared

RM              =               rm -f

NAME            =               lib_nibbler_ncurse.so

SRCS            =               ncurse.cpp

OBJS            =               $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -c $(SRCS) -lncurses
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) -lncurses

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		clean fclean all

.PHONY:		all clean fclean re
