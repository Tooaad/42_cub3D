/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/16 20:22:33 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	persp(t_params *params, double rays, double r, double disT, t_texture *texture, t_ray ray_t)
{
	int		j;
	double	ca;
	double	lineH;
	double	lineO;

	ca = params->player.angle - rays;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	lineH = (45 * HEIGHT) / (disT * cos(ca));

	lineO = HEIGHT / 2 - lineH / 2;
	int prop_rays = WIDTH / RAYS;

	float ty_step = texture->height / (float) lineH;
	float ty_off = 0;

	if (lineH > HEIGHT)
		ty_off = (lineH - HEIGHT) / 2.0;
		// lineH = HEIGHT;
	float ty = ty_off * ty_step;
	float tx = (int) (ray_t.X) % texture->width;
	if (rays > PI)
		tx = texture->width - 1 - tx;

	j = -1;
	while (++j <= lineO)
		join_pixels(params, (RAYS - r - 1) * prop_rays, j, (RAYS - r - 1)
			* prop_rays + prop_rays, j, RGBtoHEX(params->ceiling));
	j--;
	while (j++ < lineH + lineO)
	{
		join_pixels(params, (RAYS - r - 1) * prop_rays, j,
			(RAYS - r - 1) * prop_rays + prop_rays, j, get_tex_colour(texture, tx, ty)); 
		ty += ty_step;
	}
	j--;
	while (j++ < lineH + lineO * 2)
		join_pixels(params, (RAYS - r - 1) * prop_rays, j, (RAYS - r - 1)
			* prop_rays + prop_rays, j, RGBtoHEX(params->floor));
}

int	RGBtoHEX(int *RGB)
{
	return ((RGB[0] & 0xFF) << 16) + ((RGB[1] & 0xFF) << 16)
		+ ((RGB[2] & 0xFF) << 16);
}

int		get_tex_colour(t_texture *tex, int x, int y)
{	
	if (x >= 0 && x < tex->width
		&& y >= 0 && y < tex->height)
	{
		return (*(char*)(tex->img_adr
			+ (4 * tex->width * y)
			+ (4 * x)));
	}
	return (0xFFFFFF);
}
