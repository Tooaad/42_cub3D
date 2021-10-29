/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:15:25 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/29 16:41:16 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_hook(int keycode, t_params *params)
{
	key_hook1(keycode, params);
	// key_hook2(keycode, params);
	// key_hook3(keycode, params);
	// key_hook4(keycode, params);
	refresh_image(params);
	return (0);
}

void	key_hook1(int keycode, t_params *params)
{
	if (keycode == ESC)
	{
		// anti_leaks(params);
		exit(1);
	}
	if (keycode == RIGHT)
	{
		// params->camera.c_angle += 0.1;
		// if (params->camera.c_angle > 2 * PI)
		// 	params->camera.c_angle -= 2 * PI;
		// params->camera.dX = cos(params->camera.c_angle) * 5;
		// params->camera.dY = sin(params->camera.c_angle) * 5;
	}
	if (keycode == LEFT)
	{
		// params->camera.c_angle -= 0.1;
		// if (params->camera.c_angle < 0)
		// 	params->camera.c_angle += 2 * PI;
		// params->camera.dX = cos(params->camera.c_angle) * 5;
		// params->camera.dY = sin(params->camera.c_angle) * 5;
	}

	if (keycode == W)
	{
		if (params->player.posY - 10 > 0)
			params->player.posY -= 10;
		// params->player.posX += params->camera.dX;
		// params->player.posY -= params->camera.dY;
	}
	if (keycode == A)
	{
		if (params->player.posX - 10 > 0)
			params->player.posX -= 10;
	}

	if (keycode == S)
	{
		if (params->player.posY + 10 < HEIGHT)
			params->player.posY += 10;
		// params->player.posX += params->camera.dX;
		// params->player.posY -= params->camera.dY;	
	}
	if (keycode == D)
	{
		if (params->player.posX + 10 < HEIGHT)
			params->player.posX += 10;
	}
}

// void	key_hook2(int keycode, t_params *params)
// {
// 	if (keycode == RED_)
// 	{
// 		params->r -= 10;
// 		if (params->r < 0)
// 			params->r = 0;
// 	}
// }

// void	key_hook3(int keycode, t_params *params)
// {
// 	if (keycode == RED)
// 	{
// 		params->r += 10;
// 		if (params->r > 255)
// 			params->r = 255;
// 	}
// }

// void	key_hook4(int keycode, t_params *params)
// {
// 	if (keycode == DEL)
// 		params_reset(params);
// }
