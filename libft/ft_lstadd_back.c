/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Toad <Toad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:35:31 by gpernas-          #+#    #+#             */
/*   Updated: 2021/03/28 17:36:16 by Toad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lista;

	lista = *alst;
	if (!lista)
		*alst = new;
	else
	{
		while (lista->next != NULL)
			lista = lista->next;
		lista->next = new;
	}
}
