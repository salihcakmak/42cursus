/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:31:03 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/10 20:31:19 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int val, size_t n)
{
	unsigned char	*ptr;

	ptr = str;
	while (n--)
		*ptr++ = (unsigned char)val;
	return (str);
}
