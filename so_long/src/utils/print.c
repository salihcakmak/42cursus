/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:56:39 by scakmak           #+#    #+#             */
/*   Updated: 2022/03/03 09:17:06 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game/so_long.h"

static void	print_string(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

static void	print_number(int number)
{
	if (number > 9)
		print_number(number / 10);
	write(1, &"0123456789"[number % 10], 1);
}

static void	router(va_list arglist, char flag)
{
	if (flag == 's')
		print_string(va_arg(arglist, char *));
	else if (flag == 'd')
		print_number(va_arg(arglist, int));
}

void	print_message(int mode, char *message, ...)
{
	va_list	arglist;

	va_start(arglist, message);
	while (*message)
	{
		if (*message == '%')
		{	
			router(arglist, *(message + 1));
			message += 2;
		}
		else
			write(1, message++, 1);
	}
	if (mode == ERROR_MODE)
	{
		exit(1);
	}
}
