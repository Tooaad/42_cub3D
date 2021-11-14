/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:06 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/14 20:15:59 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_ray_horizontal(t_params *params, t_ray *ray, double rays)
{
	int		dof;
	double	aTan;

	dof = 0;
	aTan = 1 / tan(rays);
	
	// ------------------------------
	// --- Check Horizontal Lines ---
	// ------------------------------
	
	if (rays > PI) // looking down OK
	{
		ray->Y = roundUp(params->player.posY, params->map.prop);
		ray->X = (params->player.posY - ray->Y) * aTan + params->player.posX;
		ray->offsetY = params->map.prop;
		ray->offsetX = -ray->offsetY * aTan;
	}
	if (rays < PI) // looking up OK
	{
		ray->Y = roundDown(params->player.posY, params->map.prop) - 0.0001;
		ray->X = (params->player.posY - ray->Y) * aTan + params->player.posX;
		ray->offsetY = -params->map.prop;
		ray->offsetX = -ray->offsetY * aTan;
	}
	
	if (rays == 0 || rays == PI)
	{
		ray->X = params->player.posX;
		ray->Y = params->player.posY;
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

void	calculate_ray_vertical(t_params *params, t_ray *ray, double rays)
{
	int		dof;
	double	nTan;

	dof = 0;
	nTan = tan(rays);
	
	// ------------------------------
	// --- Check Vertical Lines -----
	// ------------------------------
	
	if (rays > PI / 2 && rays < 3 * PI / 2)
	{
		ray->X = roundDown(params->player.posX, params->map.prop) - 0.0001;
		ray->Y = (params->player.posX - ray->X) * nTan + params->player.posY;
		ray->offsetX = -params->map.prop;
		ray->offsetY = -ray->offsetX * nTan;
	}
	if (rays < PI / 2 || rays > 3 * PI / 2)
	{
		ray->X = roundUp(params->player.posX, params->map.prop);
		ray->Y = (params->player.posX - ray->X) * nTan + params->player.posY;
		ray->offsetX = params->map.prop;
		ray->offsetY = -ray->offsetX * nTan;
	}
	
	if (rays == PI / 2 || rays == 3 * PI / 2)
	{
		ray->X = params->player.posX;
		ray->Y = params->player.posY;
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
	int		r;
	double	disT;
	double	rays;
	t_ray	ray_h, ray_v, ray_t;

	rays = params->player.angle - RD * 30;
	if (rays < 0)
		rays += 2 * PI;
	if (rays > 2 * PI)
		rays -= 2 * PI;
	
	r = -1;
	while (++r < 60)
	{
		calculate_ray_horizontal(params, &ray_h, rays);
		calculate_ray_vertical(params, &ray_v, rays);
		
		double	disH = 10000000;
		disH = dist(params->player.posX, params->player.posY, ray_h.X, ray_h.Y);

		double	disV = 10000000;
		disV = dist(params->player.posX, params->player.posY, ray_v.X, ray_v.Y);


		// t_texture texture;
		if (disV < disH)
		{
			ray_t = ray_v;
			disT = disV;
			if (rays > PI / 2 && rays < 3 * PI / 2)
				persp(params, rays, r, disT, params->map.texture_ea);
				// texture = params->map.texture_ea;
			else
				persp(params, rays, r, disT, params->map.texture_we);
				// texture = params->map.texture_we;
		}
		else if (disH < disV)
		{
			ray_t = ray_h;
			disT = disH;
			if (rays > PI)
				persp(params, rays, r, disT, params->map.texture_so);
				// texture = params->map.texture_so;
			else
				persp(params, rays, r, disT, params->map.texture_no);
				// texture = params->map.texture_no;
		}
		// join_pixels(params, params->player.posX, params->player.posY, ray_t.X, ray_t.Y, 0x4000FF); // rayos
		// persp(params, rays, r, disT, &texture);






		rays += RD;
		if (rays < 0)
			rays += 2 * PI;
		if (rays > 2 * PI)
			rays -= 2 * PI;
	
		
	}
}

void join_pixels(t_params *params, int x0, int y0, int x1, int y1, int colour)
{
    int    dx;
    int    dy;
    int    err;
    int    e2;
    int    sx;
    int    sy;
    
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = -1;
    if (x0 < x1)
        sx = 1;
    sy = -1;
    if (y0 < y1)
        sy = 1;
    err = -dy / 2;
    if (dx > dy)
        err = dx / 2;
    while (x0 != x1 || y0 != y1)
    {
        if (y0 < HEIGHT && x0 < WIDTH && y0 > 0 && x0 > 0)
            put_pixel(params, x0, y0, colour);
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void join_pixels_texture(t_params *params, int x0, int y0, int x1, int y1, t_texture *texture)
{
    int    dx;
    int    dy;
    int    err;
    int    e2;
    int    sx;
    int    sy;
    
    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    sx = -1;
    if (x0 < x1)
        sx = 1;
    sy = -1;
    if (y0 < y1)
        sy = 1;
    err = -dy / 2;
    if (dx > dy)
        err = dx / 2;
    while (x0 != x1 || y0 != y1)
    {
        if (y0 < HEIGHT && x0 < WIDTH && y0 > 0 && x0 > 0)
            put_pixel(params, x0, y0, get_tex_colour(texture, x1, y1));
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
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

float dist(double ax, double ay, double bx, double by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}