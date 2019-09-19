/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:15:53 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 00:45:03 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	amount(char const *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
				s++;
			i++;
		}
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	int		ylen;
	int		i;
	int		j;
	int		u;
	char	**str;

	ylen = amount(s, c);
	if (!s || !(str = (char**)malloc(sizeof(*str) * (ylen + 1))))
		return (NULL);
	i = -1;
	u = 0;
	while (++i < ylen)
	{
		j = 0;
		if (!(str[i] = ft_strnew(ft_between_words_len(&s[u], c) + 1)))
			str[i] = NULL;
		while (s[u] == c)
			u++;
		while (s[u] != c && s[u])
			str[i][j++] = s[u++];
		str[i][j] = '\0';
	}
	str[i] = 0;
	return (str);
}
