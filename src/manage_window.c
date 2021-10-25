/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:58 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/25 13:53:40 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int close_win(t_params *params)
{
	exit(1);
	mlx_destroy_window(params->mlx, params->win);
	return 1;
}

int	refresh_image(t_params *params)
{
	// put_point(params);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_destroy_image(params->mlx, params->img);
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	// print_params(params);
	return (0);
}

int	build_mlx(t_params *params)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "cub3D");
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	mlx_loop(params->mlx);
	mlx_hook(params->win, 2, 1L<<17, close_win, &params);
	mlx_destroy_window(params->mlx, params->win);
	refresh_image(params);
	mlx_hook(params->win, 2, 2, key_hook, params);
	return (0);
}