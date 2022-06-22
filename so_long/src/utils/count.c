/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:45:38 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 00:34:03 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	get_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int	get_map_size(char **map)
{
	int	count;

	count = 0;
	while (*map)
	{
		count++;
		map++;
	}
	return (count);
}

void	count_elements_line(t_element *element, char *mapline, int i)
{
	int	j;

	j = 0;
	while (mapline[j])
	{
		if (mapline[j] == 'P')
		{
			element->current_x = i;
			element->current_y = j;
			element->p_count++;
		}
		else if (mapline[j] == 'E')
			element->e_count++;
		else if (mapline[j] == 'C')
			element->c_count++;
		else if (mapline[j] == '0')
			element->space_count++;
		else if (mapline[j] == '1')
			element->wall_count++;
		else
			element->other_count++;
		j++;
	}
}

void	count_elements(t_element *element, char **map)
{
	int	i;

	init_element(element);
	i = 0;
	while (map[i])
	{
		count_elements_line(element, map[i], i);
		i++;
	}
}
