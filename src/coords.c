/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:03:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/28 01:20:09 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_coord(t_map map, t_player player)
{
	// player.time = 0;
	// player.oldtime = 0;
	if (map.direction == 'S' || map.direction == 'N')
	{
		player.dirX = -1;
		player.dirY = 0;
		player.planeX = 0;
		player.planeY = 0.66;
		if (map.direction == 'S')
		{
			player.dirX = 1;
			player.planeY = -0.66;
		}
	}
	else
	{
		player.dirX = 0;
		player.dirY = -1;
		player.planeX = -0.66;
		player.planeY = 0;
		if (map.direction == 'E')
		{
			player.dirY = 1;
			player.planeX = 0.66;
		}
	}
}