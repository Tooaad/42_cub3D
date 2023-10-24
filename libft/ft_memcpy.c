/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:28:02 by gpernas-          #+#    #+#             */
/*   Updated: 2019/12/05 21:01:36 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	unsigned char		*csrc;
	// size_t				i;

	// i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (!n || dst == src)
		return (dst);
	while (n--)
		*cdst++ = *csrc++;
	return (dst);
}
