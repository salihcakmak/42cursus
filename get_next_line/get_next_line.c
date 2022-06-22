/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:44:25 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/21 12:33:05 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(char *buff, int fd, char **str)
{
	int		i;
	char	*temp;

	if (!*str || !ft_strchr(*str, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!*str)
				*str = ft_substr(buff, 0, i);
			else
			{
				temp = *str;
				*str = ft_strjoin(*str, buff);
				free(temp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

char	*ft_process(char **str)
{
	char	*line;
	char	*temp;

	if (!*str)
		return (NULL);
	if (!ft_strchr(*str, '\n'))
	{
		if (!ft_strlen(*str))
		{
			free(*str);
			*str = 0;
			return (NULL);
		}
		line = ft_substr(*str, 0, ft_strlen(*str));
		free(*str);
		*str = 0;
		return (line);
	}
	line = ft_substr(*str, 0, ft_strlen(*str) \
			- ft_strlen(ft_strchr(*str, '\n')) + 1);
	temp = *str;
	*str = ft_substr(ft_strchr(*str, '\n'), 1 \
			, ft_strlen(ft_strchr(*str, '\n')) - 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char static	*str;
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (NULL);
	}
	ft_read(buff, fd, &str);
	return (ft_process(&str));
}
/*
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd = open("nl", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	close(fd);
}*/
