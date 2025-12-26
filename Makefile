# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luozguo <luozguo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/26 15:01:05 by luozguo           #+#    #+#              #
#    Updated: 2025/12/26 15:01:06 by luozguo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      parse.c \
      stack.c \
      dispatch.c \
      ops_push_to_another.c \
      ops_rotate_top_to_bottom.c \
      ops_rrotate_bottom_to_top.c \
      ops_swap_upper.c \
      normalization.c \
      sort_big_radix.c \
      ft_bzero.c \
      ft_calloc.c \
      ft_split.c \
      ft_strdup.c \
      ft_substr.c \
      ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
