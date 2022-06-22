/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:17:26 by scakmak           #+#    #+#             */
/*   Updated: 2022/02/07 14:16:12 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_router(char type, va_list arg_list)
{
	if (type == 'c')
		return (write_char(va_arg(arg_list, int)));
	else if (type == 's')
		return (write_string(va_arg(arg_list, char *)));
	else if (type == 'p')
		return (write_0x(va_arg(arg_list, unsigned long), 16, 0));
	else if (type == 'd' || type == 'i')
		return (write_digitbase(va_arg(arg_list, int), 10, 0));
	else if (type == 'u')
		return (write_digitbase(va_arg(arg_list, unsigned int), 10, 0));
	else if (type == 'x')
		return (write_digitbase(va_arg(arg_list, unsigned int), 16, 0));
	else if (type == 'X')
		return (write_digitbase(va_arg(arg_list, unsigned int), 16, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		total;

	total = 0;
	va_start(arg_list, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '%')
		{
			total += write_char('%');
			str += 2;
		}
		else if (*str == '%')
		{
			total += ft_router(*(str + 1), arg_list);
			str += 2;
		}
		else
		{
			total += write_char(*str);
			str++;
		}
	}
	va_end(arg_list);
	return (total);
}

/* int main()
{
	ft_printf("Yazılan Değer : %p",LONG_MIN);
} */
/* int main()
{
	int orjinal;
	int my;
	char str[] = "Merhaba";
	  my = ft_printf("%%String : %s\nKarakter : %c\nİnteger : 
	  %i\nDecimal : %d\nx : %x\nX : %X\nPointer : %p\n\n", str,
	   'c', 10, 20, 4375, 3284, LONG_MAX);
	orjinal = printf("%%String : %s\nKarakter : %c\nİnteger : 
	%i\nDecimal : %d\nx : %x\nX : %X\nPointer : %p\n\n", str, 
	'c', 10, 20, 4375, 3284, LONG_MAX);

	printf("%d ---------- %d",orjinal, my);
} */