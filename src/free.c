/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:45:44 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:56:30 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	strpp_free(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
}

void	map_free(t_map *map)
{
	while (map->right)
	{
		map->left = NULL;
		map->top = NULL;
		map->bottom = NULL;
		map = map->right;
		free(map->left);
	}
	map->left = NULL;
	map->top = NULL;
	map->bottom = NULL;
	free(map);
}

void	fdf_free(t_mlx *fdf)
{
	map_free(fdf->map);
	free(fdf->camera);
	free(fdf->mouse);
	free(fdf);
}
