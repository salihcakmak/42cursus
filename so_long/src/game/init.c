/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:18:07 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/06 16:09:08 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_solong(t_solong *init)
{
	init->line = 0;
	init->column = 0;
	init->widht = 0;
	init->height = 0;
	init->current_x = 0;
	init->current_y = 0;
	init->x = 0;
	init->y = 0;
	init->char_move = -1;
	init->score = 0;
	init->curr_pos = 'R';
	init->c_count = 0;
	init->mlx = NULL;
	init->map = NULL;
	init->window = NULL;
	init->wall = NULL;
	init->player_l = NULL;
	init->player_r = NULL;
	init->player_u = NULL;
	init->player_d = NULL;
	init->collect = NULL;
	init->exit = NULL;
}

void	init_element(t_element *init)
{
	init->p_count = 0;
	init->e_count = 0;
	init->c_count = 0;
	init->wall_count = 0;
	init->space_count = 0;
	init->other_count = 0;
	init->current_x = 0;
	init->current_y = 0;
}

void	init_control(t_control *control, t_element *element, char **map)
{
	control->check_wall = check_wall(map);
	control->check_rectangle = check_rectangle(map);
	control->check_element = check_element(element);
	control->check_only_element = check_only_element(element);
	control->check_dublicate_player = check_dublicate_player(element);
}
