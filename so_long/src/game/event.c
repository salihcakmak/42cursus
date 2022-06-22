/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:28:44 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 01:44:09 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int key, t_solong *solong)
{
	if (key == ESC_KEY)
	{
		print_message(INFO_MODE, "%s %s", SYS_TAG, ESC_EXIT);
		finish_game(solong, 0);
	}
	else if (key == W_KEY)
		move_character_up(solong);
	else if (key == A_KEY)
		move_character_left(solong);
	else if (key == S_KEY)
		move_character_down(solong);
	else if (key == D_KEY)
		move_character_right(solong);
	return (0);
}
