##
## Makefile for  in /home/charvo_a/rendu/piscine_cpp_d01/ex01
## 
## Made by Charvoz Nicolas
## Login   <charvo_a@epitech.net>
## 
## Started on  Wed Jan  7 19:11:10 2015 Charvoz Nicolas
## Last update Wed Jan  7 19:12:09 2015 Charvoz Nicolas
##

CC	=	gcc

RM	=	rm -f

CFLAGS +=	-Wextra -Wall -W -Werror -std=gnu99

NAME	=	menger

SRCS	=	menger.c	\
		main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:		
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
