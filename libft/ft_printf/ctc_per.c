/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:47:30 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:47:33 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ctc_per(t_fwp *fwp, va_list *ap)
{
	int		count;
	int		width;

	count = 0;
	width = fwp->wid - 1;
	if (!ap)
		return (0);
	if (fwp->flag & FLAG_MINUS)
	{
		ft_putchar('%');
		count += width_di(fwp, width) + 1;
	}
	else
	{
		count += width_di(fwp, width) + 1;
		ft_putchar('%');
	}
	return (count);
}
