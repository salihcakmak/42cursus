/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:49:04 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/08 20:33:11 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*newdest;
	unsigned char	*newsrc;

	if (!dest && !src)
		return (dest);
	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (src < dest)
	{
		while (n--)
			newdest[n] = newsrc[n];
	}
	else
	{
		while (n--)
			*newdest++ = *newsrc++;
	}
	return (dest);
}
