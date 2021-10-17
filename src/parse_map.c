/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:56:00 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/17 13:10:23 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*get_data(char *line, int d)
{
	int	i;

	i = 0;
	if (d == 4)
	{	
		while (!ft_strchr(".", *line))
			line++;
		while (line[i] > 32 && line[i] < 127 )
			i++;
		return (ft_substr(line, 0, i));
	}
	else
	{
		while (!ft_isdigit(*line))
			line++;
		return ((ft_split(line, ','))[d]);
	}
}

int	parse_info(t_params *params, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) != 0 && i < 6)
	{
		j = 3;
		if (line[0] == 'N' && line[1] == 'O' && i++)
			params->n_path = get_data(line, 4);
		else if (line[0] == 'S' && line[1] == 'O' && i++)
			params->s_path = get_data(line, 4);
		else if (line[0] == 'W' && line[1] == 'E' && i++)
			params->w_path = get_data(line, 4);
		else if (line[0] == 'E' && line[1] == 'A' && i++)
			params->e_path = get_data(line, 4);
		else if (line[0] == 'F' && i++)
			while (j-- > 0)
				params->floor[j] = ft_atoi(get_data(line, j));
		else if (line[0] == 'C' && i++)
			while (j-- > 0)
				params->ceiling[j] = ft_atoi(get_data(line, j));
		free(line);
	}
	return (i);
}

// Si el programa finaliza con un '\0'en la ultima linea, esa linea no la lee
void	get_map_size(int fd, t_map *map)
{
	char	*line;
	char	*c;
	int		i;
	int		width;

	c = "10N ";
	while (get_next_line(fd, &line) != 0)
	{
		width = 0, i = 0;
		while (line[i] && line[0] != '\0')
		{
			printf("%i, %c\n", i, c[(unsigned char) line[i]]);
			// if (ft_isalnum(line[i++]) && (line[i] == ' ' || line[i] == '\0'))
			// 	width++;
			i++;
		}
		map->width = width;
		free(line);
	}
	free(line);
}

// t_point	*create_point(int z)
// {
// 	t_point		*point;

// 	point = (t_point *) malloc(sizeof(t_point));
// 	if (!point)
// 		exit_error("malloc error");
// 	point->z = z;
// 	return (point);
// }

// void	get_row_values(int i, int fd, t_map *map, t_params	*params)
// {
// 	char	*line;
// 	char	**row;
// 	int		j;
// 	int		z;

// 	if (get_next_line(fd, &line) != 0)
// 	{
// 		row = ft_split(line, ' ');
// 		j = -1;
// 		while (j++ < map->width)
// 		{
// 			if (row[j] && row[j][0] != '\n')
// 			{
// 				z = ft_atoi(row[j]);
// 				free(row[j]);
// 				map->grid[i][j] = create_point(z);
// 				if (z > params->max_deep)
// 					params->max_deep = z;
// 				if (z < params->min_deep)
// 					params->min_deep = z;
// 			}
// 		}
// 		free(row);
// 		free(line);
// 	}
// }

// void	get_map_values(int fd, t_map *map, t_params	*params)
// {
// 	int		i;

// 	i = 0;
// 	params->max_deep = 0;
// 	params->min_deep = 0;
// 	map->grid = (t_point ***)malloc(sizeof(t_point **) * map->height + 1);
// 	if (!map->grid)
// 		exit_error("malloc error");
// 	while (i < map->height)
// 	{
// 		map->grid[i] = (t_point **)malloc(sizeof(t_point *) * (map->width + 1));
// 		if (!map->grid[i])
// 			exit_error("malloc error");
// 		get_row_values(i, fd, map, params);
// 		i++;
// 	}
// }

void	parse_map(char *file, t_map *map, t_params *params)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("invalid map file");
	if (parse_info(params, fd) < 6)
		exit_error("texture or color argument missing");
	get_map_size(fd, map);
	close(fd);
	exit(1);
	
	fd = open(file, O_RDONLY);
	//get_map_values(fd, map, params);
	close(fd);
	params->map = map;
}
