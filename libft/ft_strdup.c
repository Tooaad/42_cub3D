/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:34:37 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 14:45:44 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int		i;
	char				*dup_ptr;

	dup_ptr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dup_ptr == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(src))
	{
		dup_ptr[i] = src[i];
		i++;
	}
	dup_ptr[i] = '\0';
	return (dup_ptr);
}
