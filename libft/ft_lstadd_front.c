/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:57:50 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/12 15:40:04 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int main()
{
	t_list **test;
	t_list *a,*b,*c;
	a->next = b;
	b->content = "salih";

	*test = a;
	ft_lstadd_front(test, c);

	printf("%s",c->next->next->content);
}*/
