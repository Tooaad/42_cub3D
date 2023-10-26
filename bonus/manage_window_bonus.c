/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:58 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 18:13:00 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	put_pixel(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = params->img_adr + (y * params->size_line + x
			* (params->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_win()
{
	exit(1);
}

int	refresh_image(t_params *params)
{
	controls_move(params);
	controls_rotate(params);
	draw_map(params);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_destroy_image(params->mlx, params->img);
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	return (0);
}

void	init_player(t_params *params)
{
	if (params->map.direction == 'N')
		params->player.angle = PI / 2;
	else if (params->map.direction == 'S')
		params->player.angle = 3 * PI / 2;
	else if (params->map.direction == 'W')
		params->player.angle = PI;
	else if (params->map.direction == 'E')
		params->player.angle = 0;
	params->player.dposX = cos(params->player.angle) * 5;
	params->player.dposY = sin(params->player.angle) * 5;
	params->player.posX = params->player.posX * params->map.prop
		+ params->map.prop / 2;
	params->player.posY = params->player.posY * params->map.prop
		+ params->map.prop / 2;
}

int	build_mlx(t_params *params)
{
	init_player(params);
	init_controls(params);
	params->mlx = mlx_init();
	textures_load(params);
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "cub3D");
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	refresh_image(params);
	mlx_hook(params->win, 17, 1L << 17, close_win, &params);
	mlx_hook(params->win, 2, 1L << 0, key_press, params);
	mlx_hook(params->win, 3, 1L << 1, key_release, params);
	mlx_loop_hook(params->mlx, refresh_image, params);
	mlx_loop(params->mlx);
	return (0);
}
