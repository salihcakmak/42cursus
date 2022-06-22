/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dublicate_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:24:43 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 02:45:57 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	check_dublicate_player(t_element *element)
{
	if (element->p_count > 1)
		return (0);
	return (1);
}
