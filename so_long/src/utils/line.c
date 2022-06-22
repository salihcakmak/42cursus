/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 00:31:06 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:44:18 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	get_line_len(char *content)
{
	int		i;

	if (*content == '\n')
		return (1);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	return (i);
}

int	get_line_count(char *content)
{
	int	count;

	count = 0;
	while (*content)
	{
		count++;
		while (*content && *content != '\n')
			content++;
		if (*content == '\n')
			content++;
	}
	return (count);
}

char	*get_next_line(char *content)
{
	int		i;
	char	*line;

	line = malloc(sizeof(char) * get_line_len(content) + 1);
	if (!line)
		return (0);
	i = 0;
	while (content[i] && content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
