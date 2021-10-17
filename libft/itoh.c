/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:11:37 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 14:42:19 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoh(unsigned long long int num, int aux, int caps)
{
	unsigned long long int	n;

	aux = 1;
	n = num;
	if (n >= 16)
		aux += itoh(n / 16, aux, caps);
	n = n % 16;
	if (n >= 10)
		n = n + 87;
	else
		n = n + '0';
	if (caps == 1)
		ft_putchar_fd(ft_toupper(n), 1);
	else
		ft_putchar_fd(n, 1);
	return (aux);
}
