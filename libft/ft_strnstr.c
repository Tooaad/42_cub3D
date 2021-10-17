/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:39:57 by gpernas-          #+#    #+#             */
/*   Updated: 2019/12/06 20:58:57 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	s = (char *)hay;
	if (need[0] == '\0')
		return (s);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i + j] != '\0' && hay[i + j] == need[j] && (i + j) < len)
		{
			if (need[j + 1] == '\0')
				return (&s[i]);
			++j;
		}
		++i;
	}
	return (NULL);
}
