/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:47:49 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/03 10:28:26 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const char	*get_flags(const char *s, t_fwp *fwp)
{
	while (*s == ' ' || *s == '-' || *s == '+' || *s == '0' || *s == '#')
	{
		if (*s == ' ')
			fwp->flag |= FLAG_SPACE;
		else if (*s == '-')
			fwp->flag |= FLAG_MINUS;
		else if (*s == '+')
			fwp->flag |= FLAG_PLUS;
		else if (*s == '0')
			fwp->flag |= FLAG_ZERO;
		else if (*s == '#')
			fwp->flag |= FLAG_HASH;
		s++;
	}
	return (s);
}

const char	*get_width(const char *s, t_fwp *fwp)
{
	if (*s == '*')
	{
		fwp->wid_p = 1;
		s++;
	}
	if (*s == '-')
	{
		fwp->flag |= FLAG_MINUS;
		s++;
	}
	s = get_wid_reduce(s, fwp);
	if (*s == '*')
	{
		fwp->wid_p = 1;
		s++;
	}
	return (s);
}

const char	*get_precision(const char *s, t_fwp *fwp)
{
	int		temp;

	if (*s == '.')
	{
		fwp->flag |= PRECISION;
		s++;
		s = get_prec_reduce_one(s, fwp);
		temp = 0;
		while (*s >= 48 && *s <= 57)
		{
			fwp->flag |= NU_PRE;
			temp = temp * 10 + *s - 48;
			s++;
		}
		if ((!(fwp->flag & NU_PRE) && !fwp->pre_p) || \
			(fwp->flag & NU_PRE && temp == 0))
			fwp->flag |= PRE_ZERO;
		get_prec_reduce_two(fwp, temp);
		s = get_prec_reduce_one(s, fwp);
	}
	return (s);
}

const char	*get_modifier(const char *s, t_fwp *fwp)
{
	while (*s == 'j' || *s == 'h' || *s == 'l' || *s == 'z' || \
			*s == 'L')
	{
		if (*s == 'j' && *(s++))
			fwp->flag |= TYPE_J;
		else if (*s == 'h' && *(s + 1) == 'h' && *(s++) && *(s++))
			fwp->flag |= TYPE_HH;
		else if (*s == 'h' && *(s++))
			fwp->flag |= TYPE_H;
		else if (*s == 'l' && *(s + 1) == 'l' && *(s++) && *(s++))
			fwp->flag |= TYPE_LL;
		else if (*s == 'l' && *(s++))
			fwp->flag |= TYPE_L;
		else if (*s == 'z' && *(s++))
			fwp->flag |= TYPE_Z;
		else if (*s == 'L' && *(s++))
			fwp->flag |= TYPE_LLL;
	}
	return (s);
}

const char	*get_info(const char *s, t_fwp *fwp)
{
	reset_fwp(fwp);
	while (*s == ' ' || *s == '-' || *s == '+' || *s == '#' || *s == '0' \
			|| *s == 'j' || *s == 'h' || *s == 'l' || *s == 'z' || \
			*s == 'L' || (*s >= 48 && *s <= 57) || *s == '.' || *s == '*')
	{
		s = get_flags(s, fwp);
		s = get_modifier(s, fwp);
		s = get_width(s, fwp);
		s = get_precision(s, fwp);
	}
	return (s);
}
