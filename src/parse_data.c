/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:56:00 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/21 12:51:40 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// El free esta por tema de lineas en get_map_size
void	parse_data(char *file, t_params *params)
{
	int		fd;
	int		skip_lines;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error("invalid map file");
	skip_lines = parse_info(params, fd, 0);
	if (skip_lines == 0)
		exit_error("color, map or texture missing");
	get_map_size(params, "01 NSWE", fd);
	free(params->line);
	close(fd);
	fd = open(file, O_RDONLY);
	get_map_values(skip_lines, fd, params);
	close(fd);
	if (params->map.height > params->map.width)
		params->map.prop = HEIGHT / params->map.height;
	else
		params->map.prop = HEIGHT / params->map.width;
	params->map.prop = 64;
	check_map(params->map);
}

// i es skiplines
int	parse_info(t_params *params, int fd, int i)
{
	while (get_next_line(fd, &params->line) != 0)
	{
		if (ft_strncmp(params->line, "NO", 2) && params->n_path == NULL)
			params->n_path = get_data(params, params->line, 4);
		else if (ft_strncmp(params->line, "SO", 2) && params->s_path == NULL)
			params->s_path = get_data(params, params->line, 4);
		else if (ft_strncmp(params->line, "WE", 2) && params->w_path == NULL)
			params->w_path = get_data(params, params->line, 4);
		else if (ft_strncmp(params->line, "EA", 2) && params->e_path == NULL)
			params->e_path = get_data(params, params->line, 4);
		else if (params->line[0] == 'F' && params->floor[2] == -1)
			get_data(params, params->line, 0);
		else if (params->line[0] == 'C' && params->ceiling[2] == -1)
			get_data(params, params->line, 1);
		else if (params->line[0] == '\0' && ++i)
			i--;
		else
			break ;
		i++;
		free(params->line);
	}
	return (parse_info_errors(params, i));
}

char	*get_data(t_params *params, char *line, int d)
{
	int		i;
	char	**colour;

	if (d == 4)
	{
		i = 0;
		while (!ft_strchr(".", *line))
			line++;
		while (line[i] > 32 && line[i] < 127)
			i++;
		return (ft_substr(line, 0, i));
	}	
	while (!ft_isdigit(*line))
		line++;
	colour = ft_split(line, ',');
	get_data2(params, colour, d, -1);
	return (NULL);
}

int	parse_info_errors(t_params *params, int skip_lines)
{
	int	fd;

	if (params->n_path == NULL || params->w_path == NULL
		|| params->s_path == NULL || params->e_path == NULL
		|| params->floor[0] == -1 || params->ceiling[0] == -1)
		return (0);
	fd = open(params->n_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(params->w_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(params->s_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(params->e_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (skip_lines);
}

void	get_map_size(t_params *params, char *c, int fd)
{
	int		width;

	while (params->line[0] != '\0')
	{
		width = 0;
		while (params->line[width] && params->line[0] != '\0')
		{
			if (ft_strchr(c, params->line[width]))
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
	free(params->line);
	while (params->line[0] == '\0' && get_next_line(fd, &params->line) != 0)
	{
		if (params->line[0] != '\0')
			exit_error("Character Invalid");
		free(params->line);
	}
}
