/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_ox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:09 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:10 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*upper_case(char *s)
{
	char	*temp;
	int		len;

	len = 0;
	while (s[len])
		len++;
	if (!(temp = ft_strnew(len + 1)))
		return (NULL);
	len = 0;
	while (s[len])
	{
		if (s[len] >= 'a' && s[len] <= 'z')
			temp[len] = s[len] - 32;
		else
			temp[len] = s[len];
		len++;
	}
	free(s);
	return (temp);
}

int		put_hash(t_fwp *fwp)
{
	if (fwp->flag & FLAG_HASH && fwp->flag & SIXDN)
	{
		ft_putchar('0');
		ft_putchar('x');
		return (2);
	}
	else if (fwp->flag & FLAG_HASH && fwp->flag & SIXUP)
	{
		ft_putchar('0');
		ft_putchar('X');
		return (2);
	}
	else if (fwp->flag & FLAG_HASH && fwp->flag & EIGHT)
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

int		minus_ox(t_fwp *fwp, char *s, int64_t di)
{
	int		count;
	int		prec;
	int		len;

	count = 0;
	len = ft_strlen(s);
	if (di != 0)
		count += put_hash(fwp);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	prec -= (fwp->flag & FLAG_HASH && fwp->flag & EIGHT && di != 0) ? 1 : 0;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	count += ((fwp->wid - count) > 0) ? width_di(fwp, fwp->wid - count) : 0;
	return (count);
}

int		normal_ox(t_fwp *fwp, char *s, int64_t di)
{
	int		count;
	int		width;
	int		prec;
	int		temp;
	int		len;

	count = 0;
	len = ft_strlen(s);
	temp = fwp->flag & USELESS_PRE ? 0 : fwp->pre;
	width = fwp->wid - (len > temp ? len : fwp->pre);
	if (fwp->flag & FLAG_HASH && di != 0)
		width -= fwp->flag & EIGHT ? 1 : 2;
	count += for_nm_ox(fwp, di, width);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	prec -= (fwp->flag & FLAG_HASH && fwp->flag & EIGHT) ? 1 : 0;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, s);
	return (count);
}

int		ctc_ox(t_fwp *fwp, va_list *ap)
{
	int64_t	di;
	int64_t	base;
	char	*temp;
	int		count;

	di = signed_modifier(fwp, ap);
	base = reduce_for_ox(fwp);
	di = fwp->flag & TYPE_H ? (unsigned short)di : di;
	di = fwp->flag & TYPE_HH ? (unsigned char)di : di;
	if (fwp->flag & TYPE_J && di < 0)
	{
		if (!(temp = ft_musi_itoa_base((uint64_t)di, base)))
			return (0);
	}
	else if (!(temp = (di < 0 ? ft_musi_itoa_base((unsigned)di, base) \
		: ft_msi_itoa_base(di, base))))
		return (0);
	for_reduce_ox(fwp, temp);
	if (fwp->flag & OX_ZERO && !fwp->wid)
		return (for_zero_ox(fwp, temp, base));
	temp = fwp->flag & SIXUP ? upper_case(temp) : temp;
	count = fwp->flag & FLAG_MINUS ? minus_ox(fwp, temp, di) \
		: normal_ox(fwp, temp, di);
	free(temp);
	return (count);
}
