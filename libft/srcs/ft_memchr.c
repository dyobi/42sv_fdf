/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:12:46 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 00:26:00 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int			i;
	const void	*str;

	i = 0;
	str = s;
	while (i < (int)n)
	{
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return ((void*)&str[i]);
		i++;
	}
	return (NULL);
}
