/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:36:23 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 18:13:19 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

int	RGBtoHEX(int r, int g, int b)
{
	return (((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF));
}

int	get_tex_colour(t_texture *tex, int x, int y)
{	
	if (x >= 0 && x < tex->width && y >= 0 && y < tex->height)
		return (tex->img_adr[tex->height * y + x]);
	return (0xFFFFFF);
}
