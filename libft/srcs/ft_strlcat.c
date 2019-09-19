/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:14:53 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:14:53 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dl;
	unsigned int	sl;
	unsigned int	i;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize <= dl)
		return (dstsize + sl);
	i = 0;
	while ((dstsize - 1) > (dl + i) && src[i])
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
