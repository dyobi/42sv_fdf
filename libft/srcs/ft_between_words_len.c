/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_between_words_len.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:14:00 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/02 19:24:57 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_between_words_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c)
		s++;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}
