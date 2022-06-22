/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 02:00:44 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 01:40:52 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_solong *solong, t_element *element, char **map)
{
	data_fill_solong(solong, element, map);
	solong->window = mlx_new_window(solong->mlx, solong->column * 64, \
	solong->line * 64, "so_long");
	render_map(solong);
	mlx_hook(solong->window, 2, 1L << 0, key_event, solong);
	mlx_hook(solong->window, 17, 1L << 17, finish_game, solong);
	mlx_loop(solong->mlx);
}

int	finish_game(t_solong *solong, int exit_mode)
{
	if (solong->wall)
		mlx_destroy_image(solong->mlx, solong->wall);
	if (solong->collect)
		mlx_destroy_image(solong->mlx, solong->collect);
	if (solong->exit)
		mlx_destroy_image(solong->mlx, solong->exit);
	if (solong->player_d)
		mlx_destroy_image(solong->mlx, solong->player_d);
	if (solong->player_l)
		mlx_destroy_image(solong->mlx, solong->player_l);
	if (solong->player_r)
		mlx_destroy_image(solong->mlx, solong->player_r);
	if (solong->player_u)
		mlx_destroy_image(solong->mlx, solong->player_u);
	if (solong->map)
		free_buff(solong->map, get_map_size(solong->map));
	if (exit_mode)
		exit(1);
	exit(0);
}

int	main(int ac, char **av)
{
	t_solong	solong;
	t_element	element;
	t_control	control;
	char		**map;

	if (ac == 2)
	{
		check_is_ber(av[1]);
		map = get_split_content(get_file_content(av[1]));
		count_elements(&element, map);
		init_control(&control, &element, map);
		do_control(&control, map);
		start_game(&solong, &element, map);
	}
	else
		print_message(ERROR_MODE, "%s %s", ERR_TAG, ARG_ERROR);
	return (0);
}
