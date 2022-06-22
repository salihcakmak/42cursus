/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:47:39 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/07 01:57:46 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_MODE 0
# define INFO_MODE	1

# include "../../mlx/mlx.h"
# include "info.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

enum {
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC_KEY = 53
};

typedef struct s_element
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	wall_count;
	int	space_count;
	int	other_count;
	int	current_x;
	int	current_y;

}	t_element;

typedef struct s_control
{
	int	check_wall;
	int	check_rectangle;
	int	check_element;
	int	check_only_element;
	int	check_dublicate_player;

}	t_control;

typedef struct s_solong
{
	void	*mlx;
	char	**map;
	void	*window;
	void	*wall;
	void	*player_l;
	void	*player_r;
	void	*player_u;
	void	*player_d;
	void	*collect;
	void	*exit;
	int		widht;
	int		height;
	int		line;
	int		column;
	int		current_x;
	int		current_y;
	int		x;
	int		y;
	int		score;
	int		char_move;
	int		c_count;
	char	curr_pos;

}	t_solong;

void	print_message(int mode, char *message, ...);

char	*get_file_content(char *path);
char	**get_split_content(char *content);
int		get_strlen(char *str);
int		get_map_size(char **map);
int		get_line_len(char *content);
int		get_line_count(char *content);
char	*get_next_line(char *content);

void	free_buff(char **buffer, int i);
void	count_elements(t_element *element, char **map);

void	check_is_ber(char *path);
int		check_wall(char **map);
int		check_rectangle(char **map);
int		check_only_element(t_element *element);
int		check_element(t_element *element);
int		check_dublicate_player(t_element *element);

void	init_solong(t_solong *init);
void	init_element(t_element *init);
void	init_control(t_control *control, t_element *element, char **map);
void	do_control(t_control *control, char **map);

void	character_direction(t_solong *s, int curr_x, int curr_y);
void	move_character_left(t_solong *solong);
void	move_character_right(t_solong *solong);
void	move_character_up(t_solong *solong);
void	move_character_down(t_solong *solong);
int		finish_game(t_solong *solong, int exit_mode);
void	fill_game_image(t_solong *solong);
void	data_fill_solong(t_solong *solong, t_element *element, char **map);
void	render_map(t_solong *solong);
int		key_event(int key, t_solong *solong);
void	create_window(t_solong *solong);

#endif