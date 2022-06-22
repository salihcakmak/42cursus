/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 02:51:46 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/09 03:33:10 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	ndlen;

	ndlen = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n-- >= ndlen)
	{
		if (*haystack == *needle && !ft_memcmp(haystack, needle, ndlen))
			return ((char *)haystack);
		++haystack;
	}
	return (NULL);
}
