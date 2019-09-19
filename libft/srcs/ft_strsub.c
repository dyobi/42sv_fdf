/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:16:04 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:16:04 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(str = ft_strnew(len)))
			return (NULL);
		while (len--)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		return (str);
	}
	return (0);
}
