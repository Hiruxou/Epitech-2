/*
** client.h for  in /home/nicolaschr/rendu/PSU_2014_myftp/client_ftp
**
** Made by Nicolas Charvoz
** Login   <nicolaschr@epitech.net>
**
** Started on  Mon Mar  9 20:19:26 2015 Nicolas Charvoz
** Last update Sun Mar 22 12:00:35 2015 Nicolas Charvoz
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

# define		SIZE_OF_TAB_C 12
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
# define                c120    "120: Service ready in %s minutes.\n".
# define	c125   "125: Data connection already open; transfer starting.\n"
# define        c150   "150: File status okay; about to open data connection.\n"
# define                c200    "200: Command okay.\n"
# define                c202    "202: Command not implemented.\n"
# define                c214    "214: %s\n"
# define                c220    "220: Service ready for new user.\n"
# define                c221    "221: Service closing control connection.\n"
# define                c226    "226: Closing data connection.\n"
# define                c230    "230: User logged in, proceed.\n"
# define                c250    "250: Requested file action okay, completed.\n"
# define                c257    "257: %s created.\n"
# define                c331    "331: User name okay, need password.\n"
# define                c332    "332: Need account for login.\n"
# define		c530	"530: Not logged in (Please login using 'user')"

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
}			t_client;

void	init_struct(t_client *);
void	create_socket(t_client*);
void	init_host(t_client*, char**);
void	connect_to_server(t_client*);
void	read_write_client(t_client*);
void	parser(char*, t_client*);
void	exec_cmd(t_client*);
int	user_ftp(t_client*);
int	ls_ftp(t_client*);
int	lls_ftp(t_client*);
int     cd_ftp(t_client*);
int	lcd_ftp(t_client*);
int	get_ftp(t_client*);
int	put_ftp(t_client*);
int	pwd_ftp(t_client*);
int	lpwd_ftp(t_client*);
int	clear_client(t_client*);
int	quit_ftp(t_client*);
int	noop_ftp(t_client*);
void	free_tab(t_client*);
int	file_exists(char*);
char	*read_file(char*, int*);
void	read_write_inf(int, FILE*, int);
FILE	*open_my_file(char*, int*);
void	*xmalloc(int);

#endif /* !CLIENT_H_ */
