# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scakmak <scakmak@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 13:59:43 by scakmak           #+#    #+#              #
#    Updated: 2022/03/06 21:31:55 by scakmak          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
SRCS	=	./src/controls/check_dublicate_player.c ./src/controls/check_element.c ./src/controls/check_is_ber.c \
			./src/controls/check_only_element.c ./src/controls/check_rectangle.c ./src/controls/check_wall.c \
			./src/game/check.c ./src/game/event.c ./src/game/game.c ./src/game/fill.c \
			./src/game/init.c ./src/game/move.c ./src/game/so_long.c ./src/utils/count.c ./src/utils/file.c \
			./src/utils/line.c ./src/utils/print.c ./src/utils/split.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		make -C ./mlx
		$(CC) $(CFLAGS) $(SRCS) ./mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	@echo "Dosyalar Siliniyor"
	@make -C ./mlx clean
	@rm -rf $(OBJS)
	@echo Silindi $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
