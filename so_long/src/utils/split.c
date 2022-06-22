/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:20:22 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:44:47 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	free_buff(char **buffer, int i)
{
	while (--i >= 0 && buffer[i])
	{
		free(buffer[i]);
		buffer[i] = 0;
	}
	free(buffer);
	buffer = 0;
}

void	fill_buff(char **buffer, char *content)
{
	int		i;
	int		size;
	char	*tmpcontent;

	i = 0;
	tmpcontent = content;
	size = get_line_count(content);
	while (i < size)
	{
		buffer[i] = get_next_line(content);
		if (buffer[i] == 0)
		{
			free(tmpcontent);
			free_buff(buffer, i);
			print_message(ERROR_MODE, "%s %s", ERR_TAG, NOT_ALLOCATED);
		}
		while (*content && *content != '\n')
			content++;
		if (*content == '\n')
			content++;
		i++;
	}
	buffer[i] = 0;
}

char	**get_split_content(char *content)
{
	char	**buffer;

	buffer = malloc(sizeof(char *) * (get_line_count(content) + 1));
	if (!buffer)
	{
		free(content);
		print_message(ERROR_MODE, "%s %s", ERR_TAG, NOT_ALLOCATED);
	}
	fill_buff(buffer, content);
	free(content);
	return (buffer);
}
