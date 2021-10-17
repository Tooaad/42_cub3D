/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crueda-g <crueda-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 11:53:22 by crueda-g          #+#    #+#             */
/*   Updated: 2019/12/10 19:43:45 by crueda-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_list;

	s_list = (t_list *)malloc(sizeof(t_list));
	if (!s_list)
		return (NULL);
	s_list->content = (void *)content;
	s_list->next = NULL;
	return (s_list);
}
