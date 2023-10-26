/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:15:25 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 18:13:01 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	init_controls(t_params *params)
{
	params->player.controls.right = 0;
	params->player.controls.left = 0;
	params->player.controls.w = 0;
	params->player.controls.s = 0;
	params->player.controls.a = 0;
	params->player.controls.d = 0;
}

int	key_press(int keycode, t_params *params)
{
	if (keycode == ESC)
	{
		anti_leaks(params);
		exit(1);
	}
	if (keycode == DEL)
		init_player(params);
	if (keycode == RIGHT)
		params->player.controls.right = 1;
	if (keycode == LEFT)
		params->player.controls.left = 1;
	if (keycode == W)
		params->player.controls.w = 1;
	if (keycode == S)
		params->player.controls.s = 1;
	if (keycode == A)
		params->player.controls.a = 1;
	if (keycode == D)
		params->player.controls.d = 1;
	return (0);
}

int	key_release(int keycode, t_params *params)
{
	if (keycode == RIGHT)
		params->player.controls.right = 0;
	if (keycode == LEFT)
		params->player.controls.left = 0;
	if (keycode == W)
		params->player.controls.w = 0;
	if (keycode == S)
		params->player.controls.s = 0;
	if (keycode == A)
		params->player.controls.a = 0;
	if (keycode == D)
		params->player.controls.d = 0;
	return (0);
}

void	controls_move(t_params *params)
{
	if (params->player.controls.w)
	{
		params->player.posY -= params->player.dposY * 3;
		params->player.posX += params->player.dposX * 3;
	}
	if (params->player.controls.s)
	{
		params->player.posY += params->player.dposY * 2;
		params->player.posX -= params->player.dposX * 2;
	}
	if (params->player.controls.a)
	{
		params->player.posY -= params->player.dposX * 3;
		params->player.posX -= params->player.dposY * 3;
	}
	if (params->player.controls.d)
	{
		params->player.posY += params->player.dposX * 2;
		params->player.posX += params->player.dposY * 2;
	}
}

void	controls_rotate(t_params *params)
{
	if (params->player.controls.left == 1)
	{
		params->player.angle += 0.1;
		if (params->player.angle > 2 * PI)
			params->player.angle -= 2 * PI;
		params->player.dposX = cos(params->player.angle) * 2;
		params->player.dposY = sin(params->player.angle) * 2;
	}
	if (params->player.controls.right == 1)
	{
		params->player.angle -= 0.1;
		if (params->player.angle < 0)
			params->player.angle += 2 * PI;
		params->player.dposX = cos(params->player.angle) * 3;
		params->player.dposY = sin(params->player.angle) * 3;
	}
}
