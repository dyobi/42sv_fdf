/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:28:33 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/03 10:31:00 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_ct	g_ct[] =
{
	{"white", "\x1B[37m"},
	{"black", "\x1B[30m"},
	{"red", "\x1B[31m"},
	{"yellow", "\x1B[33m"},
	{"green", "\x1B[32m"},
	{"cyan", "\x1B[36m"},
	{"blue", "\x1B[34m"},
	{"eoc", "\033[0m"},
	{NULL, NULL}
};

int		put_color(const char *s)
{
	int		i;
	int		j;
	char	temp[10];

	i = 0;
	j = 0;
	s++;
	while (s[i] != '}')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	while (j < 8)
	{
		if (!(ft_strcmp(g_ct[j].color, temp)))
		{
			ft_putstr(g_ct[j].output);
			return (i);
		}
		j++;
	}
	return (0);
}
