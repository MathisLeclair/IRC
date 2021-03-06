/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sisokay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleclair <mleclair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:16:42 by mleclair          #+#    #+#             */
/*   Updated: 2017/01/13 12:19:18 by mleclair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprintf.h"

int		ft_sisdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_sisokay(char c)
{
	if (c == 'z' || c == 'h' || c == 'l' || c == '+' || c == '-' || c == '#'
		|| c == ' ' || c == '*' || c == '.' || c == 'j' || ft_isdigit(c))
		return (1);
	return (0);
}

int		ft_sfuckit(char c)
{
	if (c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 'p'
		|| c == 'd' || c == 'D' || c == 'i' || c == 'c' || c == 'C')
		return (1);
	return (0);
}
