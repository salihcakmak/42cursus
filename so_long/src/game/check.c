/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:47:47 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/06 17:49:44 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_control(t_control *control, char **map)
{
	if (control->check_wall == 0)
	{
		free_buff(map, get_map_size(map));
		print_message(ERROR_MODE, "%s %s", ERR_TAG, WALL_ERR);
	}
	else if (control->check_rectangle == 0)
	{
		free_buff(map, get_map_size(map));
		print_message(ERROR_MODE, "%s %s", ERR_TAG, RECTANGLE_ERR);
	}
	else if (control->check_element == 0)
	{
		free_buff(map, get_map_size(map));
		print_message(ERROR_MODE, "%s %s", ERR_TAG, ELEMENT_ERR);
	}
	else if (control->check_only_element == 0)
	{
		free_buff(map, get_map_size(map));
		print_message(ERROR_MODE, "%s %s", ERR_TAG, O_ELEMENT_ERR);
	}
	else if (control->check_dublicate_player == 0)
	{
		free_buff(map, get_map_size(map));
		print_message(ERROR_MODE, "%s %s", ERR_TAG, DUB_PLAYER_ERR);
	}
}
