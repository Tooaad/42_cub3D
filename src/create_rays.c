/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:06 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/19 23:29:12 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_ray_horizontal(t_params *params, t_ray *ray, float rays)
{
	int		dof;
	double	aTan;

	dof = 0;
	aTan = 1 / tan(rays);
	if (rays > PI)
	{
		ray->Y = roundUp(params->player.posY, params->map.prop);
		ray->X = (params->player.posY - ray->Y) * aTan + params->player.posX;
		ray->offsetY = params->map.prop;
		ray->offsetX = -ray->offsetY * aTan;
	}
	else if (rays < PI)
	{
		ray->Y = roundDown(params->player.posY, params->map.prop) - 0.0001;
		ray->X = (params->player.posY - ray->Y) * aTan + params->player.posX;
		ray->offsetY = -params->map.prop;
		ray->offsetX = -ray->offsetY * aTan;
	}
	while (dof < params->map.height)
	{
		ray->mx = ray->X / params->map.prop;
		ray->my = ray->Y / params->map.prop;

		if (ray->mx < params->map.width && ray->my < params->map.height && ray->mx >= 0 && ray->my >= 0 && params->map.grid[ray->my][ray->mx] == '1')
			dof = params->map.height;
		else
		{
			ray->X += ray->offsetX;
			ray->Y += ray->offsetY;
			dof += 1;
		}
	}
}

void	calculate_ray_vertical(t_params *params, t_ray *ray, float rays)
{
	int		dof;
	double	nTan;

	dof = 0;
	nTan = tan(rays);
	if (rays > PI / 2 && rays < 3 * PI / 2)
	{
		ray->X = roundDown(params->player.posX, params->map.prop) - 0.0001;
		ray->Y = (params->player.posX - ray->X) * nTan + params->player.posY;
		ray->offsetX = -params->map.prop;
		ray->offsetY = -ray->offsetX * nTan;
	}
	else if (rays < PI / 2 || rays > 3 * PI / 2)
	{
		ray->X = roundUp(params->player.posX, params->map.prop);
		ray->Y = (params->player.posX - ray->X) * nTan + params->player.posY;
		ray->offsetX = params->map.prop;
		ray->offsetY = -ray->offsetX * nTan;
	}
	while (dof < params->map.width)
	{
		ray->mx = ray->X / params->map.prop;
		ray->my = ray->Y / params->map.prop;
		
		if (ray->mx < params->map.width && ray->my < params->map.height && ray->mx >= 0 && ray->my >= 0 && params->map.grid[ray->my][ray->mx] == '1')
			dof = params->map.width;
		else
		{
			ray->X += ray->offsetX;
			ray->Y += ray->offsetY;
			dof += 1;
		}
	}
}

void	trace_ray(t_params *params)
{
	t_ray	ray_v;
	t_ray	ray_h;
	double	r;
	double	disT;
	float	rays;

	rays = params->player.angle - (RD * 60 / WIDTH) * (WIDTH / 2);
	if (rays < 0)
		rays += 2 * PI;
	if (rays > 2 * PI)
		rays -= 2 * PI;
	
	r = -1;
	while (++r < RAYS)
	{
		calculate_ray_horizontal(params, &ray_h, rays);
		calculate_ray_vertical(params, &ray_v, rays);
		double	disH = 10000000;
		double	disV = 10000000;
		
		disV = dist(params->player.posX, params->player.posY, ray_v.X, ray_v.Y);
		disH = dist(params->player.posX, params->player.posY, ray_h.X, ray_h.Y);
	
		if (ray_v.Y > params->player.posY && (rays > PI / 2  - 0.1 && rays < PI / 2 + 0.1))
			disV = 10000000;
		if (ray_v.Y < params->player.posY && (rays > (3 * PI / 2) - 0.1 && rays < (3 * PI / 2) + 0.1))
			disV = 10000000;
		if (ray_h.X > params->player.posX && (rays > PI - 0.1 && rays < PI + 0.1))
			disH = 10000000;
		if (ray_h.X < params->player.posX && (rays > 2 * PI - 0.1 || rays < 0 + 0.1))
			disH = 10000000;
		
		if (disV <= disH)
		{
			params->vertical = 1;
			disT = disV;
			if (rays > PI / 2 && rays < 3 * PI / 2)
				persp(params, rays, r, disT, params->map.texture_ea, ray_v);
			else
				persp(params, rays, r, disT, params->map.texture_we, ray_v);
		}
		else if (disH < disV)
		{
			disT = disH;
			params->vertical = 0;
			if (rays > PI)
				persp(params, rays, r, disT, params->map.texture_so, ray_h);
			else
				persp(params, rays, r, disT, params->map.texture_no, ray_h);
		}
		rays += (RD * 60 / WIDTH);
		if (rays < 0)
			rays += 2 * PI;
		if (rays > 2 * PI)
			rays -= 2 * PI;	
	}
}

int roundUp(int numToRound, int multiple)
{
	if (multiple == 0)
		return numToRound;

	int remainder = numToRound % multiple;
	if (remainder == 0)
		return numToRound;

	return numToRound + multiple - remainder;
}

int roundDown(int numToRound, int multiple)
{
	if (multiple == 0)
		return numToRound;

	int remainder = numToRound % multiple;
	if (remainder == 0)
		return numToRound;

	return numToRound - remainder;
}

double dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

// void join_pixels(t_params *params, int x0, int y0, int x1, int y1, int colour)
// {
//     int    dx;
//     int    dy;
//     int    err;
//     int    e2;
//     int    sx;
//     int    sy;
    
//     dx = abs(x1 - x0);
//     dy = abs(y1 - y0);
//     sx = -1;
//     if (x0 < x1)
//         sx = 1;
//     sy = -1;
//     if (y0 < y1)
//         sy = 1;
//     err = -dy / 2;
//     if (dx > dy)
//         err = dx / 2;
//     while (x0 != x1 || y0 != y1)
//     {
//         if (y0 < HEIGHT && x0 < WIDTH && y0 > 0 && x0 > 0)
//             put_pixel(params, x0, y0, colour);
//         e2 = err;
//         if (e2 > -dx)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dy)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }
