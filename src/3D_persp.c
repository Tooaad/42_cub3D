/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/20 14:58:59 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	persp(t_params *params,  t_texture *texture, float rays, float r)
{
	t_ray	ray_t;
	float	ca;
	float	lineH;
	float	lineO;
	int		j;

	if (vertical == 1)

	ca = params->player.angle - rays;
	if (ca < 0)
		ca += 2 * PI;
	if (ca > 2 * PI)
		ca -= 2 * PI;
	lineH = (100 * HEIGHT) / (params->disT * cos(ca));

	float ty_step = texture->height / (float) lineH;
	float ty_off = 0;

	if (lineH > HEIGHT)
	{
		ty_off = (lineH - HEIGHT) / 2.0;
		lineH = HEIGHT;
	}
	lineO = HEIGHT / 2 - lineH / 2;
	float ty = ty_off * ty_step;
	float tx = (int) (ray_t.X) % texture->width;
	if (rays > PI)
		tx = texture->width - 1 - tx;
		
	if (params->vertical)
		tx = (int)ray_t.Y % texture->width;
	else
		tx = (int)ray_t.X % texture->width;
	j = -1;
	while (++j <= lineO)
		put_pixel(params, (RAYS - r - 1), j,
			RGBtoHEX(params->ceiling[0], params->ceiling[1], params->ceiling[2]));
	j--;
	while (++j < lineH + lineO)
	{
		int c = get_tex_colour(texture, tx, ty);

		put_pixel(params, (RAYS - r - 1), j, RGBtoHEX(c >> 16, c >> 8, c));
		ty += ty_step;
	}
	j--;
	while (++j < lineH + lineO * 2)
		put_pixel(params, (RAYS - r - 1), j,
			RGBtoHEX(params->floor[0], params->floor[1], params->floor[2]));
}
