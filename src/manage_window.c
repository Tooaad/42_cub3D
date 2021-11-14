/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:12:58 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/13 12:26:50 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void    draw_texture(t_params *params)
{
    int x;
    int y;
    char *colour;

    t_texture    *tex = params->map.texture_no;

    y = -1;
	// tex->height = 64;
	// tex->width = 64;
    while (++y < tex->height)
    {
        x = -1;
        while (++x < tex->width)
        {
            colour = tex->img_adr + (y * tex->width * 4 + x * 4);

            int x1, y1;
            
            y1 = y * 4 - 1;
            while (++y1 < y * 4 + 4)
            {
                x1 = x * 4 - 1;
                while (++x1 < x * 4 + 4)
                    put_pixel(params, x1, y1, *colour);
            }
        }
    }
}

int close_win(t_params *params)
{

	mlx_destroy_window(params->mlx, params->win);
	exit(0);
}

int	refresh_image(t_params *params)
{
	draw_map(params);
	draw_texture(params);
	mlx_put_image_to_window(params->mlx, params->win, params->img, 0, 0);
	mlx_destroy_image(params->mlx, params->img);
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
		&(params->size_line), &(params->endian));
	return (0);
}

void    init_player(t_params *params)
{
    if (params->map.direction == 'N')
        params->player.angle = PI / 2;
    else if (params->map.direction == 'S')
        params->player.angle = 3 * PI / 2;
    else if (params->map.direction == 'W')
        params->player.angle = PI;
    else if (params->map.direction == 'E')
        params->player.angle = 0;
        
    params->player.dposX = cos(params->player.angle) * 5;
    params->player.dposY = sin(params->player.angle) * 5;

    params->player.posX = params->player.posX * params->map.prop + params->map.prop / 2;
    params->player.posY = params->player.posY * params->map.prop + params->map.prop / 2;
}

int	build_mlx(t_params *params)
{
    init_player(params);
	params->mlx = mlx_init();
	textures_load(params);
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "cub3D");
	params->img = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->img_adr = mlx_get_data_addr(params->img, &(params->bits_per_pixel),
			&(params->size_line), &(params->endian));
	refresh_image(params);
	mlx_hook(params->win, 2, 2, key_hook, params);
	mlx_hook(params->win, 17, 1L<<17, close_win, &params);
	mlx_loop(params->mlx);
	return (0);
}