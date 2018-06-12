/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:56:22 by mleclair          #+#    #+#             */
/*   Updated: 2018/05/21 14:58:45 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void client_loop(){
    while (1)
    {
        client_s();
    }
}

void client_s(){
int				ret;
	struct timeval	timeout;

	FD_ZERO(t_client.fd_read);
	FD_ZERO(t_client.fd_write);
	//FD_COPY(CLIENT_ACTIVE, CLIENT_READ);
	//FD_COPY(CLIENT_ACTIVE, CLIENT_WRITE);
	timeout.tv_sec = 0;
	timeout.tv_usec = 50;
	ret = select(client()->fd + 1, CLIENT_READ, CLIENT_WRITE, NULL, &timeout);
	if (ret < 0)
		error(-1, "Select encountered an error.\n");
	if (FD_ISSET(0, CLIENT_READ))
		client()->cl_read = client_read(0, client()->cl_read);
	if (FD_ISSET(client()->fd, CLIENT_READ) && client()->fd > 0)
		client()->sv_read = client_read(client()->fd, client()->sv_read);
	if (FD_ISSET(client()->fd, CLIENT_WRITE) && client()->fd > 0)
		client()->sv_write = client_write(client()->fd, client()->sv_write);
}