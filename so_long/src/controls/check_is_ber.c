/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_ber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:57:26 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/06 23:19:21 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

void	check_is_ber(char *path)
{
	int	i;
	int	pathlen;

	pathlen = 0;
	while (path[pathlen])
		pathlen++;
	if (pathlen < 5)
		print_message(ERROR_MODE, "%s %s", ERR_TAG, FNAME_ERROR);
	i = 0;
	path += pathlen - 4;
	while (*path)
	{
		if (*path != ".ber"[i])
			print_message(ERROR_MODE, "%s %s", ERR_TAG, BER_ERROR);
		i++;
		path++;
	}
}
