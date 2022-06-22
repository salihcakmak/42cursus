/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:48:47 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/08 14:25:33 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen(src);
	if (destsize)
	{
		if (srclen >= destsize)
			len = destsize - 1;
		else
			len = srclen;
		ft_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (srclen);
}
