##
## Makefile for  in /home/nicolaschr/rendu/PSU_2014_myftp
## 
## Made by Nicolas Charvoz
## Login   <nicolaschr@epitech.net>
## 
## Started on  Tue Mar 10 00:31:27 2015 Nicolas Charvoz
## Last update Sun Mar 22 22:43:37 2015 Nicolas Charvoz
##

NAME		=	serveur
NAME2		=	client

SRC_SERVER	=	server_ftp/main_server.c		\
			server_ftp/utilis.c			\
			server_ftp/xfonc.c			\
			server_ftp/parser.c			\
			server_ftp/exec.c			\
			server_ftp/command.c			\
			server_ftp/command2.c			\
			server_ftp/client_command.c		\
			server_ftp/read_file.c			\
			server_ftp/my_cd.c			\
			server_ftp/read_inf.c			\
			xmalloc.c

SRC_CLIENT	=	client_ftp/init_client.c		\
			client_ftp/init_struct.c		\
			client_ftp/main_client.c		\
			client_ftp/parser.c			\
			client_ftp/interpret_cmd.c		\
			client_ftp/command.c			\
			client_ftp/free_tab.c			\
			client_ftp/client_command.c		\
			client_ftp/command2.c			\
			client_ftp/file_exists.c		\
			client_ftp/read_file.c			\
			client_ftp/read_write_inf.c		\
			client_ftp/open_my_file.c		\
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
