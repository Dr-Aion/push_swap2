# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 13:27:58 by aiganymmold       #+#    #+#              #
#    Updated: 2025/07/16 18:24:31 by aiganymmold      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = error_handling.c ft_atol.c ft_split.c \
	   greedy_chunked_push_utils.c greedy_chunked_push.c \
	   greedy_max_pull.c index_mapping.c \
	   main.c push_command.c quicksort.c \
	   reverse_rotate_command.c rotate_command.c \
	   small_stack_algorithm.c stack.c stack_utils.c swap_command.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
