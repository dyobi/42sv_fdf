/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:12:29 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/03 00:45:23 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	nb_len(int n)
{
	int		len;

	len = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = nb_len(n);
	if (!(str = ft_strnew((size_t)len)))
		return (NULL);
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	len -= 1;
	while (n >= 10)
	{
		str[len--] = (char)(n % 10 + '0');
		n /= 10;
	}
	str[len] = (char)(n + '0');
	return (str);
}
