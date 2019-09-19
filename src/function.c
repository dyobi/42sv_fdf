/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:46:11 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:46:12 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		close_p(void *param)
{
	(void)param;
	exit(0);
}

void	max_min_v(t_mlx *fdf)
{
	t_map	*temp;

	temp = fdf->map;
	fdf->min_v = 0;
	fdf->max_v = 0;
	fdf->w = 0;
	fdf->h = 0;
	while (temp)
	{
		fdf->min_v = temp->value < fdf->min_v ? temp->value : fdf->min_v;
		fdf->max_v = temp->value > fdf->max_v ? temp->value : fdf->max_v;
		fdf->w = temp->x_1 > fdf->w ? temp->x_1 : fdf->w;
		fdf->h = temp->y_1 > fdf->h ? temp->y_1 : fdf->h;
		temp = temp->right;
	}
	fdf->w += 1;
	fdf->h += 1;
}

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	print_menu(t_mlx *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "\n*- KILKIM -*\n");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Move : < ^ > v");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 35, TEXT_COLOR, "Zoom : + / -");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Altitude : < / >");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Rotate : Mouse");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "ISO : I Key");
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "");
	mlx_string_put(mlx, win, 15, y += 30, TEXT_COLOR, "Parallel : P Key");
}
