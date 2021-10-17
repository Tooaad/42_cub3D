/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crueda-g <crueda-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 21:22:52 by crueda-g          #+#    #+#             */
/*   Updated: 2019/12/10 20:06:41 by crueda-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*prev;

	list = *lst;
	while (list)
	{
		prev = list;
		list = list->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}
