/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:36:24 by gpernas-          #+#    #+#             */
/*   Updated: 2019/12/05 18:45:02 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = (ft_strlen(dest));
	res = 0;
	while (src[res])
		res++;
	if (size <= i)
		res = res + size;
	else
		res = res + i;
	j = 0;
	while (i + 1 < size && src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (size > i)
		dest[i] = '\0';
	return (res);
}
