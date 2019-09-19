/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:44:45 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:44:46 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	rot_x(int *y, int *z, double alpha)
{
	int pre_y;

	pre_y = *y;
	*y = pre_y * cos(alpha) + *z * sin(alpha);
	*z = -pre_y * sin(alpha) + *z * cos(alpha);
}

static void	rot_y(int *x, int *z, double beta)
{
	int pre_x;

	pre_x = *x;
	*x = pre_x * cos(beta) + *z * sin(beta);
	*z = -pre_x * sin(beta) + *z * cos(beta);
}

static void	rot_z(int *x, int *y, double gamma)
{
	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = pre_x * cos(gamma) - pre_y * sin(gamma);
	*y = pre_x * sin(gamma) + pre_y * cos(gamma);
}

static void	iso(int *x, int *y, int z)
{
	int pre_x;
	int pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x - pre_y) * cos(0.523599);
	*y = -z + (pre_x + pre_y) * sin(0.523599);
}

t_point		project(t_point p, t_mlx *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->w * fdf->camera->zoom) / 2;
	p.y -= (fdf->h * fdf->camera->zoom) / 2;
	rot_x(&p.y, &p.z, fdf->camera->alpha);
	rot_y(&p.x, &p.z, fdf->camera->beta);
	rot_z(&p.x, &p.y, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIN_X - MENU_X) / 2 + fdf->camera->x_offset + MENU_X;
	p.y += (WIN_Y + fdf->h * fdf->camera->zoom) / 2 + fdf->camera->y_offset;
	return (p);
}
