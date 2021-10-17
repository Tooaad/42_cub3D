/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:42:03 by gpernas-          #+#    #+#             */
/*   Updated: 2021/10/16 18:51:42 by gpernas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		str = ft_newstr(len);
		if (!str)
			return (NULL);
		if (start < ft_strlen(s))
		{
			while (i < len)
			{
				str[i] = s[i + start];
				i++;
			}
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
