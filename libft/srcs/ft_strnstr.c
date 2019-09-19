/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:15:43 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 00:53:19 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lens;

	i = 0;
	j = 0;
	lens = len;
	if (needle[j] == '\0')
		return ((char*)haystack);
	if (lens > ft_strlen(haystack))
		lens = ft_strlen(haystack);
	while (haystack[i + j] && i + j < lens)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < lens)
			j++;
		if (!needle[j])
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
