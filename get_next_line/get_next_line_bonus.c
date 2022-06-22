/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:21:57 by scakmak           #+#    #+#             */
/*   Updated: 2022/01/21 12:33:21 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(char *buff, int fd, char **str)
{
	int		i;
	char	*temp;

	if (!str[fd] || !ft_strchr(str[fd], '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		while (i > 0)
		{
			buff[i] = 0;
			if (!str[fd])
				str[fd] = ft_substr(buff, 0, i);
			else
			{
				temp = str[fd];
				str[fd] = ft_strjoin(str[fd], buff);
				free(temp);
			}
			if (ft_strchr(buff, '\n'))
				break ;
			i = read(fd, buff, BUFFER_SIZE);
		}
	}
	free(buff);
}

char	*ft_process(char **str, int fd)
{
	char	*line;
	char	*temp;

	if (!str[fd])
		return (NULL);
	if (!ft_strchr(str[fd], '\n'))
	{
		if (!ft_strlen(str[fd]))
		{
			free(str[fd]);
			str[fd] = 0;
			return (NULL);
		}
		line = ft_substr(str[fd], 0, ft_strlen(str[fd]));
		free(str[fd]);
		str[fd] = 0;
		return (line);
	}
	line = ft_substr(str[fd], 0, ft_strlen(str[fd]) - \
			ft_strlen(ft_strchr(str[fd], '\n')) + 1);
	temp = str[fd];
	str[fd] = ft_substr(ft_strchr(str[fd], '\n'), 1, \
			ft_strlen(ft_strchr(str[fd], '\n')) - 1);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char static	*str[OPEN_MAX];
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, buff, 0) == -1)
	{
		free(buff);
		return (NULL);
	}
	ft_read(buff, fd, str);
	return (ft_process(str, fd));
}

/*
#include <stdio.h>
#include <fcntl.h>
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
