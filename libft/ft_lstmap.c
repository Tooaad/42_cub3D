/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpernas- <gpernas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:19:17 by gpernas-          #+#    #+#             */
/*   Updated: 2021/11/20 20:59:01 by gpernas-         ###   ########.fr       */
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
