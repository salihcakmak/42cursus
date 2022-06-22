/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:28:57 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/06 18:51:07 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_character(t_solong *s)
{
	s->char_move++;
	if (s->curr_pos == 'R')
		mlx_put_image_to_window(s->mlx, s->window, s->player_r, s->x, s->y);
	else if (s->curr_pos == 'L')
		mlx_put_image_to_window(s->mlx, s->window, s->player_l, s->x, s->y);
	else if (s->curr_pos == 'U')
		mlx_put_image_to_window(s->mlx, s->window, s->player_u, s->x, s->y);
	else if (s->curr_pos == 'D')
		mlx_put_image_to_window(s->mlx, s->window, s->player_d, s->x, s->y);
}

void	put_image(t_solong *s, int i, int j)
{
	if (s->map[i][j] == '1')
		mlx_put_image_to_window(s->mlx, s->window, s->wall, s->x, s->y);
	else if (s->map[i][j] == 'P')
		render_character(s);
	else if (s->map[i][j] == 'C')
		mlx_put_image_to_window(s->mlx, s->window, s->collect, s->x, s->y);
	else if (s->map[i][j] == 'E')
		mlx_put_image_to_window(s->mlx, s->window, s->exit, s->x, s->y);
}

void	render_map(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	solong->x = 0;
	solong->y = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			put_image(solong, i, j);
			solong->x += 64;
			j++;
		}
		if (solong->map[i][j] == 0)
			solong->x = 0;
		solong->y += 64;
		i++;
	}
	print_message(INFO_MODE, "%s MOVE: %d\n", SYS_TAG, solong->char_move);
}
