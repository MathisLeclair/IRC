/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 11:57:32 by mleclair          #+#    #+#             */
/*   Updated: 2018/04/26 12:47:32 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void loop(t_env *e){
    int	i;

    i = 0;
    e->max = 0;
    FD_ZERO(&e->fd_read);
    FD_ZERO(&e->fd_write);
    while (i < e->maxfd)
    {
        if (e->fds[i].type != FD_FREE)
        {
            FD_SET(i, &e->fd_read);
            if (strlen(e->fds[i].buf_write) > 0)
                FD_SET(i, &e->fd_write);
            e->max = e->max > i ? e->max : i;
        }
        i++;
    }
    e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
    while ((i < e->maxfd) && (e->r > 0))
    {
        if (FD_ISSET(i, &e->fd_read))
            e->fds[i].fct_read(e, i);
        if (FD_ISSET(i, &e->fd_write))
            e->fds[i].fct_write(e, i);
        if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
            e->r--;
        i++;
    }
}
