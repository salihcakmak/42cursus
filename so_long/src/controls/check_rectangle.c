/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 23:06:54 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:45:34 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	check_rectangle(char **map)
{
	int	len;
	int	blen;

	blen = get_strlen(*map);
	while (*map)
	{
		len = get_strlen(*map);
		if (blen != len)
			return (0);
		map++;
	}
	return (1);
}
