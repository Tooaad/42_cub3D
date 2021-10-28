/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:35:06 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/28 11:35:36 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycast_player(t_params *params)
{
	int		rays;
	double	camera_angle;
	double	ray_dirX;
	double	ray_dirY;

	rays = 0;	
	while (rays < WIDTH)
	{
		camera_angle = 2 * rays / WIDTH - 1;
		// ray_dirX = params->player.dirX + params->player.planeX * camera_angle;
		// ray_dirY = params->player.dirY + params->player.planeY * camera_angle;
		ray_dirX = params->camera.c_angle - params->player


		player_position(ray_dirX, ray_dirY, params->player, params->camera);

		rays++;
	}
}

void	player_position(double ray_dirX, double ray_dirY, t_player player, t_camera cam)
{
	double	viewX;
	double	viewY;
	double	distance_wall;
	int		hitwall;



	viewX = sin(ray_dirX);
	viewy = sin(ray_dirY);
	hitwall = 0;
	distance_wall = 0;
	while (hitwall > 0)
	{

	}
}
