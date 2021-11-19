/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:51 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/19 20:30:53 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	put_pixel(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = params->img_adr + (y * params->size_line + x
			* (params->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_player(t_params *params)
{
	int	x;
	int	y;
	int	minmap_prop;

	minmap_prop = (params->map.prop * MINMAP / 100);
	x = params->player.posX * minmap_prop / params->map.prop - 4;
	while (x++ < params->player.posX * minmap_prop / params->map.prop + 4)
	{
		y = params->player.posY * minmap_prop / params->map.prop - 4;
		while (y++ < params->player.posY * minmap_prop / params->map.prop + 4)
			if (x + 8 < WIDTH && x > 0 && y + 8 < HEIGHT && y > 0)
				put_pixel(params, x, y, 0x1600FF);
	}
}

void	paint_square(t_params *params, int x, int y, int colour)
{
	int	xo;
	int	yo;
	int	minmap_prop;


	minmap_prop = (params->map.prop * MINMAP / 100);
	yo = y * minmap_prop;
	while (yo++ < y * minmap_prop + minmap_prop)
	{
		xo = x * minmap_prop;
		while (xo++ < x * minmap_prop + minmap_prop)
			put_pixel(params, xo, yo, colour);
	}
}

void	draw_grid(t_params *params)
{
	int	x;
	int	y;
	int	colour;

	y = -1;
	colour = -1;
	while (++y < params->map.height)
	{
		x = -1;
		while (++x < params->map.width)
		{
			if (params->map.grid[y][x] == '1')
				colour = 0xFFFFFF;
			else
				colour = 0x000000;
			if (colour != -1)
				paint_square(params, x, y, colour);
		}
	}
}

void	draw_map(t_params *params)
{
	trace_ray(params);
	draw_grid(params);
	draw_player(params);
}
