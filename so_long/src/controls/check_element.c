/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:23:42 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/06 20:47:38 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

int	check_element(t_element *element)
{
	if (element->p_count == 0)
		return (0);
	if (element->c_count == 0)
		return (0);
	if (element->e_count == 0)
		return (0);
	if (element->wall_count == 0)
		return (0);
	return (1);
}
