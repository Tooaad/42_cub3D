/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:39:59 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/16 18:59:48 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H 
# define CUB3D_H

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
# define MINMAP 30
# define RAYS	60

# define ESC	53
# define DEL	51
# define RIGHT	124
# define LEFT	123
# define W		13
# define A		0
# define S		1
# define D		2

# define PI		3.14159265
# define RD		0.0174533

typedef struct	s_texture
{
	int				height;
	int				width;
	char			*img_adr;
	void			*ima_ptr;
}				t_texture;

typedef struct	s_ray
{
	double			X;
	double			Y;
	double			angle;
	double			aView;
	double			nView;
	int				mx;
	int				my;
	double			offsetX;
	double			offsetY;
}				t_ray;

typedef struct s_player
{
	double			posX;		// Start Position
	double			posY;
	double			angle;		// Player angle	
	double			dposX;		// Start Rotation
	double			dposY;
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
}					t_params;

//
void	exit_error(char *str);
void	textures_load(t_params *params);
//
void	parse_data(char *file, t_params *params);
int		parse_info(t_params *params, int fd);
char	*get_data(char *line, int d);
int		parse_info_errors(t_params *params, int skip_lines);
void	get_map_size(int fd, t_params *params);
//
void	get_map_values(int skip_lines, int fd, t_params *params);
void	get_row_values(int i, int skip_lines, int fd, t_params *params);
void	check_map(t_map map);
void	check_zeros(t_map map);
void	surrounded(char *c, int i, int j, t_map map);
//
void    init_player(t_params *params);
int		refresh_image(t_params *params);
int		build_mlx(t_params *params);
//
int		key_hook(int keycode, t_params *params);
void	key_hook1(int keycode, t_params *params);
void	key_hook2(int keycode, t_params *params);

//
void	paint_background(t_params *params, int colour);
void	put_pixel(t_params *params, int x, int y, int color);
void	draw_player(t_params *params);
void	paint_square(t_params *params, int x, int y, int colour);
void	draw_grid(t_params *params);
void	draw_ray(t_params *params);
void	draw_map(t_params *params);

//
void	calculate_ray_horizontal(t_params *params, t_ray *ray, double rays);
void	calculate_ray_vertical(t_params *params, t_ray *ray, double rays);
void	trace_ray(t_params *params);
void	join_pixels(t_params *params, int x2, int y2, int x1, int y1, int colour);
void 	join_pixels_texture(t_params *params, int x0, int y0, int x1, int y1, int colour);
int		roundUp(int numToRound, int multiple);
int		roundDown(int numToRound, int multiple);
float	dist(double ax, double ay, double bx, double by);

//
void	persp(t_params *params, double rays, double ra, double disT, t_texture *texture, t_ray ray_t);
int		RGBtoHEX(int *RGB);
int		get_tex_colour(t_texture *tex, int x, int y);

#endif