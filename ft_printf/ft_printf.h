/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:24:26 by scakmak           #+#    #+#             */
/*   Updated: 2022/02/07 14:17:05 by scakmak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

# ifndef LOWER_BASE_H
#  define LOWER_BASE_H "0123456789abcdef"
# endif

# ifndef UPPER_BASE_H
#  define UPPER_BASE_H "0123456789ABCDEF"
# endif

int	write_char(int c);
int	write_string(char *str);
int	write_0x(unsigned long number, int base, int hex_case);
int	write_digitbase(long double number, int base, int hex_case);
int	ft_printf(const char *str, ...);

#endif