/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:29:20 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 17:31:20 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	i = 0;
	if (!cdst && !csrc)
		return (NULL);
	if (csrc < cdst)
		while (++i <= len)
			cdst[len - i] = csrc[len - i];
	else
		while (len-- > i)
			*(cdst++) = *(csrc++);
	return (dst);
}
