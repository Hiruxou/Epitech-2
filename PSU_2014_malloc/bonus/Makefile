##
## Makefile for Makefime in /home/garcia_t/rendu/PSU_2014_malloc
## 
## Made by antoine garcia
## Login   <garcia_t@epitech.net>
## 
## Started on  Tue Feb 10 10:48:20 2015 antoine garcia
## Last update Sun Feb 15 19:32:34 2015 antoine garcia
##

CC = gcc

CFLAGS = -fPIC -lpthread
LDFLAGS = -shared

RM = rm -f

NAME = libmy_malloc_$(HOSTTYPE).so

NAMELINK = libmy_malloc.so
SRCS =	block.c \
	malloc.c \
	show_alloc_mem.c \
	realloc.c \
	align.c \
	calloc.c \
	free.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -c  $(SRCS)
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJS)
		ln -s $(NAME) $(NAMELINK)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMELINK)

re:	fclean all

.PHONY: all clean fclean re
