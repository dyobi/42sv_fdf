/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:13:08 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:13:08 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (str1 == str2)
		return (dst);
	else if (str1 > str2)
	{
		str1 = str1 + len - 1;
		str2 = str2 + len - 1;
		while (len--)
			*str1-- = *str2--;
	}
	else
	{
		while (len--)
			*str1++ = *str2++;
	}
	return (dst);
}
