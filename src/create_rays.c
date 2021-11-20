/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:06 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/20 14:16:25 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_ray_horizontal(t_params *params, t_ray *ray, float rays)
{
	int		dof;
	float	aTan;

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
	float	nTan;

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
		
		if (ray->mx < params->map.width && ray->my < params->map.height
			&& ray->mx >= 0 && ray->my >= 0 && params->map.grid[ray->my][ray->mx] == '1')
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
	float	rays;
	float	r;

	rays = params->player.angle - (RD * 60 / WIDTH) * (WIDTH / 2);
	if (rays < 0)
		rays += 2 * PI;
	if (rays > 2 * PI)
		rays -= 2 * PI;	
	r = -1;
	while (++r < RAYS)
	{
		calculate_ray_horizontal(params, &params->player.horiz, rays);
		calculate_ray_vertical(params, &params->player.vert, rays);
		calculate_distance(params, rays, r);
		rays += (RD * 60 / WIDTH);
		if (rays < 0)
			rays += 2 * PI;
		if (rays > 2 * PI)
			rays -= 2 * PI;	
	}
}


// disV se puede pasar por estructura en 3D_persp
// if vertical == 1 usaremos player.vert, si no horiz
void	calculate_distance(t_params *params, float rays, float r)
{
	params->ray.disH = 10000000;
	params->ray.disV = 10000000;
	params->ray.disV = dist(params->player.posX, params->player.posY,
		params->player.vert.X, params->player.vert.Y);
	params->ray.disH = dist(params->player.posX, params->player.posY,
		params->player.horiz.X, params->player.horiz.Y);
	fix_rays(params->player, params->ray, rays);
	if (params->ray.disV <= params->ray.disH)
	{
		params->vertical = 1;
		params->player.disT = params->ray.disV;
		if (rays > PI / 2 && rays < 3 * PI / 2)
			persp(params, params->map.texture_ea, rays, r);
		else
			persp(params, params->map.texture_we, rays, r);
	}
	else
	{
		params->vertical = 0;
		params->player.disT = params->ray.disH;
		if (rays > PI)
			persp(params, params->map.texture_so, rays, r);
		else
			persp(params, params->map.texture_no, rays, r);
	}
}

void	fix_rays(t_player player, t_ray ray, float ra)
{
	if (player.vert.Y > player.posY && (ra > PI / 2  - 0.1 && ra < PI / 2 + 0.1))
		ray.disV = 10000000;
	else if (player.vert.Y < player.posY
			&& (ra > (3 * PI / 2) - 0.1 && ra < (3 * PI / 2) + 0.1))
		ray.disV = 10000000;
	else if (player.horiz.X > player.posX && (ra > PI - 0.1 && ra < PI + 0.1))
		ray.disH = 10000000;
	else if (player.horiz.X < player.posX && (ra > 2 * PI - 0.1 || ra < 0 + 0.1))
		ray.disH = 10000000;
}