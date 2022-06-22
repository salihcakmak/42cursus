# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/06 18:04:22 by scakmak           #+#    #+#              #
#    Updated: 2022/02/07 14:21:57 by scakmak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_utils.c ft_printf.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I./

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
			$(CC) -c $(CFLAGS) $(SRCS) -I./
			ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean : 
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re 