/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 01:26:26 by scakmak           #+#    #+#             */
/*   Updated: 2022/02/15 09:43:30 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* param c value is 1 (one) or 0 (zero) */
void	convert_binary_to_char(int c)
{
	static int	i = 7;
	static int	character = 0;

	character += c << i;
	if (i == 0)
	{
		i = 7;
		write(1, &character, 1);
		character = 0;
	}
	else
		i--;
}

/* router func */
void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		convert_binary_to_char(1);
	else if (sig == SIGUSR2)
		convert_binary_to_char(0);
}

/* signal values -> SIGUSR1 = 1 | SIGUSR2 = 0 */
int	main(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	write(1, "Server Pid : ", 13);
	ft_itoa(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
