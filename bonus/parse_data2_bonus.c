/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:08:40 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 19:04:39 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D_bonus.h"

void	get_data2(t_params *params, char **colour)
{
	int	i;

	i = -1;
	while (++i < 3 && colour[i])
	{
		params->floor[i] = ft_atoi(colour[i]);
		if (ft_numlen(params->floor[i]) != (int)ft_strlen(colour[i])
			|| params->floor[i] > 255 || params->floor[i] < 0)
		{
			free(colour[i]);
			exit_error("Error en un numero del suelo");
		}
		free(colour[i]);
	}
	if (i < 3 || colour[i])
		exit_error("RGB distinto de 3 arguments");
	free(colour);
}

void	get_data3(t_params *params, char **colour)
{
	int	i;

	i = -1;
	while (++i < 3 && colour[i])
	{
		params->ceiling[i] = ft_atoi(colour[i]);
		if (ft_numlen(params->ceiling[i]) != (int)ft_strlen(colour[i])
			|| params->ceiling[i] > 255 || params->ceiling[i] < 0)
		{
			free(colour[i]);
			exit_error("Error en un numero del suelo");
		}
		free(colour[i]);
	}
	if (i < 3 || colour[i])
		exit_error("RGB distinto de 3 arguments");
	free(colour);
}
