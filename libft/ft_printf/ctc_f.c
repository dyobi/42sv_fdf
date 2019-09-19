/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctc_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:47:16 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:47:20 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long double	read_f(t_fwp *fwp, va_list *ap)
{
	long double	ld;

	if (fwp->flag & TYPE_LLL)
		ld = va_arg(*ap, long double);
	else
		ld = (long double)va_arg(*ap, double);
	return (ld);
}

char		*rounding_off(t_fwp *fwp, long double right)
{
	int64_t	rightt;
	char	*temp;
	int		prec;
	int		tmp;

	prec = (fwp->flag & PRECISION) ? fwp->pre : 6;
	tmp = prec + 1;
	while (tmp-- > 0)
		right *= 10;
	right += 5;
	rightt = (int64_t)right / 10;
	rightt = rightt > 0 ? rightt : -rightt;
	if (rightt != 0 && ft_msi_len(rightt) == prec + 1)
		fwp->flag |= F_PLUS;
	if (!(temp = reduce_for_f(fwp, rightt, prec)))
		return (NULL);
	return (temp);
}

int			minus_f(t_fwp *fwp, char *right, char *left, int sign)
{
	int		count;
	int		i;

	count = minus_di(sign);
	count += ((fwp->flag & FLAG_SPACE) && !(fwp->flag & FLAG_PLUS)) \
		? flag_space_di(sign) : 0;
	count += (fwp->flag & FLAG_PLUS) ? flag_plus_di(sign) : 0;
	count += put_di(fwp, left);
	if (fwp->pre)
	{
		count += 1;
		ft_putchar('.');
	}
	i = (fwp->flag & F_PLUS) ? 1 : 0;
	count += put_di(fwp, &right[i]);
	count += width_di(fwp, fwp->wid - count);
	return (count);
}

int			normal_f(t_fwp *fwp, char *right, char *left, int sign)
{
	int		count;
	int		width;
	int		i;

	count = 0;
	count += ((fwp->flag & FLAG_SPACE) && !(fwp->flag & FLAG_PLUS)) \
		? flag_space_di(sign) : 0;
	count += (fwp->flag & FLAG_PLUS) ? flag_plus_di(sign) : 0;
	width = fwp->wid - count - ft_strlen(left) - ft_strlen(right) + \
		(fwp->flag & F_PLUS ? 1 : 0) - ((fwp->flag & PRECISION && fwp->pre) \
		? 1 : 0) - (!(fwp->flag & PRECISION) ? 1 : 0) - (sign ? 1 : 0);
	count += width_di(fwp, width);
	count += minus_di(sign);
	count += put_di(fwp, left);
	if ((fwp->flag & PRECISION && fwp->pre) || !(fwp->flag & PRECISION) || \
		fwp->flag & FLAG_HASH)
	{
		count += 1;
		ft_putchar('.');
	}
	i = (fwp->flag & F_PLUS) ? 1 : 0;
	count += put_di(fwp, &right[i]);
	return (count);
}

int			ctc_f(t_fwp *fwp, va_list *ap)
{
	int64_t		left;
	long double	right;
	char		*lef;
	char		*rig;
	int			sign;

	right = read_f(fwp, ap);
	fwp->flag |= right ? F_EXIST : 0;
	sign = right >= 0 ? 0 : 1;
	left = (int64_t)right;
	right = (right - left) > 0 ? right - left : left - right;
	left = left >= 0 ? left : -left;
	if (!(rig = rounding_off(fwp, right)))
		return (0);
	left += (fwp->flag & F_PLUS) ? 1 : 0;
	if (!(lef = ft_msi_itoa_base(left, 10)))
		return (0);
	if (fwp->flag & FLAG_MINUS)
		left = (int64_t)minus_f(fwp, rig, lef, sign);
	else
		left = (int64_t)normal_f(fwp, rig, lef, sign);
	free(rig);
	free(lef);
	return ((int)left);
}
