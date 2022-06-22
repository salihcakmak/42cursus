/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:24:10 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/11 15:30:59 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*nstring;
	size_t	nstringlen;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nstringlen = ft_strlen(s);
	nstring = malloc(sizeof(char) * (nstringlen + 1));
	if (!nstring)
		return (NULL);
	while (*s)
	{
		nstring[i] = f(i, (char)*s);
		s++;
		i++;
	}
	nstring[i] = '\0';
	return (nstring);
}
