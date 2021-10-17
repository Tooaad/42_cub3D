/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crueda-g <crueda-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:27:03 by crueda-g          #+#    #+#             */
/*   Updated: 2019/12/10 20:15:30 by crueda-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*list;

	list = lst;
	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
