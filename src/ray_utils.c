/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:32:38 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/19 23:36:00 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int roundUp(int numToRound, int multiple)
{
	int remainder;

	remainder = numToRound % multiple;
	if (multiple == 0 || remainder == 0)
		return numToRound;
	return (numToRound + multiple - remainder);
}

int roundDown(int numToRound, int multiple)
{
	int remainder;

	remainder = numToRound % multiple;
	if (multiple == 0 || remainder == 0)
		return numToRound;
	return (numToRound - remainder);
}

float dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

// void join_pixels(t_params *params, int x0, int y0, int x1, int y1, int colour)
// {
//     int    dx;
//     int    dy;
//     int    err;
//     int    e2;
//     int    sx;
//     int    sy;
    
//     dx = abs(x1 - x0);
//     dy = abs(y1 - y0);
//     sx = -1;
//     if (x0 < x1)
//         sx = 1;
//     sy = -1;
//     if (y0 < y1)
//         sy = 1;
//     err = -dy / 2;
//     if (dx > dy)
//         err = dx / 2;
//     while (x0 != x1 || y0 != y1)
//     {
//         if (y0 < HEIGHT && x0 < WIDTH && y0 > 0 && x0 > 0)
//             put_pixel(params, x0, y0, colour);
//         e2 = err;
//         if (e2 > -dx)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dy)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }
