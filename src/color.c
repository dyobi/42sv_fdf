/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:46:04 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:46:06 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

double	percent(int start, int end, int current)
{
	double	place;
	double	dist;

	place = current - start;
	dist = end - start;
	return ((dist == 0) ? 1.0 : (place / dist));
}

int		gradation_color(t_mlx *fdf, t_map *map)
{
	double	per;

	per = percent(fdf->min_v, fdf->max_v, map->value);
	if (per < 0.2)
		return (COLOR_DISCO);
	else if (per < 0.4)
		return (COLOR_BRICK_RED);
	else if (per < 0.6)
		return (COLOR_FLAMINGO);
	else if (per < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int		get_light(int start, int end, double per)
{
	return ((int)((1 - per) * start + per * end));
}

int		get_color(t_point curr, t_point s, t_point e, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	per;

	if (curr.color == e.color)
		return (curr.color);
	if (delta.x > delta.y)
		per = percent(s.x, e.x, curr.x);
	else
		per = percent(s.y, e.y, curr.y);
	red = get_light((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, per);
	green = get_light((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, per);
	blue = get_light(s.color & 0xFF, e.color & 0xFF, per);
	return ((red << 16) | (green << 8) | blue);
}
