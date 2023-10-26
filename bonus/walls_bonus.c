/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 18:13:26 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	trace_walls(t_params *params, t_texture *texture, float rays, float r)
{
	t_ray	ray_t;
	float	ca;

	if (params->vertical)
		ray_t = params->player.vert;
	else
		ray_t = params->player.horiz;
	ca = params->player.angle - rays;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	texture->wall.lineH = (100 * HEIGHT) / (params->player.disT * cos(ca));
	calculate_walls(params, texture, ray_t, rays);
	draw_walls(params, texture, r);
}

void	calculate_walls(t_params *params, t_texture *texture, t_ray ray_t,
	float rays)
{
	float	ty_off;

	ty_off = 0;
	texture->wall.ty_step = texture->height / texture->wall.lineH;
	if (texture->wall.lineH > HEIGHT)
	{
		ty_off = (texture->wall.lineH - HEIGHT) / 2.0;
		texture->wall.lineH = HEIGHT;
	}
	texture->wall.lineO = HEIGHT / 2 - texture->wall.lineH / 2;
	texture->wall.ty = ty_off * texture->wall.ty_step;
	texture->wall.tx = (int)(ray_t.X) % texture->width;
	if (rays > PI)
		texture->wall.tx = texture->width - 1 - texture->wall.tx;
	if (params->vertical)
		texture->wall.tx = (int)ray_t.Y % texture->width;
	else
		texture->wall.tx = (int)ray_t.X % texture->width;
}

void	draw_walls(t_params *params, t_texture *texture, float r)
{
	int	j;
	int	c;

	j = -1;
	while (++j <= texture->wall.lineO)
		put_pixel(params, (RAYS - r - 1), j,
			RGBtoHEX(params->ceiling[0], params->ceiling[1],
				params->ceiling[2]));
	j--;
	while (++j < texture->wall.lineH + texture->wall.lineO)
	{
		c = get_tex_colour(texture, texture->wall.tx, texture->wall.ty);
		put_pixel(params, (RAYS - r - 1), j, RGBtoHEX(c >> 16, c >> 8, c));
		texture->wall.ty += texture->wall.ty_step;
	}
	j--;
	while (++j < texture->wall.lineH + texture->wall.lineO * 2)
		put_pixel(params, (RAYS - r - 1), j,
			RGBtoHEX(params->floor[0], params->floor[1], params->floor[2]));
}

// Esta funcion es de calculos de rayos pero no entra en create_rays
int	dist_limit(t_params *params, t_ray *ray, int dof, int direc)
{
	ray->mx = ray->X / params->map.prop;
	ray->my = ray->Y / params->map.prop;
	if (ray->mx < params->map.width && ray->my < params->map.height
		&& ray->mx >= 0 && ray->my >= 0
		&& params->map.grid[ray->my][ray->mx] == '1')
	{
		if (direc)
			return (params->map.width);
		else
			return (params->map.height);
	}
	else
	{
		ray->X += ray->offsetX;
		ray->Y += ray->offsetY;
		return (dof + 1);
	}
}
