/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:44:05 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:59:51 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		main(int ac, char **av)
{
	t_mlx	*fdf;

	if (ac != 2)
		terminate(ERR_USAGE);
	fdf = init_mlx(open(av[1], O_RDONLY));
	fdf->camera = camera_init(fdf);
	draw(fdf);
	setup_controls(fdf);
	mlx_loop(fdf->mlx);
	fdf_free(fdf);
	return (0);
}
