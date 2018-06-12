/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:29:32 by mleclair          #+#    #+#             */
/*   Updated: 2018/05/21 15:07:44 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void verif_port(char *port)
{
    int i;

    i = -1;
    while (port[++i])
        if (!ft_isdigit(port[i]))
            error(-1, "Port is invalid, Format : 12345");
    if (ft_strlen(port) > 5 || ft_strlen(port) < 1)
        error(-1, "Port is invalid, Format : 12345");
}

void client_connect(char *ip, char *port)
{
    struct hostent		*hostent;
    struct sockaddr_in	sock;

    verif_port(port);
    socket(AF_INET, SOCK_STREAM, 0);
    if (!(hostent = gethostbyname(ip)))
        error(-1, NULL);
    sock.sin_family = AF_INET;
    sock.sin_port = htons(ft_atoi(port));
}

int main(int argc, char **argv) {
    int i;

    if (argc <= 3)
    {
        i = -1;
        while (argv[1][++i])
            if (!ft_isdigit(argv[1][i]) && argv[1][i] != ':')
                error(-1, "Ip and port should only be number and ':'");
        while (argv[2] && argv[2][++i])
            if (!ft_isdigit(argv[2][i]) && argv[2][i] != ':')
                    error(-1, "Ip and port should only be number and ':'");
        if (argc == 2)
            client_connect(argv[1], argv[2]);
        else if(argc == 3)
            client_connect(ft_strsplit(argv[2], ':')[0],
                ft_strsplit(argv[2], ':')[1]);
        else
            client_connect(argv[1], "666");
    }
    else
        printf("usage: ./server [server_ip[PORT]] || \
            ./server <server_ip> <port>");
}
