/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:15:59 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:15:59 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char*)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
