/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:35:10 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 17:36:22 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lista;

	if (!del)
		return ;
	else
	{
		while (*lst)
		{
			del((*lst)->content);
			lista = *lst;
			*lst = lista->next;
			free(lista);
		}
	}
	lst = NULL;
}
