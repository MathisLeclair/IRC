/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:35:55 by mleclair          #+#    #+#             */
/*   Updated: 2018/05/21 12:54:14 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc.h"

void srv_accept(t_env *e, int socket) {
    int cs;
    struct sockaddr_in sockadd;
    socklen_t sockadd_len;

    cs = accept(socket, (struct sockaddr *)&sockadd, &sockadd_len);
    printf("New client #%d from %s:%d\n", cs,
       inet_ntoa(sockadd.sin_addr), ntohs(sockadd.sin_port));
    e->fds[cs].type = FD_CLIENT;
    e->fds[cs].fct_read = client_read;
    e->fds[cs].fct_write = client_write;

}

void create_server(t_env *env){
    struct protoent *pro;
    struct sockaddr_in	sin;
    int sock;

    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(env->port);
    pro = getprotobyname("tcp");
    sock = socket(AF_INET, SOCK_STREAM, pro->p_proto);
    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) == -1)
        error(-1, "server bind failed");
    if (listen(sock, 42)== -1)
        error(-1, "server listen failed");
    env->fds[sock].type = FD_SERV;
    env->fds[sock].fct_read = srv_accept;
}

void init(t_env *env){
    struct rlimit lim;

    getrlimit(RLIMIT_NOFILE, &lim);
    env->maxfd = lim.rlim_max;
    env->port = 0;
    env->fds = malloc(sizeof(env->fds) * env->maxfd);
}

void main_loop(t_env *env) {
    //TODO all
    (void)env;
    while (1) {
        //butt stuff
    }
}

int main(int argc, char **argv) {
    t_env *env;
    int i;

    env = malloc(sizeof(t_env *));
    i = -1;
    if (argc == 2)
    {
        while (argv[1][++i]) {
            if (!ft_isdigit(argv[1][i]))
                error(-1, "Port shold be compose only of number");
        }
        init(env);
        env->port = ft_atoi(argv[1]);
        create_server(env);
        //main_loop(env);
    }
    else
        printf("usage: ./server [PORT]");

}
