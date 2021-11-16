/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:15:25 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/16 18:59:53 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_hook(int keycode, t_params *params)
{
	key_hook1(keycode, params);
	key_hook2(keycode, params);
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
	if (keycode == DEL)
		init_player(params);
	
	if (keycode == LEFT)
	{
		params->player.angle += 0.1;
		if (params->player.angle > 2 * PI)
			params->player.angle -= 2 * PI;
		params->player.dposX = cos(params->player.angle) * 5;
		params->player.dposY = sin(params->player.angle) * 5;
	}
	if (keycode == RIGHT)
	{
		params->player.angle -= 0.1;
		if (params->player.angle < 0)
			params->player.angle += 2 * PI;
		params->player.dposX = cos(params->player.angle) * 5;
		params->player.dposY = sin(params->player.angle) * 5;
	}
}

void	key_hook2(int keycode, t_params *params)
{
	if (keycode == W)
	{
		params->player.posY -= params->player.dposY;
		params->player.posX += params->player.dposX;
	}
	if (keycode == S)
	{
		params->player.posY += params->player.dposY;
		params->player.posX -= params->player.dposX;
	}
	if (keycode == A)
	{
		params->player.posY -= params->player.dposX;
		params->player.posX -= params->player.dposY;
	}
	if (keycode == D)
	{
		params->player.posY += params->player.dposX;
		params->player.posX += params->player.dposY;
	}
}

// void	key_hook3(int keycode, t_params *params)
// {
// 	if (keycode == RED)
// 	{
// 		r += 10;
// 		if (r > 255)
// 			r = 255;
// 	}
// }

// void	key_hook4(int keycode, t_params *params)
// {
// 	if (keycode == DEL)
// 		params_reset(params);
// }
