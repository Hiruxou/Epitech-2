/*
** client.h for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 20:19:26 2015 Nicolas Charvoz
** Last update Sun Apr 12 17:57:45 2015 Nicolas Charvoz
*/

#ifndef			CLIENT_H_
# define		CLIENT_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <errno.h>
# include <signal.h>
# include <limits.h>

# define		SIZE_OF_TAB_C 11
# define		BufferLength 4096
# define		SERVER	"127.0.0.1"
# define                KNRM    "\x1B[0m"
# define                KRED    "\x1B[31m"
# define                KGRN    "\x1B[32m"
# define                KYEL    "\x1B[33m"
# define                KBLU    "\x1B[34m"
# define                KMAG    "\x1B[35m"
# define                KCYN    "\x1B[36m"
# define                KWHT    "\x1B[37m"
# define                RESET   "\033[0m"

typedef struct		s_client
{
  int			sd;
  int			rc;
  int			length;
  struct sockaddr_in	serveraddr;
  char			buffer[BufferLength];
  char			server[255];
  char			temp;
  int			totalcnt;
  struct hostent	*hostp;
  char			*data;
  char			buf[4096];
  int			servport;
  char			**args;
  char			*username;
  fd_set		read_fds;
  fd_set		master;
}			t_client;

void	init_struct(t_client *);
void	create_socket(t_client*);
void	init_host(t_client*, char**);
void	connect_to_server(t_client*);
void	read_write_client(t_client*);
void	parser(char*, t_client*);
void	exec_cmd(t_client*, int);
void	free_tab(t_client*);
void	*xmalloc(int);
void	read_message(t_client*);
void	send_message(t_client*);
void	param_server(t_client*);
int	server_irc(t_client*);
int	nick_irc(t_client*);
int	list_irc(t_client*);
int	join_irc(t_client*);
int	part_irc(t_client*);
int	users_irc(t_client*);
int	private_msg_irc(t_client*);
int	send_file_irc(t_client*);
int	accept_file_irc(t_client*);
int	msg_irc(t_client*);
void	loop_client(t_client*);

#endif /* !CLIENT_H_ */
