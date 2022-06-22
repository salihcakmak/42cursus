/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:10:57 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:44:10 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_message(ERROR_MODE, "%s %s", ERR_TAG, FOPN_ERROR);
	return (fd);
}

void	close_file(int fd)
{
	if (close(fd) < 0)
		print_message(ERROR_MODE, "%s %s", ERR_TAG, FCLS_ERROR);
}

int	get_file_length(char *path)
{
	int		fd;
	int		count;
	char	buff;

	fd = open_file(path);
	count = 0;
	while (read(fd, &buff, 1))
		count++;
	close_file(fd);
	return (count);
}

char	*get_file_content(char *path)
{
	int		fd;
	char	*buff;
	int		size;
	int		i;

	size = get_file_length(path);
	if (!size)
		print_message(ERROR_MODE, "%s %s", ERR_TAG, EMPTY_FILE);
	fd = open_file(path);
	buff = malloc(sizeof(char) * (size + 1));
	if (!buff)
		print_message(ERROR_MODE, "%s %s", ERR_TAG, NOT_ALLOCATED);
	i = read(fd, buff, size);
	if (i <= 0)
	{
		free(buff);
		print_message(ERROR_MODE, "%s %s", ERR_TAG, EMPTY_FILE);
	}
	buff[i] = '\0';
	close_file(fd);
	return (buff);
}
