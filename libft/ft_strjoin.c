/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 21:09:29 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/16 18:52:48 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_newstr(size);
	while (i < size && ptr)
	{
		if (i < (size - ft_strlen(s2)))
			ptr[i] = s1[i];
		else
		{
			ptr[i] = s2[j];
			j++;
		}
		i++;
	}
	return (ptr);
}
