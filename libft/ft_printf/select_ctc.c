/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_ctc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:35 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:48:37 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_dt		g_dt[] =
{
	{'c', ctc_c},
	{'s', ctc_s},
	{'d', ctc_di},
	{'i', ctc_di},
	{'o', ctc_ox},
	{'x', ctc_ox},
	{'X', ctc_ox},
	{'u', ctc_u},
	{'p', ctc_p},
	{'f', ctc_f},
	{'F', ctc_f},
	{'Z', ctc_z},
	{'U', ctc_u},
	{'%', ctc_per},
	{0, NULL}
};

int64_t		signed_modifier(t_fwp *fwp, va_list *ap)
{
	int64_t	i;

	if ((fwp->flag & TYPE_L || fwp->flag & TYPE_LL) && \
		(fwp->flag & SIXUP || fwp->flag & SIXDN || fwp->flag & EIGHT))
		fwp->flag |= TYPE_J;
	if ((fwp->flag & SMALLU && fwp->flag & TYPE_LL) \
		|| (fwp->flag & UNLONG && fwp->flag & TYPE_LL))
		return (va_arg(*ap, unsigned long long));
	else if (fwp->flag & TYPE_J || fwp->flag & UNLONG)
		return (va_arg(*ap, unsigned long));
	else if (fwp->flag & TYPE_LL)
		return (va_arg(*ap, long long));
	else if (fwp->flag & TYPE_L)
		return (va_arg(*ap, long));
	else if (fwp->flag & TYPE_LLL)
		return (va_arg(*ap, long double));
	else if (fwp->flag & TYPE_Z)
		return (va_arg(*ap, size_t));
	else
		i = va_arg(*ap, int);
	if (fwp->flag & TYPE_H)
		i = (short)i;
	else if (fwp->flag & TYPE_HH)
		i = (char)i;
	return (i);
}

int			select_ctc(const char *s, t_fwp *fwp, va_list *ap)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!*s)
		return (0);
	while (i < 15)
	{
		if (g_dt[i].specifier == *s)
		{
			len = g_dt[i].ft(fwp, ap);
			break ;
		}
		i++;
	}
	return (len);
}
