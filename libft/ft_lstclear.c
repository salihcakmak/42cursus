/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:50:37 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/12 18:09:13 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pos;

	if (!del)
		return ;
	while (*lst)
	{
		pos = *lst;
		*lst = pos->next;
		ft_lstdelone(pos, del);
	}
}
