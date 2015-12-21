##
## Makefile for  in /home/nicolaschr/rendu/cpp_nibbler/plugin/OpenGL
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Fri Mar 27 10:04:37 2015 Nicolas Charvoz
## Last update Sun Apr  5 12:35:10 2015 Nicolas Charvoz
##

CC		=	g++

RM		=	rm -f

NAME		=	lib_nibbler_opengl.so

CXXFLAGS	+=	-fPIC -shared -lSDL -lGL -lGLU -lglut -lSDL_image -lX11

SRCS		=	opengl.cpp \

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CXXFLAGS)

clean:
			$(RM) $(OBJS)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
