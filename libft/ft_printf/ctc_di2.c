/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_di2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:48 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:49 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		flag_minus_di(t_fwp *fwp, char *temp, int len, int sign)
{
	int		count;
	int		prec;

	count = minus_di(sign);
	count += ((fwp->flag & FLAG_SPACE) && !(fwp->flag & FLAG_PLUS)) \
		? flag_space_di(sign) : 0;
	count += (fwp->flag & FLAG_PLUS) ? flag_plus_di(sign) : 0;
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += put_di(fwp, temp);
	count += ((fwp->wid - count) > 0) ? width_di(fwp, fwp->wid - count) : 0;
	return (count);
}

int		flagcase_di(t_fwp *fwp, int width, int sign)
{
	int		count;

	count = 0;
	if (fwp->flag & FLAG_ZERO)
	{
		count += minus_di(sign);
		count += ((fwp->flag & FLAG_SPACE) && !(fwp->flag & FLAG_PLUS)) \
			? flag_space_di(sign) : 0;
		count += (fwp->flag & FLAG_PLUS) ? flag_plus_di(sign) : 0;
		count += width_di(fwp, width);
	}
	else
	{
		count += ((fwp->flag & FLAG_SPACE) && !(fwp->flag & FLAG_PLUS)) \
			? flag_space_di(sign) : 0;
		count += width_di(fwp, width);
		count += (fwp->flag & FLAG_PLUS) ? flag_plus_di(sign) : 0;
		count += minus_di(sign);
	}
	return (count);
}

int		normal_di(t_fwp *fwp, char *temp, int len, int sign)
{
	int		count;
	int		width;
	int		prec;
	int		tm;

	count = 0;
	if (!(fwp->flag & USELESS_PRE) && (fwp->flag & PRECISION) &&\
		fwp->pre == 0 && temp[0] == '0' && temp[1] == '\0')
		len = 0;
	tm = fwp->flag & USELESS_PRE ? 0 : fwp->pre;
	width = fwp->wid - (len > tm ? len : fwp->pre);
	width -= sign ? 1 : 0;
	width -= (!sign && fwp->flag & FLAG_SPACE && \
		!(fwp->flag & FLAG_PLUS)) ? 1 : 0;
	width -= ((fwp->flag & FLAG_PLUS) && !sign) ? 1 : 0;
	count += flagcase_di(fwp, width, sign);
	prec = (fwp->flag & USELESS_PRE ? 0 : fwp->pre) - len;
	count += prec > 0 ? prec : 0;
	while (prec-- > 0)
		ft_putchar('0');
	count += (len ? put_di(fwp, temp) : 0);
	return (count);
}

int		ctc_di(t_fwp *fwp, va_list *ap)
{
	int64_t		di;
	char		*temp;
	int			len;
	int			count;
	int			sign;

	di = signed_modifier(fwp, ap);
	sign = di < 0 ? 1 : 0;
	if (fwp->flag & PRECISION && !(fwp->flag & USELESS_PRE))
		fwp->flag &= ~FLAG_ZERO;
	if (!(temp = (di < 0 ? ft_musi_itoa_base(-(uint64_t)di, 10) : \
		ft_msi_itoa_base(di, 10))))
		return (0);
	len = ft_msi_len(di);
	if (fwp->flag & FLAG_MINUS)
		count = flag_minus_di(fwp, temp, len, sign);
	else
		count = normal_di(fwp, temp, len, sign);
	free(temp);
	return (count);
}
