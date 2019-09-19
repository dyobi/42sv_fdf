/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sucknorm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:49:21 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:49:24 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*get_prec_reduce_one(const char *s, t_fwp *fwp)
{
	if (*s == '*')
	{
		fwp->pre_p = 1;
		s++;
	}
	return (s);
}

void		reset_fwp(t_fwp *fwp)
{
	fwp->flag = 0;
	fwp->wid = 0;
	fwp->wid_p = 0;
	fwp->pre = 0;
	fwp->pre_p = 0;
}

int			for_nm_ox(t_fwp *fwp, int64_t di, int width)
{
	int		count;

	count = 0;
	if (fwp->flag & FLAG_ZERO)
	{
		count += di != 0 ? put_hash(fwp) : 0;
		count += width_di(fwp, width);
	}
	else
	{
		count += width_di(fwp, width);
		count += di != 0 ? put_hash(fwp) : 0;
	}
	return (count);
}

int			for_zero_ox(t_fwp *fwp, char *temp, int64_t base)
{
	int		count;

	count = 0;
	if ((count = (fwp->flag & FLAG_HASH && base == 8) ? 1 : 0))
		ft_putchar('0');
	free(temp);
	return (count);
}

void		for_reduce_ox(t_fwp *fwp, char *temp)
{
	if (temp[0] == '0' && temp[1] == '\0' && fwp->flag & PRECISION \
		&& fwp->pre == 0)
		fwp->flag |= OX_ZERO;
}
