/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <kilkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:14:13 by kilkim            #+#    #+#             */
/*   Updated: 2019/08/01 13:14:13 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*e1;
	unsigned char	*e2;

	e1 = (unsigned char*)s1;
	e2 = (unsigned char*)s2;
	while (*e1 == *e2 && *e1 && *e2)
	{
		e1++;
		e2++;
	}
	return (*e1 - *e2);
}
