/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:40:31 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/12 16:05:01 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
#include <stdio.h>
int main()
{
    t_list **test = malloc(sizeof(t_list *));;
    t_list *a = malloc(sizeof(t_list));
    t_list *b= malloc(sizeof(t_list));
    t_list *c= malloc(sizeof(t_list));
    a->next = b;
    b->content = "salih";
	b->next = c;

    *test = a;
	ft_lstsize(*test);
	printf("%d",ft_lstsize(*test));

}*/
