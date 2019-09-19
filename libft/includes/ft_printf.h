/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:49:12 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/02 22:49:14 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

# define FLAG_SPACE 1
# define FLAG_MINUS (1 << 1)
# define FLAG_PLUS (1 << 2)
# define FLAG_ZERO (1 << 3)
# define FLAG_HASH (1 << 4)
# define TYPE_H (1 << 5)
# define TYPE_HH (1 << 6)
# define TYPE_L (1 << 7)
# define TYPE_LL (1 << 8)
# define TYPE_LLL (1 << 9)
# define TYPE_Z (1 << 10)
# define TYPE_J (1 << 11)
# define WIDTH (1 << 12)
# define PRECISION (1 << 13)
# define NU_PRE (1 << 14)
# define PRE_ZERO (1 << 15)
# define USELESS_PRE (1 << 16)
# define SIXUP (1 << 17)
# define SIXDN (1 << 18)
# define EIGHT (1 << 19)
# define F_PLUS (1 << 20)
# define OX_ZERO (1 << 21)
# define UNLONG (1 << 22)
# define SMALLU (1 << 23)
# define F_EXIST (1 << 24)

typedef struct	s_dispatch_table
{
	char	specifier;
	int		(*ft)();
}				t_dt;

typedef struct	s_color_table
{
	char	*color;
	char	*output;
}				t_ct;

typedef struct	s_fwp
{
	va_list	ap;
	int		flag;
	int		wid;
	int		wid_p;
	int		pre;
	int		pre_p;
	int		len;
}				t_fwp;

void			flag_star(t_fwp *fwp, va_list *ap);
void			reset_fwp(t_fwp *fwp);
void			for_reduce_ox(t_fwp *fwp, char *temp);
void			get_prec_reduce_two(t_fwp *fwp, int temp);
void			flag_star_wid(t_fwp *fwp, va_list *ap);
void			flag_star_pre(t_fwp *fwp, va_list *ap);
char			*reduce_for_f(t_fwp *fwp, int64_t right, int prec);
const char		*get_flags(const char *s, t_fwp *fwp);
const char		*get_width(const char *s, t_fwp *fwp);
const char		*get_precision(const char *s, t_fwp *fwp);
const char		*get_modifier(const char *s, t_fwp *fwp);
const char		*get_info(const char *s, t_fwp *fwp);
const char		*get_prec_reduce_one(const char *s, t_fwp *fwp);
const char		*get_wid_reduce(const char *s, t_fwp *fwp);
int				put_color(const char *s);
int				ctc_c(t_fwp *fwp, va_list *ap);
int				ctc_s(t_fwp *fwp, va_list *ap);
int				ctc_di(t_fwp *fwp, va_list *ap);
int				ctc_ox(t_fwp *fwp, va_list *ap);
int				ctc_u(t_fwp *fwp, va_list *ap);
int				ctc_p(t_fwp *fwp, va_list *ap);
int				ctc_z(t_fwp *fwp, va_list *ap);
int				ctc_f(t_fwp *fwp, va_list *ap);
int				ctc_per(t_fwp *fwp, va_list *ap);
int				select_ctc(const char *s, t_fwp *fwp, va_list *ap);
int				ft_printf(const char *format, ...);
int				is_valid(const char *s, t_fwp *fwp, va_list *ap);
int				for_nm_ox(t_fwp *fwp, int64_t di, int width);
int				for_zero_ox(t_fwp *fwp, char *temp, int64_t base);
int				minus_di(int sign);
int				flag_plus_di(int sign);
int				width_di(t_fwp *fwp, int width);
int				flag_space_di(int sign);
int				put_di(t_fwp *fwp, char *s);
int				put_hash(t_fwp *fwp);
int64_t			reduce_for_ox(t_fwp *fwp);
int64_t			signed_modifier(t_fwp *fwp, va_list *ap);

#endif
