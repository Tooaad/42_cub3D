/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:16:39 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 17:34:58 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = -1;
	p = (char *)malloc(count * size);
	if (p == NULL)
		return (NULL);
	while (++i < count * size)
	{
		p[i] = '\0';
	}
	return (p);
}
