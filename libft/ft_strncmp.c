/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:39:43 by gpernas-          #+#    #+#             */
/*   Updated: 2019/12/01 20:26:06 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u1;
	unsigned char	*u2;
	unsigned int	i;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (u1[i] && u2[i] && u1[i] == u2[i] && i < n)
		i++;
	if (n == i)
		return (0);
	if (u1[i] != u2[i])
		return (u1[i] - u2[i]);
	else
		return (0);
}
