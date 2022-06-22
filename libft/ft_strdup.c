/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 03:59:10 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/09 10:23:45 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*newd;

	len = ft_strlen(s1) + 1;
	newd = malloc(len);
	if (!newd)
		return (NULL);
	ft_strlcpy(newd, s1, len);
	return (newd);
}
