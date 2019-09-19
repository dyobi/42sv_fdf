/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_musi_itoa_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:26:28 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/03 10:26:30 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		u_base_len(uint64_t nb, uint64_t base)
{
	uint64_t	i;
	int			len;

	i = nb;
	len = 0;
	while (i >= base)
	{
		i /= base;
		len++;
	}
	len++;
	return (len);
}

char	*ft_musi_itoa_base(uint64_t nb, uint64_t base)
{
	uint64_t	i;
	char		*temp;
	int			len;

	len = u_base_len(nb, base);
	if (!(temp = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		i = nb % base;
		nb /= base;
		if (i >= 10)
			temp[len] = i - 10 + 'a';
		else
			temp[len] = i + '0';
	}
	return (temp);
}
