/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 04:44:32 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:44:33 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_map_1(t_map *map, int value, int x, int y)
{
	static int	index = 0;

	map->value = value;
	map->x_1 = x;
	map->y_1 = y;
	map->x_2 = 0;
	map->y_2 = 0;
	map->index = index++;
	map->right = NULL;
	map->top = NULL;
	map->bottom = NULL;
}

void	set_map_2(t_map *map)
{
	t_map	*temp_top;
	t_map	*temp_bot;

	temp_top = map;
	temp_bot = map;
	while (temp_top->bottom)
	{
		temp_top = temp_top->right;
		temp_bot = temp_bot->right;
	}
	if ((temp_bot = temp_bot->right) == NULL)
		terminate(ERR_MAP_INIT);
	while (temp_bot && (temp_bot->y_1 != temp_top->y_1 + 1))
		temp_bot = temp_bot->right;
	while (temp_bot)
	{
		temp_bot->top = temp_top;
		temp_top->bottom = temp_bot;
		temp_top = temp_top->right;
		temp_bot = temp_bot->right;
	}
}

t_map	*make_map(t_map *map, int value, int x, int y)
{
	t_map		*curr;
	t_map		*temp;

	temp = map;
	if (!(curr = (t_map*)ft_memalloc(sizeof(t_map))))
		terminate(ERR_MAP_INIT);
	set_map_1(curr, value, x, y);
	if (!map)
	{
		curr->left = NULL;
		temp = curr;
	}
	else
	{
		while (map->right)
			map = map->right;
		curr->left = map;
		map->right = curr;
		map->x_2 = curr->x_1;
		map->y_2 = curr->y_2;
	}
	return (temp);
}

t_map	*init_map(t_map *map, const int fd)
{
	char	**temp;
	char	*line;
	int		i;
	int		x;
	int		y;

	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		temp = ft_strsplit(line, ' ');
		i = -1;
		x = 0;
		while (temp[++i])
		{
			if (!(map = make_map(map, ft_atoi(temp[i]), x++, y)))
				terminate(ERR_MAP_INIT);
		}
		strpp_free(temp);
		free(line);
		y++;
	}
	set_map_2(map);
	return (map);
}

t_mlx	*init_mlx(const int fd)
{
	t_mlx	*fdf;

	if (!(fdf = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		terminate(ERR_FDF_INIT);
	if (!(fdf->mlx = mlx_init()))
		terminate(ERR_FDF_INIT);
	if (!(fdf->win = mlx_new_window(fdf->mlx, WIN_X, WIN_Y, WIN_T)))
		terminate(ERR_FDF_INIT);
	if (!(fdf->img = mlx_new_image(fdf->mlx, WIN_X, WIN_Y)))
		terminate(ERR_FDF_INIT);
	if (!(fdf->img_addr = mlx_get_data_addr(fdf->img, &(fdf->bpp), \
		&(fdf->size_line), &(fdf->endian))))
		terminate(ERR_FDF_INIT);
	if (!(fdf->map = init_map(fdf->map, fd)))
		terminate(ERR_MAP_INIT);
	if (!(fdf->mouse = (t_mouse*)ft_memalloc(sizeof(t_mouse))))
		terminate(ERR_FDF_INIT);
	max_min_v(fdf);
	return (fdf);
}
