/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:56:12 by mleclair          #+#    #+#             */
/*   Updated: 2018/04/25 11:57:53 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void error(int err, char *string) {

    if (string == NULL)
        printf("An error as been detected");
    else
        printf("%s\n", string);
    exit(err);
}
