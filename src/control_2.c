/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:43:57 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:43:59 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	setup_controls(t_mlx *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_p, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}

int		key_press(int key, void *param)
{
	t_mlx	*fdf;

	fdf = (t_mlx*)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS || \
		key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT || \
		key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1 || key == NUM_PAD_2 \
		|| key == MAIN_PAD_2 || key == NUM_PAD_3 || key == MAIN_PAD_3 || \
		key == NUM_PAD_4 || key == MAIN_PAD_4 || key == NUM_PAD_6 || key \
		== MAIN_PAD_6 || key == NUM_PAD_7 || key == MAIN_PAD_7 || key == \
		NUM_PAD_8 || key == MAIN_PAD_8 || key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*fdf;

	(void)x;
	(void)y;
	fdf = (t_mlx*)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_mlx	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_mlx*)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_mlx	*fdf;

	fdf = (t_mlx *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		draw(fdf);
	}
	return (0);
}
