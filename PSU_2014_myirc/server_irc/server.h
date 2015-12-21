/*
** server.h for  in /home/nicolaschr/rendu/PSU_2014_myftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 16:19:26 2015 Nicolas Charvoz
** Last update Wed Apr 15 17:26:08 2015 Nicolas Charvoz
*/

#ifndef			SERVER_H_
# define		SERVER_H_

# include		<stdio.h>
# include		<stdlib.h>
# include		<string.h>
# include		<unistd.h>
# include		<sys/types.h>
# include		<sys/socket.h>
# include		<sys/select.h>
# include		<netinet/in.h>
# include		<arpa/inet.h>
# include		<sys/stat.h>
# include		<fcntl.h>
# include		<limits.h>
# include		<time.h>

# define		KNRM	"\x1B[0m"
# define		KRED	"\x1B[31m"
# define		KGRN	"\x1B[32m"
# define		KYEL	"\x1B[33m"
# define		KBLU	"\x1B[34m"
# define		KMAG	"\x1B[35m"
# define		KCYN	"\x1B[36m"
# define		KWHT	"\x1B[37m"
# define		RESET	"\033[0m"

typedef struct		s_client
{
  char	name[4096];
  char	chan[4096];
  int	id;
  int	c_fd;
  struct sockaddr_in clientaddr;
  struct s_client *next;
}			t_client;

typedef struct		s_server
{
  int			nb_clients;
  fd_set		master;
  fd_set		read_fds;
  struct sockaddr_in	serveraddr;
  int			fdmax;
  int			listener;
  int			newfd;
  char			*buf;
  int			addrlen;
  char			**args;
  int			i;
  char			*home;
  t_client		*clients;
}			t_server;

int			xsocket(int, int, int);
void			xbind(int, const struct sockaddr*, socklen_t);
void			xlisten(int, int);
void			init_socket(t_server*);
void			bind_socket(t_server*, int);
void			accept_server(t_server*, char**);
void			read_write_server(t_server*, int, char**);
void			parser(char *,t_server*);
void			*xmalloc(int);
t_client		*push_back(t_client **client);
int			server_irc(t_server*, t_client *);
int			nick_irc(t_server*, t_client *);
int			list_irc(t_server*, t_client *);
int			join_irc(t_server*, t_client *);
int			part_irc(t_server*, t_client *);
int			users_irc(t_server*, t_client *);
int			private_msg_irc(t_server*, t_client *);
int			send_file_irc(t_server*, t_client *);
int			accept_file_irc(t_server*, t_client *);
int			user_irc(t_server*, t_client *);
int			msg_irc(t_server*, t_client *);
void			exec_cmd(t_server *, int, t_client *);
void			join_channel(t_server *, t_client *);
void			change_nickname(t_server *, t_client *, char *);
t_client*		choose_client(int, t_server*, t_client*);

#endif			/* !SERVER_H_ */
