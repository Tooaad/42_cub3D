/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crueda-g <crueda-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:55:08 by crueda-g          #+#    #+#             */
/*   Updated: 2019/12/15 12:27:29 by crueda-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*list;
	t_list			*lstfinal;
	t_list			*aux;

	list = lst;
	lstfinal = NULL;
	while (list)
	{
		aux = ft_lstnew(f(list->content));
		if (!aux)
		{
			ft_lstclear(&lstfinal, del);
			return (NULL);
		}
		ft_lstadd_back(&lstfinal, aux);
		list = list->next;
	}
	return (lstfinal);
}
