# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 17:44:47 by kprigent          #+#    #+#              #
#    Updated: 2024/06/24 14:31:24 by ppitzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/src/main.c \
		srcs/src/input_verifs.c \
		srcs/src/files_verifs.c \
		srcs/libft/ft_strlen.c \
		srcs/libft/ft_split.c \
		srcs/src/map_read.c \
		srcs/src/utils.c \
		srcs/src/init_parsing.c \
		srcs/src/print.c \
		srcs/src/free.c \
		srcs/get_next_line/get_next_line.c \
		srcs/get_next_line/get_next_line_utils.c \
		srcs/src/map_data.c \
		srcs/src/texture_verifications.c \

OBJTS = $(SRCS:.c=.o)

HEADER = -I includes
CFLAGS = -Wall -Wextra -Werror -g

$(NAME): $(OBJTS)
	cc -o $(NAME) $(OBJTS)

RM	= rm -f

all:	${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} ${OBJTS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
