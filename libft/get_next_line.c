/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:17:15 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/20 21:00:20 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fill_line(char **str, char **line, int fd)
{
	char	*clean;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		clean = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = clean;
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_substr(str[fd], 0, len);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[4096];
	char		buf[32 + 1];
	char		*clean;
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_newstr(1);
	ret = read(fd, buf, 32);
	while (ret > 0)
	{
		buf[ret] = '\0';
		clean = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = clean;
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, buf, 32);
	}
	if (ret < 0)
		free(str[fd]);
	if (ret < 0)
		return (-1);
	return (fill_line(str, line, fd));
}
