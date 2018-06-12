/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:47:53 by mleclair          #+#    #+#             */
/*   Updated: 2018/05/21 13:21:02 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_H
# define IRC_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/select.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdlib.h>

# define FD_FREE	0
# define FD_SERV	1
# define FD_CLIENT	2

# define BUF_SIZE 4096

typedef struct	s_fd
{
  int	type;
  void	(*fct_read)();
  void	(*fct_write)();
  char	buf_read[BUF_SIZE + 1];
  char	buf_write[BUF_SIZE + 1];
}		t_fd;

typedef struct  s_env{
    int     port;
    t_fd    *fds;
    int     max;
    int     maxfd;
    int     r;
    fd_set	fd_read;
    fd_set	fd_write;
    char    *buff;
}               t_env;


typedef  struct s_client {
    int fd;
    char *str;
}               t_client;

void error(int err, char *string);

void client_read(t_env *e, int cs);
void client_write(t_client *client, char *str);


#endif
