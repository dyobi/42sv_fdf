/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:49:03 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:49:05 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		minus_u(t_fwp *fwp, char *s)
{
	int		count;
	int		prec;
	int		len;

	len = ft_strlen(s);
	count = 0;
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	count += ((fwp->wid - count) > 0) ? width_di(fwp, fwp->wid - count) : 0;
	return (count);
}

int		normal_u(t_fwp *fwp, char *s)
{
	int		count;
	int		width;
	int		prec;
	int		temp;
	int		len;

	len = ft_strlen(s);
	count = 0;
	temp = fwp->flag & USELESS_PRE ? 0 : fwp->pre;
	width = fwp->wid - (len > temp ? len : fwp->pre);
	count += width_di(fwp, width);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	return (count);
}

int		ctc_u(t_fwp *fwp, va_list *ap)
{
	int64_t	di;
	char	*temp;
	int		count;

	di = signed_modifier(fwp, ap);
	di = (!(fwp->flag & UNLONG) && !(fwp->flag & TYPE_L) && \
		fwp->flag & TYPE_H) ? (unsigned short)di : di;
	di = (!(fwp->flag & UNLONG) && !(fwp->flag & TYPE_L) && \
		fwp->flag & TYPE_HH) ? (unsigned char)di : di;
	if (fwp->flag & UNLONG || fwp->flag & TYPE_L || fwp->flag \
		& TYPE_LL || fwp->flag & TYPE_J)
	{
		if (!(temp = ft_musi_itoa_base((uint64_t)di, 10)))
			return (0);
	}
	else if (!(temp = di < 0 ? ft_musi_itoa_base((unsigned)di, 10) : \
		ft_msi_itoa_base(di, 10)))
		return (0);
	if (fwp->flag & PRECISION && !(fwp->flag & USELESS_PRE))
		fwp->flag &= ~FLAG_ZERO;
	count = fwp->flag & FLAG_MINUS ? minus_u(fwp, temp) \
		: normal_u(fwp, temp);
	free(temp);
	return (count);
}
