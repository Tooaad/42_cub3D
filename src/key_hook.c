/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:15:25 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/23 19:05:07 by gpernas-         ###   ########.fr       */
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
		params->camera.cam += 30;
	if (keycode == LEFT)
		params->camera.cam -= 30;
	// if (keycode == W)

	// if (keycode == A)
	
	// if (keycode == S)
	
	// if (keycode == D)
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
