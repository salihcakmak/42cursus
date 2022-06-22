/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 10:03:44 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 00:46:51 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_game_image(t_solong *solong)
{
	solong->wall = mlx_xpm_file_to_image(solong->mlx, \
	"textures/wall/stone_wall.xpm", &solong->widht, &solong->height);
	solong->player_l = mlx_xpm_file_to_image(solong->mlx, \
	"textures/characters/left.xpm", &solong->widht, &solong->height);
	solong->player_r = mlx_xpm_file_to_image(solong->mlx, \
	"textures/characters/right.xpm", &solong->widht, &solong->height);
	solong->player_u = mlx_xpm_file_to_image(solong->mlx, \
	"textures/characters/back.xpm", &solong->widht, &solong->height);
	solong->player_d = mlx_xpm_file_to_image(solong->mlx, \
	"textures/characters/front.xpm", &solong->widht, &solong->height);
	solong->collect = mlx_xpm_file_to_image(solong->mlx, \
	"textures/collectibles/collectible.xpm", &solong->widht, &solong->height);
	solong->exit = mlx_xpm_file_to_image(solong->mlx, \
	"textures/collectibles/bitcoin.xpm", &solong->widht, &solong->height);
}

void	data_fill_solong(t_solong *solong, t_element *element, char **map)
{
	init_solong(solong);
	solong->map = map;
	solong->line = get_map_size(solong->map);
	solong->column = get_strlen(solong->map[0]);
	solong->c_count = element->c_count;
	solong->mlx = mlx_init();
	solong->current_x = element->current_x;
	solong->current_y = element->current_y;
	fill_game_image(solong);
}
