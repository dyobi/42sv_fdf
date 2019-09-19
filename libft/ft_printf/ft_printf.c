/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:48:28 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/04 23:40:18 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_star_wid(t_fwp *fwp, va_list *ap)
{
	int		width;

	if (fwp->wid_p)
	{
		width = va_arg(*ap, int);
		if (!(fwp->flag & WIDTH))
		{
			if (width < 0)
			{
				width *= -1;
				fwp->flag |= FLAG_MINUS;
			}
			fwp->wid = width;
		}
	}
}

void	flag_star_pre(t_fwp *fwp, va_list *ap)
{
	int		precision;

	if (fwp->pre_p)
	{
		precision = va_arg(*ap, int);
		if (!(fwp->flag & NU_PRE))
		{
			if (precision < 0)
			{
				fwp->flag |= USELESS_PRE;
				fwp->pre = 6;
			}
			else
				fwp->pre = precision;
		}
	}
}

int		is_valid(const char *s, t_fwp *fwp, va_list *ap)
{
	flag_star_wid(fwp, ap);
	flag_star_pre(fwp, ap);
	if (*s == 'U')
		fwp->flag |= UNLONG;
	else if (*s == 'u')
		fwp->flag |= SMALLU;
	else if (*s == 'x')
		fwp->flag |= SIXDN;
	else if (*s == 'X')
		fwp->flag |= SIXUP;
	else if (*s == 'o')
		fwp->flag |= EIGHT;
	if (*s == 'd' || *s == 'x' || *s == 'X' || *s == 'f' || *s == 'i' ||\
			*s == 'c' || *s == 'o' || *s == 's' || *s == 'Z' || \
			*s == 'u' || *s == 'p' || *s == '%' || *s == 'U')
		return (1);
	return (0);
}

int		fpf_main(const char *s, va_list *ap, t_fwp *fwp)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s = get_info(++s, fwp);
			if (!is_valid(s, fwp, ap))
				break ;
			fwp->len += select_ctc(s, fwp, ap);
		}
		else if (*s == '{' && (i = put_color(s)))
			s = s + i + 1;
		else
		{
			ft_putchar(*s);
			fwp->len++;
		}
		s++;
	}
	return (fwp->len);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_fwp	fwp;
	int		count;

	ft_bzero(&fwp, sizeof(t_fwp));
	va_start(ap, format);
	count = fpf_main(format, &ap, &fwp);
	va_end(ap);
	return (count);
}
