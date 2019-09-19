/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:42:04 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:42:07 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	put_pixel(t_mlx *fdf, int x, int y, int color)
{
	int		i;

	if (x >= MENU_X && x < WIN_X && y >= 0 && y < WIN_Y)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->img_addr[i] = color;
		fdf->img_addr[++i] = color >> 8;
		fdf->img_addr[++i] = color >> 16;
	}
}

static void	draw_line(t_point a, t_point b, t_mlx *fdf)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = FT_ABS(b.x - a.x);
	delta.y = FT_ABS(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel(fdf, cur.x, cur.y, get_color(cur, a, b, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

t_point		new_ptr(t_mlx *fdf, t_map *map)
{
	t_point	ptr;

	ptr.x = map->x_1;
	ptr.y = map->y_1;
	ptr.z = map->value;
	ptr.color = gradation_color(fdf, map);
	return (ptr);
}

void		draw(t_mlx *fdf)
{
	t_map	*temp;

	temp = fdf->map;
	ft_bzero(fdf->img_addr, WIN_X * WIN_Y * (fdf->bpp / 8));
	while (temp)
	{
		if (temp->x_1 < fdf->w - 1 && temp->right)
			draw_line(project(new_ptr(fdf, temp), fdf), \
				project(new_ptr(fdf, temp->right), fdf), fdf);
		if ((temp->y_1 != fdf->h - 1) && temp->bottom)
			draw_line(project(new_ptr(fdf, temp), fdf), \
				project(new_ptr(fdf, temp->bottom), fdf), fdf);
		temp = temp->right;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	print_menu(fdf);
}
