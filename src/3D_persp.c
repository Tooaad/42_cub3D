/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_persp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:46:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/14 20:16:16 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	persp(t_params *params, double rays, double r, double disT, t_texture *texture)
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
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	lineO = HEIGHT / 2 - lineH / 2;
	int prop_rays = WIDTH / RAYS;
	j = -1;
	while (++j <= lineO)
		join_pixels(params, (RAYS - r - 1) * prop_rays, j, (RAYS - r - 1)
			* prop_rays + prop_rays, j, RGBtoHEX(params->ceiling));
	j--;
	while (j++ < lineH + lineO)
		join_pixels_texture(params, (RAYS - r - 1) * prop_rays, j,
			(RAYS - r - 1) * prop_rays + prop_rays, j, texture);
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
		return (*(int*)(tex->img_adr
			+ (4 * tex->width * y)
			+ (4 * x)));
	}
	return (0x0);
}


// ------ Textures

// void xpm_to_image(t_params *params, t_texture tex)
// {
// 	tex->img_ptr = mlx_xpm_file_to_image(params->mlx, )
// }