/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:06 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/01 16:34:14 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void trace_ray(t_params *params)
{
	int r;
	int maxView;
	int mx;
	int my;
	int mi;
	int mj;

	r = 0;
	params->ray.angle = params->player.angle;
	while (r < 1)
	{
		// Horizontal lines
		maxView = 0;
		params->ray.aView = -1 / tan(params->ray.angle);
		if (params->ray.angle > PI)
		{
			put_pixel(params, 1, 1, 0x00FF00);
			put_pixel(params, 1, 2, 0x00FF00);
			put_pixel(params, 2, 1, 0x00FF00);
			put_pixel(params, 2, 2, 0x00FF00);
			put_pixel(params, 2, 3, 0x00FF00);
			put_pixel(params, 3, 2, 0x00FF00);
			params->ray.X = ((params->player.posX / params->map.prop) * params->map.prop) - 0.0001;
			params->ray.Y = (params->player.posY - params->ray.Y) * params->ray.aView + params->player.posX;
			params->ray.offsetX = -params->map.prop;
			params->ray.offsetY = -params->ray.offsetX * params->ray.aView;
		}
		if (params->ray.angle < PI)
		{
			put_pixel(params, 1, 1, 0xFF6666);
			put_pixel(params, 1, 2, 0xFF6666);
			put_pixel(params, 2, 1, 0xFF6666);
			put_pixel(params, 2, 2, 0xFF6666);
			put_pixel(params, 2, 3, 0xFF6666);
			put_pixel(params, 3, 2, 0xFF6666);
			params->ray.X = ((params->player.posY / params->map.prop) * params->map.prop) + (params->map.height * params->map.width);
			params->ray.Y = (params->player.posX - params->ray.Y) * params->ray.aView + params->player.posY;
			params->ray.offsetX = params->map.prop;
			params->ray.offsetY = -params->ray.offsetX * params->ray.aView;
		}
		if (params->ray.angle == 0 || params->ray.angle == PI)
		{
			put_pixel(params, 1, 1, 0x4000FF);
			put_pixel(params, 1, 2, 0x4000FF);
			put_pixel(params, 2, 1, 0x4000FF);
			put_pixel(params, 2, 2, 0x4000FF);
			put_pixel(params, 2, 3, 0x4000FF);
			put_pixel(params, 3, 2, 0x4000FF);
			params->ray.X = params->player.posX;
			params->ray.Y = params->player.posY;
			maxView = 8;
		}

		while (maxView < 4)
		{
			mx = (int)params->ray.X / params->map.prop;
			my = (int)params->ray.Y / params->map.prop;
			printf("111rayitos: %f - %f\n\n", params->ray.X, params->ray.Y);
			mi = mx * params->map.width + my;
			mj = my * params->map.height + mx;

			printf("mi,mj: %d - %d\n\n", mx, my);

			if (mi < params->map.width * params->map.height && params->map.grid[mx][my] == 1) // hit wall
				maxView = 10;
			else
			{
				params->ray.X += params->ray.offsetX;
				params->ray.Y += params->ray.offsetY;
				maxView += 1;
			}
		}
		printf("jugador: %f - %f\n", params->player.posX, params->player.posY);
		printf("222rayitos: %f - %f\n\n", params->ray.X, params->ray.Y);
		// put_pixel(params, params->player.posX, params->ray.Y, 0x008F39);
		// put_pixel(params, params->player.posX, params->ray.Y+1, 0x008F39);
		// put_pixel(params, params->player.posX+1, params->ray.Y, 0x008F39);
		// put_pixel(params, params->player.posX+1, params->ray.Y+1, 0x008F39);
		join_pixels(params, params->player.posY, params->player.posX, params->ray.X, params->ray.Y);
		r++;
	}
}

void join_pixels(t_params *params, int x0, int y0, int x1, int y1)
{
	int dx, dy, p, x, y;

	dx = x1 - x0;
	dy = y1 - y0;
	x = x0;
	y = y0;

	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			put_pixel(params, x, y, 0x4000FF);
			y = y + 1;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			put_pixel(params, x, y, 0x4000FF);
			p = p + 2 * dy;
		}
		x = x + 1;
	}
}

// void	raycast_player(t_params *params)
// {
// 	int		rays;
// 	double	camera_angle;
// 	double	ray_dirX;
// 	double	ray_dirY;

// 	rays = 0;
// 	while (rays < WIDTH)
// 	{
// 		camera_angle = 2 * rays / WIDTH - 1;
// 		ray_dirX = params->player.dirX + params->player.planeX * camera_angle;
// 		ray_dirY = params->player.dirY + params->player.planeY * camera_angle;

// 		player_position(params->player, params->camera);

// 		rays++;
// 	}
// }

// void	player_position(t_player player, t_camera cam)
// {
// 	int		actual_posX;
// 	int		actual_posY;
// 	double	sideDistX;
// 	double	sideDistY;
// 	double	deltaDistX;
// 	double	deltaDistY;

// 	actual_posX = (int) player.posX;
// 	actual_posY = (int) player.posY;

// }
