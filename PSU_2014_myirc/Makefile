##
## Makefile for  in /home/nicolaschr/rendu/PSU_2014_myftp
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Tue Mar 10 00:31:27 2015 Nicolas Charvoz
## Last update Wed Apr 15 17:28:02 2015 Nicolas Charvoz
##

NAME		=	server
NAME2		=	client

SRC_SERVER	=	server_irc/main_server.c		\
			server_irc/utilis.c			\
			server_irc/xfonc.c			\
			server_irc/list.c			\
			server_irc/parser.c			\
			server_irc/interpret_cmd.c		\
			server_irc/command.c			\
			server_irc/command2.c			\
			server_irc/join_channel.c		\
			server_irc/nickname.c			\
			server_irc/user.c			\
			xmalloc.c

SRC_CLIENT	=	client_irc/init_client.c		\
			client_irc/init_struct.c		\
			client_irc/main_client.c		\
			client_irc/free_tab.c			\
			client_irc/read_message.c		\
			client_irc/parser.c			\
			client_irc/interpret_cmd.c		\
			client_irc/command.c			\
			client_irc/command2.c			\
			client_irc/loop_client.c		\
			xmalloc.c

OBJ_SERVER      =       $(SRC_SERVER:.c=.o)
OBJ_CLIENT      =       $(SRC_CLIENT:.c=.o)

CC		=	gcc

CFLAGS		+=	-W -Wall -Wextra -Werror

RM		=	rm -f

all:		$(NAME) $(NAME2)

$(NAME):	$(OBJ_SERVER)
		@echo "\033[31m=== Server compilation ===\033[00m"
		$(CC) -o $(NAME) $(OBJ_SERVER) $(CFLAGS)
		@echo  $(SRC_SERVER) "\033[32m==> Compilation sucess\033[00m"

$(NAME2):	$(OBJ_CLIENT)
		@echo  "\033[31m=== Client compilation ===\033[00m"
		$(CC) -o $(NAME2) $(OBJ_CLIENT) $(CFLAGS)
		@echo  $(SRC_CLIENT) "\033[32m==> Compilation sucess\033[00m"

clean:
		@echo  "\033[31m=== Clean mode ===\033[00m"
		@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
		@echo  $(OBJ_SERVER) $(OBJ_CLIENT) "\033[32m==> Delete sucess\033[00m"

fclean:		clean
		@$(RM) $(NAME) $(NAME2) *# */*#
		@echo -e $(NAME) $(NAME2) "\033[32m==> EXE delete sucess\033[00m"

re:		fclean all

.PHONY:		all re clean fclean

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@
