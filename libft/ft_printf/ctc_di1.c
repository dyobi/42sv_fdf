/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_di1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:47:59 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:01 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		width_di(t_fwp *fwp, int width)
{
	int		count;

	count = 0;
	if (!(fwp->flag & FLAG_MINUS) && fwp->flag & FLAG_ZERO)
	{
		while (width-- > 0)
		{
			ft_putchar('0');
			count++;
		}
	}
	else
	{
		while (width-- > 0)
		{
			ft_putchar(' ');
			count++;
		}
	}
	return (count);
}

int		minus_di(int sign)
{
	if (sign)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

int		flag_space_di(int sign)
{
	if (!sign)
		ft_putchar(' ');
	return (sign ? 0 : 1);
}

int		flag_plus_di(int sign)
{
	if (!sign)
		ft_putchar('+');
	return (sign ? 0 : 1);
}

int		put_di(t_fwp *fwp, char *s)
{
	int		i;

	i = 0;
	if (fwp->flag & OX_ZERO)
	{
		ft_putchar(' ');
		return (1);
	}
	else if (!(fwp->flag & F_EXIST) && fwp->flag & PRECISION && \
		!fwp->pre && s[0] == '0' && s[1] == '\0')
	{
		if (!fwp->wid)
			return (0);
		ft_putchar(' ');
		return (1);
	}
	else
	{
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	return (i);
}
