/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:09:29 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/27 21:10:01 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	base(int b, unsigned long long int num)
{
	int							siz;
	unsigned long long int		base;

	siz = 1;
	base = b;
	while (base <= num)
	{
		base = base * b;
		siz++;
	}
	return (siz);
}
