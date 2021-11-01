/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:51 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/01 13:03:53 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	put_pixel(t_params *params, int x, int y, int color)
{
	char	*dst;

	dst = params->img_adr + (y * params->size_line + x
		* (params->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
				put_pixel(params, y, x, 0x1600FF);
		}
	}
}

void	paint_square(t_params *params, int x, int y, int colour)
{
	int	xo;
	int	yo;

	yo = y * params->map.prop + 1;
	while (yo++ < y * params->map.prop + (params->map.prop - 1))
	{
		xo = x * params->map.prop + 1;
		while (xo++ < x * params->map.prop + (params->map.prop - 1))
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
				colour = 0xFFFFFF;	
			else
				colour = 0x000000;
			if (colour != -1)
				paint_square(params, x, y, colour);
		}
	}
}

void	draw_ray(t_params *params)
{
	int	x;
	int	y;
	int	colour;

	y = params->player.posY;
	colour = 0x008F39;
	// while (++y < params->ray.Y)
	// {
		x = params->player.posX;
	// 	while (++x < params->ray.Y)
	// 	{
			// put_pixel(params, x, y, colour);
			// put_pixel(params, x+1, y, colour);
			// put_pixel(params, x, y+1, colour);
			// put_pixel(params, x-1, y, colour);
			// put_pixel(params, x, y-1, colour);
			// put_pixel(params, x+2, y, colour);
			// put_pixel(params, x, y+2, colour);
			// put_pixel(params, x-2, y, colour);
			// put_pixel(params, x, y-2, colour);
			// put_pixel(params, x+1, y+1, colour);
	// 	}
	// }

}

void	draw_map(t_params *params)
{
	paint_background(params, 0x9B9B9B);
	draw_grid(params);
	draw_player(params);
	trace_ray(params);
	// draw_ray(params);
}