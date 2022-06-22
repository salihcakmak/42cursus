/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:26:23 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/08 19:54:56 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (!destsize)
		return (slen);
	else if (destsize < dlen)
		return (slen + destsize);
	else
	{
		i = 0;
		while (src[i] != '\0' && (dlen + i) < destsize - 1)
		{
			dest[dlen + i] = src[i];
			i++;
		}
		dest[dlen + i] = '\0';
		return (dlen + slen);
	}
}
/*size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
}*/
