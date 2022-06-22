/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:23:59 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:45:28 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	check_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

int	check_column(char *line)
{
	int	size;

	size = get_strlen(line);
	if (*line != '1' || line[size -1] != '1')
		return (0);
	return (1);
}

int	check_wall(char **map)
{
	int	i;
	int	size;

	i = 0;
	size = get_map_size(map);
	if (!check_line(map[i]) || !check_line(map[size - 1]))
		return (0);
	while (map[i])
	{
		if (!check_column(map[i]))
			return (0);
		i++;
	}
	return (1);
}
