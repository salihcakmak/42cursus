/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:03:21 by scakmak           #+#    #+#             */
/*   Updated: 2022/02/07 14:20:05 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	write_string(char *str)
{
	int	count;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}	
	count = 0;
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	write_0x(unsigned long number, int base, int hex_case)
{
	int	count;

	count = 0;
	count += write_string("0x");
	count += write_digitbase(number, base, hex_case);
	return (count);
}

int	write_digitbase(long double number, int base, int hex_case)
{
	int	count;
	int	neg;

	count = 1;
	neg = 0;
	if (number < 0)
	{
		number = -number;
		write (1, "-", 1);
		neg = 1;
	}
	if (number >= base)
		count += (write_digitbase(number / base, base, hex_case));
	if (hex_case)
		write(1, &UPPER_BASE_H[(unsigned long)number % base], 1);
	else
		write(1, &LOWER_BASE_H[(unsigned long)number % base], 1);
	return (count + neg);
}
