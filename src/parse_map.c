/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 02:40:56 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/01 16:42:29 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
		ft_memset(params->map.grid[i], ' ', params->map.width);
		get_row_values(i, skip_lines, fd, params);
		i++;
	}
}

void	get_row_values(int i, int skip_lines, int fd, t_params *params)
{
	int			j;

	while (i == 0 && skip_lines-- > 0 && get_next_line(fd, &params->line))
		free(params->line);
	if (get_next_line(fd, &params->line) != 0 || params->line[0] != '\0')
	{
		j = -1;
		while (++j < (int)ft_strlen(params->line))
		{
			params->map.grid[i][j] = params->line[j];
		    if (ft_strchr("NSEW", params->line[j]))
			{
				if (params->map.direction != '\0')
					exit_error("Invalid map, multiple initial positions detected");
				params->player.posX = j;
				params->player.posY = i;
				params->map.direction = params->line[j];
			}
		}
		free(params->line);
	}
}

void	check_map(t_map map)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while (!ft_strchr("NSEW", map.grid[i][j]))
		if (++j >= (int)ft_strlen(map.grid[i]) && ++i)
			j = 0;
	if (i == 0 || i == map.height - 1 || j == (int)ft_strlen(map.grid[i]) - 1)
		exit_error("Como se te ocurra probar otro mapa invalido... n\n");
	surrounded("01", i - 1, j, map);
	check_zeros(map);
}

// printf("%d  --  %d,   %c\n", i ,j, map.grid[i][j]);
void	check_zeros(t_map map)
{
	int	i;
	int	j;
	
	j = 0;
	i = 0;
	while (i < map.height - 1)
	{
		while (!ft_strchr("0", map.grid[i][j]))
		{
			if (i == map.height - 1 && j == (int)ft_strlen(map.grid[i]) - 1)
				return ;
			if (++j >= (int)ft_strlen(map.grid[i]) && ++i)
				j = 0;
		}
		if (i == 0 || i == map.height - 1)
			exit_error("Como se te ocurra probar otro mapa invalido... 0\n");

		if(map.grid[i][j] == '0')
			surrounded("01NSEW", i - 1, j, map);
		j++;
	}
}

void	surrounded(char *c, int i, int j, t_map map)
{
	size_t	movs;

	movs = 3;
	while (movs-- > 0)
	{
		if (ft_strchr(c, map.grid[i][j - 1])
			&& ft_strchr(c, map.grid[i][j + 1]))
		{
			if((movs == 1 && ft_strchr("01NSEW", map.grid[i][j]))
				|| ft_strchr(c, map.grid[i][j])){
				i++;
			}
			else
				exit_error("Te la estas buscando...\n");
		}
		else
			exit_error("Como se te ocurra probar otro mapa invalido...\n");
	}
}
