/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:12:58 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:12:58 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (dst == src)
		return (dst);
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	while (n--)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	return (dst);
}
