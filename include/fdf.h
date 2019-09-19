/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:38:24 by kilkim            #+#    #+#             */
/*   Updated: 2019/09/08 04:58:07 by kilkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>
# include <limits.h>

# define FT_MIN(A, B) (((A) < (B)) ? (A) : (B))
# define FT_MAX(A, B) (((A) > (B)) ? (A) : (B))
# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define WIN_T "LUKE'S WORLD"
# define WIN_X 1280
# define WIN_Y 720
# define MENU_X 220

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP			"Incorrect MAP_FILE"
# define ERR_MAP_INIT		"Map initialization error"
# define ERR_FDF_INIT		"FdF initialization error"
# define ERR_CAMERA_INIT	"Camera initialization error"

# define TEXT_COLOR			0xFFFFFF
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x222222

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	2
# define MOUSE_THIRD_BUTTON	3
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124

# define NUM_PAD_0			82
# define NUM_PAD_1			83
# define NUM_PAD_2			84
# define NUM_PAD_3			85
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define NUM_PAD_7			89
# define NUM_PAD_8			91
# define NUM_PAD_9			92
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78

# define MAIN_PAD_ESC		53
# define MAIN_PAD_I			34
# define MAIN_PAD_P			35
# define MAIN_PAD_0			29
# define MAIN_PAD_1			18
# define MAIN_PAD_2			19
# define MAIN_PAD_3			20
# define MAIN_PAD_4			21
# define MAIN_PAD_5			23
# define MAIN_PAD_6			22
# define MAIN_PAD_7			26
# define MAIN_PAD_8			28
# define MAIN_PAD_9			25
# define MAIN_PAD_PLUS		24
# define MAIN_PAD_MINUS		27
# define MAIN_PAD_LESS		43
# define MAIN_PAD_MORE		47

typedef enum
{
	false,
	true
}	t_bool;

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}				t_point;

typedef struct	s_camera
{
	t_projection	projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
}				t_camera;

typedef struct	s_mouse
{
	char			is_pressed;
	int				x;
	int				y;
	int				previous_x;
	int				previous_y;
}				t_mouse;

typedef struct	s_map
{
	int				value;
	int				x_1;
	int				y_1;
	int				x_2;
	int				y_2;
	int				index;
	struct s_map	*left;
	struct s_map	*right;
	struct s_map	*top;
	struct s_map	*bottom;
}				t_map;

typedef struct	s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				size_line;
	int				endian;
	int				min_v;
	int				max_v;
	int				w;
	int				h;
	struct s_map	*map;
	struct s_camera	*camera;
	struct s_mouse	*mouse;
}				t_mlx;

t_map			*make_map(t_map *map, int value, int x, int y);
t_map			*init_map(t_map *map, const int fd);
t_mlx			*init_mlx(const int fd);
t_point			new_ptr(t_mlx *fdf, t_map *map);
t_point			project(t_point p, t_mlx *fdf);
t_camera		*camera_init(t_mlx *fdf);
int				main(int ac, char **av);
int				gradation_color(t_mlx *fdf, t_map *map);
int				get_light(int start, int end, double per);
int				get_color(t_point curr, t_point s, t_point e, t_point delta);
int				close_p(void *param);
int				key_press(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
double			percent(int start, int end, int current);
void			draw(t_mlx *fdf);
void			set_map_1(t_map *map, int value, int x, int y);
void			set_map_2(t_map *map);
void			zoom(int key, t_mlx *fdf);
void			move(int key, t_mlx *fdf);
void			rotate(int key, t_mlx *fdf);
void			flatten(int key, t_mlx *fdf);
void			change_projection(int key, t_mlx *fdf);
void			strpp_free(char **str);
void			setup_controls(t_mlx *fdf);
void			max_min_v(t_mlx *fdf);
void			print_menu(t_mlx *fdf);
void			terminate(char *s);
void			fdf_free(t_mlx *fdf);

#endif
