/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:39:59 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/17 11:19:35 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <mlx.h> 

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct s_map
{
	t_point			***grid;
	int				width;
	int				height;
}					t_map;

typedef struct s_params
{
	t_map			*map;
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
void	parse_map(char *file, t_map *map, t_params	*params);
