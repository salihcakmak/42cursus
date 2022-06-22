/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:17:57 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 01:54:11 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	character_direction(t_solong *s, int curr_x, int curr_y)
{
	if (s->map[curr_x][curr_y] == 'E' && s->score == s->c_count)
	{
		print_message(INFO_MODE, "%s %s \nSkorunuz: %d\n", \
		SYS_TAG, GAME_OVER, s->score);
		finish_game(s, 0);
	}
	else if (s->map[curr_x][curr_y] != '1' && s->map[curr_x][curr_y] != 'E')
	{
		if (s->map[curr_x][curr_y] == 'C')
			s->score++;
		s->map[s->current_x][s->current_y] = '0';
		s->current_x = curr_x;
		s->current_y = curr_y;
		s->map[curr_x][curr_y] = 'P';
		mlx_clear_window(s->mlx, s->window);
		render_map(s);
	}
}

void	move_character_left(t_solong *solong)
{
	solong->curr_pos = 'L';
	character_direction(solong, solong->current_x, solong->current_y - 1);
}

void	move_character_right(t_solong *solong)
{
	solong->curr_pos = 'R';
	character_direction(solong, solong->current_x, solong->current_y + 1);
}

void	move_character_up(t_solong *solong)
{
	solong->curr_pos = 'U';
	character_direction(solong, solong->current_x - 1, solong->current_y);
}

void	move_character_down(t_solong *solong)
{
	solong->curr_pos = 'D';
	character_direction(solong, solong->current_x + 1, solong->current_y);
}
