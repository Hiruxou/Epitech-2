##
## Makefile for  in /home/charvo_a/rendu/piscine_cpp_d01/ex01
## 
## Made by Charvoz Nicolas
## Login   <charvo_a@epitech.net>
## 
## Started on  Wed Jan  7 19:11:10 2015 Charvoz Nicolas
## Last update Mon Jan 12 10:25:56 2015 Nicolas Charvoz
##

CC	=	g++

RM	=	rm -f

CFLAGS +=	-Wextra -Wall -W -Werror

NAME	=	my_cat

SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:		
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
