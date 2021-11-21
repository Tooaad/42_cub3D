/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:08:40 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 02:43:36 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_data2(t_params *params, char **colour, int d, int i)
{
	if (d == 0)
	{
		while (++i < 3 && colour[i])
		{
			params->floor[i] = ft_atoi(colour[i]);
			free(colour[i]);
			if (ft_numlen(params->floor[i]) != (int)ft_strlen(colour[i])
				|| params->floor[i] > 255 || params->floor[i] < 0)
				exit_error("Error en un numero del suelo");
		}
	}
	else
	{
		while (++i < 3 && colour[i])
		{
			params->ceiling[i] = ft_atoi(colour[i]);
			free(colour[i]);
			if (ft_numlen(params->ceiling[i]) != (int)ft_strlen(colour[i])
				|| params->ceiling[i] > 255 || params->ceiling[i] < 0)
				exit_error("Error en un numero del cielo");
		}
	}
	if (i < 3 || colour[i])
		exit_error("RGB distinto de 3 arguments");
	free(colour);
}
