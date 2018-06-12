/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:30:01 by mleclair          #+#    #+#             */
/*   Updated: 2018/04/26 13:28:21 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void client_read(t_env *e, int cs)
{
    int	r;
    int	i;

    r = recv(cs, e->fds[cs].buf_read, BUF_SIZE, 0);
    if (r <= 0)
    {
        close(cs);
        e->fds[cs].type = FD_FREE;
        e->fds[cs].fct_read = NULL;
        e->fds[cs].fct_write = NULL;
        printf("client #%d gone away\n", cs);
    }
    else
    {
        i = 0;
        while (i < e->maxfd)
        {
            if ((e->fds[i].type == FD_CLIENT) && (i != cs))
                send(i, e->fds[cs].buf_read, r, 0);
            i++;
        }
    }
}

void client_write(t_client *client, char *str)
{
    //TODO
    printf("%s\n", str);
    send(client->fd, str, ft_strlen(str), 0);
}
