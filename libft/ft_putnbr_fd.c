/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:32:02 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 17:31:49 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	number;

	number = nb;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		number = nb * -1;
	}
	else
	{
		number = nb;
	}
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	ft_putchar_fd(number % 10 + 48, fd);
}
