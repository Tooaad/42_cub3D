/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:39:59 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/29 16:32:45 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# define WIDTH	1960
# define HEIGHT	1080
# define ESC	53
# define DEL	51
# define RIGHT	124
# define LEFT	123
# define W		13
# define A		0
# define S		1
# define D		2

# define PI		3.1459265

typedef struct s_camera
{
	double			dX;
	double			dY;
	double			c_angle;
}				t_camera;

typedef struct s_player
{
	double			posX;		// Start
	double			posY;
	double			dirX;		// init direction 
	double			dirY;
	double			planeX;		// FOV
	double			planeY;
	double			time; 
	double			oldtime;
}				t_player;

typedef struct s_map
{
	char			**grid;
	char			direction;
	int				width;
	int				height;
}					t_map;

typedef struct s_params
{
	t_camera		camera;
	t_player		player;
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
int		refresh_image(t_params *params);
int		build_mlx(t_params *params);
//
int		key_hook(int keycode, t_params *params);
void	key_hook1(int keycode, t_params *params);
void	key_hook2(int keycode, t_params *params);
void	key_hook3(int keycode, t_params *params);
void	key_hook4(int keycode, t_params *params);

//
void	paint_background(t_params *params, int colour);
void	put_pixel(t_params *params, int x, int y, int color);
void	draw_player(t_params *params);
void	paint_square(t_params *params, int x, int y, int colour);
void	draw_grid(t_params *params);
void	draw_map(t_params *params);