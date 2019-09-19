/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:18 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:19 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		pre_s(t_fwp *fwp, char *s)
{
	int		count;
	int		pre_i;

	count = 0;
	pre_i = fwp->pre;
	while (pre_i--)
		ft_putchar(s[count++]);
	return (count);
}

int		minus_s(t_fwp *fwp, char *s, int len)
{
	int		count;
	int		width;

	count = 0;
	if (fwp->pre < len && !(fwp->flag & USELESS_PRE) \
		&& (fwp->flag & PRECISION) && *s)
		count += pre_s(fwp, s);
	else if (*s)
		count += put_di(fwp, s);
	if (fwp->wid > count)
	{
		width = fwp->wid - count;
		count += width_di(fwp, width);
	}
	return (count);
}

int		normal_s(t_fwp *fwp, char *s, int len)
{
	int		count;
	int		width;
	int		prec;
	int		temp;

	prec = (!(fwp->flag & USELESS_PRE) && fwp->flag & PRECISION \
		? fwp->pre : len);
	count = 0;
	temp = prec < len ? prec : len;
	temp = !*s ? 0 : temp;
	width = fwp->wid - temp;
	count += width_di(fwp, width);
	if (prec < len && *s)
		count += pre_s(fwp, s);
	else if (*s)
		count += put_di(fwp, s);
	return (count);
}

int		ctc_s(t_fwp *fwp, va_list *ap)
{
	char	*s;
	int		len;
	int		count;

	count = 0;
	s = va_arg(*ap, char*);
	if (s == NULL)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	if (fwp->flag & FLAG_MINUS)
		count = minus_s(fwp, s, len);
	else
		count = normal_s(fwp, s, len);
	return (count);
}
