/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/18 11:52:58 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	persp(t_params *params, float rays, double r, double disT, t_texture *texture, t_ray ray_t)
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

	double ty_step = texture->height / (double) lineH;
	double ty_off = 0;

	if (lineH > HEIGHT)
		ty_off = (lineH - HEIGHT) / 2.0;
		// lineH = HEIGHT;
	double ty = ty_off * ty_step;
	double tx = (int) (ray_t.X) % texture->width;
	if (rays > PI)
		tx = texture->width - 1 - tx;

	if (params->vertical)
	{
		tx = (int)ray_t.Y % texture->width;
		// if (rays > PI / 2 && rays < 3 * PI / 2)
		// 	tx = texture->width - 1 - tx;
	}
	else
	{
		tx = (int)ray_t.X % texture->width;
		// if (rays > PI)
		// 	tx = texture->width - 1 - tx;
	}


	j = -1;
	while (++j <= lineO)
		join_pixels(params, (RAYS - r - 1), j, (RAYS - r), j, RGBtoHEX(params->ceiling[0], params->ceiling[1], params->ceiling[2]));
	j--;
	while (++j < lineH + lineO)
	{
		int c = get_tex_colour(texture, tx, ty);

		join_pixels(params, (RAYS - r - 1), j,
			(RAYS - r), j, RGBtoHEX(c >> 16, c >> 8, c));
		ty += ty_step;
		//  RGBtoHEX((int)c >> 16, (int)c >> 8, (int)c)
	}
	j--;
	while (++j < lineH + lineO * 2)
		join_pixels(params, (RAYS - r - 1), j, (RAYS - r), j, RGBtoHEX(params->floor[0], params->floor[1], params->floor[2]));
}

int	RGBtoHEX(int r, int g, int b)
{
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8)
		+ ((b & 0xFF));
}

int		get_tex_colour(t_texture *tex, int x, int y)
{	
	if (x >= 0 && x < tex->width
		&& y >= 0 && y < tex->height)
	{
		return (tex->img_adr[tex->height * y + x]);

	}
	return (0xFFFFFF);
}
