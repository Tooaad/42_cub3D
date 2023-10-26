/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:39:59 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 19:02:05 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# define WIDTH	1920
# define HEIGHT	1080
# define MINMAP 20
# define RAYS	WIDTH

# define ESC	53
# define DEL	51
# define RIGHT	124
# define LEFT	123
# define W		13
# define A		0
# define S		1
# define D		2

# define PI		3.14159
# define RD		0.0174533

typedef struct s_wall
{
	float			lineH;
	float			lineO;
	float			ty_step;
	float			ty;
	float			tx;
}				t_wall;

typedef struct s_controls
{
	int				right;
	int				left;
	int				w;
	int				a;
	int				s;
	int				d;
}				t_controls;

typedef struct s_texture
{
	int				height;
	int				width;
	unsigned int	*img_adr;
	t_wall			wall;
}				t_texture;

typedef struct s_ray
{
	float			disH;
	float			disV;
	float			X;
	float			Y;
	float			angle;
	float			aView;
	float			nView;
	float			offsetX;
	float			offsetY;
	int				mx;
	int				my;
}					t_ray;

typedef struct s_player
{
	t_controls		controls;
	t_ray			horiz;
	t_ray			vert;
	float			disT;
	float			posX;
	float			posY;
	float			angle;
	float			dposX;
	float			dposY;
}				t_player;

typedef struct s_map
{
	t_texture		*texture_no;
	t_texture		*texture_so;
	t_texture		*texture_we;
	t_texture		*texture_ea;
	char			**grid;
	char			direction;
	int				width;
	int				height;
	int				prop;
}				t_map;

typedef struct s_params
{
	t_player		player;
	t_ray			ray;
	t_map			map;
	char			*line;
	void			*win;
	void			*mlx;
	void			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				floor[3];
	int				ceiling[3];
	char			*img_adr;
	char			*n_path;
	char			*s_path;
	char			*w_path;
	char			*e_path;
	int				vertical;
}					t_params;

// cub3D
void	exit_error(char *str);
void	anti_leaks(t_params	*params);
void	init_params(t_params *params);
void	textures_load(t_params *params);

// parse_data
void	parse_data(char *file, t_params *params);
int		parse_info(t_params *params, int fd, int i);
char	*get_data(t_params *params, char *line, int d);
void	get_data2(t_params *params, char **colour);
void	get_data3(t_params *params, char **colour);
int		parse_info_errors(t_params *params, int skip_lines);
void	get_map_size(t_params *params, char *c, int fd);

// parse_map
void	get_map_values(int skip_lines, int fd, t_params *params);
void	get_row_values(int i, int skip_lines, int fd, t_params *params);
void	check_map(t_map map);
void	check_zeros(t_map map);
void	surrounded(char *c, int i, int j, t_map map);

// manage_window
void	put_pixel(t_params *params, int x, int y, int color);
int		close_win();
void	init_player(t_params *params);
int		refresh_image(t_params *params);
int		build_mlx(t_params *params);

// key_hook
void	init_controls(t_params *params);
int		key_press(int keycode, t_params *params);
int		key_release(int keycode, t_params *params);
void	controls_move(t_params *params);
void	controls_rotate(t_params *params);

// minimap
void	draw_player(t_params *params);
void	paint_square(t_params *params, int x, int y, int colour);
void	draw_grid(t_params *params);
void	draw_map(t_params *params);

// create_rays
void	fix_rays(t_params *params, t_player player, float ra);
void	calculate_distance(t_params *params, float rays, float r);
void	calculate_ray_horizontal(t_params *params, t_ray *ray, float rays);
void	calculate_ray_vertical(t_params *params, t_ray *ray, float rays);
void	trace_ray(t_params *params);

// walls
void	trace_walls(t_params *params, t_texture *texture, float rays, float ra);
void	calculate_walls(t_params *params, t_texture *texture, t_ray ray_t,
			float rays);
void	draw_walls(t_params *params, t_texture *texture, float r);
int		dist_limit(t_params *params, t_ray *ray, int dof, int direc);

// ray_utils
int		roundUp(int numToRound, int multiple);
int		roundDown(int numToRound, int multiple);
float	dist(float ax, float ay, float bx, float by);
// void	join_pixels(t_params *params, int x2, int y2,
// 			int x1, int y1, int colour);

// texture_utils
int		RGBtoHEX(int r, int g, int b);
int		get_tex_colour(t_texture *tex, int x, int y);

#endif