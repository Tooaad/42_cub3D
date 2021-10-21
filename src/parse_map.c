/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:40:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/21 02:46:01 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	get_map_size(int fd, t_params *params)
{
	char	*c;
	int		width;

	c = "01 NSWE";
	while (params->line[0] != '\0')
	{
		width = 0;
		while (params->line[width] && params->line[0] != '\0')
		{
			if(ft_strchr(c, params->line[width]))
				width++;
			else
				exit_error("Character Invalid");
			if (width > params->map.width)
				params->map.width = width;
		}
		params->map.height++;
		free(params->line);
		get_next_line(fd, &params->line);
	}
	while (params->line[0] == '\0' && get_next_line(fd, &params->line) != 0)
	{
		if (params->line[0] != '\0')
			exit_error("Character Invalid");
		free(params->line);
	}
	free(params->line);
}

void	get_map_values(int skip_lines, int fd, t_params *params)
{
	int		i;

	i = 0;
	params->map.grid = (char **)ft_memalloc(sizeof(char *) * params->map.height + 1);
	if (!params->map.grid)
		exit_error("malloc error");
	while (i < params->map.height)
	{
		params->map.grid[i] = (char *)ft_memalloc(sizeof(char) * params->map.width + 1);
		if (!params->map.grid[i])
			exit_error("malloc error");
		get_row_values(i, skip_lines, fd, params);
		i++;
	}
	exit(1);
}

void	get_row_values(int i, int skip_lines, int fd, t_params *params)
{
	size_t		j;

	while (skip_lines-- > 0)
		get_next_line(fd, &params->line);
	while (get_next_line(fd, &params->line) != 0 || params->line[0] != '\0')
	{
		j = -1;	
		while (++j < ft_strlen(params->line))
		{
			if (params->line[j])
				params->map.grid[i][j] = params->line[j];
			free(params->line);		
		}
		printf("%zu\n", ft_strlen(params->map.grid[i]));
		free(params->line);
	}
}

void	check_map(t_params *params)
{
	// Recorrer todas las filas en busca de 0
	// Mirar que alrededor de los 0 solo haya 0s o 1s
}
