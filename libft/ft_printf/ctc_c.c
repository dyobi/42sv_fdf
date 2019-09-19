/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:47:04 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/04 23:39:15 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ctc_c(t_fwp *fwp, va_list *ap)
{
	unsigned char	c;
	int				i;

	i = 1;
	c = (unsigned char)va_arg(*ap, int);
	if (fwp->flag & FLAG_MINUS)
	{
		ft_putchar(c);
		while (i++ < fwp->wid)
			ft_putchar(' ');
	}
	else if (fwp->wid)
	{
		while (i++ < fwp->wid)
		{
			if (fwp->flag & FLAG_ZERO)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar(c);
	}
	else
		ft_putchar(c);
	return (fwp->wid > 0 ? fwp->wid : 1);
}
