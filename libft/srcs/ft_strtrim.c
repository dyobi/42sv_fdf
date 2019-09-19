/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:16:09 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 01:10:32 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(const char *s)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	while (ft_iswhite(s[i]))
		i++;
	while (ft_iswhite(s[j - 1]))
		j--;
	if (i > j)
		j = i;
	if (!(str = ft_strnew(j - i)))
		return (NULL);
	ft_strncpy(str, s + i, j - i);
	return (str);
}
