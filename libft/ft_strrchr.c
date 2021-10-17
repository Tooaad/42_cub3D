/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:40:40 by gpernas-          #+#    #+#             */
/*   Updated: 2019/12/05 18:47:54 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (ft_strchr(s, c) == 0)
		return (NULL);
	while (*s)
		s++;
	while (*s != c)
		s--;
	return ((char *)s);
}
