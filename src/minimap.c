/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:51 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/29 17:04:41 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	paint_background(t_params *params, int colour)
{
	int	x;
	int	y;

	x = -1;
	while(++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			put_pixel(params, x, y, colour);
		}
	}
}

void	put_pixel(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = params->img_adr + (y * params->size_line + x * (params->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_player(t_params *params)
{
	int	x;
	int	y;

	x = params->player.posX - 4;
	while (x++ < params->player.posX + 4)
	{
		y = params->player.posY - 4;
		while (y++ < params->player.posY + 4)
		{
			if (x + 4 < WIDTH && x - 4 > 0 && y + 4 < HEIGHT && y - 4 > 0)
				put_pixel(params, x, y, 0x1600FF);
		}
	}
}

void	paint_square(t_params *params, int x, int y, int colour)
{
	int	xo;
	int	yo;

	yo = y * (HEIGHT / params->map.width) + 1;
	while (yo++ < (y * (HEIGHT / params->map.width) + (HEIGHT / params->map.width) - 1))
	{
		xo = x * (HEIGHT / params->map.width) + 1;
		while (xo++ < (x * (HEIGHT / params->map.width) + (HEIGHT / params->map.width) - 1))
		{
			put_pixel(params, xo, yo, colour);
		}
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
				colour = 0x000000;
			else
				colour = 0xFFFFFF;
			printf("painting %d, %d with %c\n", x, y, params->map.grid[y][x]);
			if (colour != -1)
				paint_square(params, x, y, colour);
		}
	}
}

void	draw_map(t_params *params)
{
	paint_background(params, 0x9B9B9B);
	draw_grid(params);
	draw_player(params);
}