/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:56 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:57 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		put_flag(int i)
{
	if (i > 0)
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	return (2);
}

int		minus_p(t_fwp *fwp, char *s, int len)
{
	int		count;
	int		prec;

	count = 0;
	count += put_flag(1);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	count += ((fwp->wid - count) > 0) ? width_di(fwp, fwp->wid - count) : 0;
	return (count);
}

int		normal_p(t_fwp *fwp, char *s, int len)
{
	int		count;
	int		width;
	int		prec;
	int		temp;

	count = 0;
	temp = fwp->flag & USELESS_PRE ? 0 : fwp->pre;
	width = fwp->wid - (len > temp ? len : fwp->pre);
	width -= 2;
	count += width_di(fwp, width);
	count += put_flag(1);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	return (count);
}

int		ctc_p(t_fwp *fwp, va_list *ap)
{
	int64_t	di;
	char	*temp;
	int		count;
	int		len;

	count = 0;
	di = (int64_t)va_arg(*ap, void*);
	if (!(temp = ft_msi_itoa_base(di, 16)))
		return (0);
	len = ft_strlen(temp);
	if (fwp->flag & FLAG_MINUS)
		count = minus_p(fwp, temp, len);
	else
		count = normal_p(fwp, temp, len);
	free(temp);
	return (count);
}
