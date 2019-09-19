/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 01:29:20 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/07 01:29:27 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char c)
{
	char	*rtnstr;
	size_t	str_len;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == c)
		{
			i += 1;
			if (!(rtnstr = ft_strnew(str_len - i)))
				return (NULL);
			rtnstr = ft_strcpy(rtnstr, &(str[i]));
			free(str);
			return (rtnstr);
		}
		i++;
	}
	free(str);
	return (ft_strnew(0));
}
