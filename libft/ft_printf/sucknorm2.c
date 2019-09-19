/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sucknorm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:27:28 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/03 10:27:30 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*get_wid_reduce(const char *s, t_fwp *fwp)
{
	int		temp;

	temp = 0;
	while (*s >= 48 && *s <= 57)
	{
		fwp->flag |= WIDTH;
		temp = temp * 10 + *s - 48;
		s++;
	}
	fwp->wid = temp > fwp->wid ? temp : fwp->wid;
	return (s);
}

void		get_prec_reduce_two(t_fwp *fwp, int temp)
{
	if (!(fwp->flag & PRE_ZERO))
	{
		if (fwp->pre != 0)
			fwp->pre = fwp->pre > temp ? temp : fwp->pre;
		else
			fwp->pre = temp;
	}
}

int64_t		reduce_for_ox(t_fwp *fwp)
{
	int64_t	base;

	base = fwp->flag & EIGHT ? 8 : 16;
	if (fwp->flag & PRECISION && !(fwp->flag & USELESS_PRE))
		fwp->flag &= ~FLAG_ZERO;
	return (base);
}

char		*reduce_for_f(t_fwp *fwp, int64_t right, int prec)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = fwp->flag & F_PLUS ? prec + 1 : prec;
	if (right == 0 && prec && !(fwp->flag & F_PLUS))
	{
		if (!(temp = ft_strnew(prec)))
			return (NULL);
		while (prec-- > 0)
			temp[i++] = '0';
	}
	else
	{
		if (!(temp = ft_strnew(j)))
			return (NULL);
		while (j-- > 0)
		{
			temp[j] = right % 10 + '0';
			right /= 10;
		}
	}
	return (temp);
}
