# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youchen <youchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 12:19:42 by youchen           #+#    #+#              #
#    Updated: 2024/01/29 17:21:33 by youchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

SRC = push_swap_util.c utilitis.c push_swap.c instructions.c pars.c
BONUS_SRC_DIR = bonus
BONUS_SRC = $(BONUS_SRC_DIR)/checker_util_bonus.c $(BONUS_SRC_DIR)/checker_bonus.c $(BONUS_SRC_DIR)/double_instractions_bonus.c $(BONUS_SRC_DIR)/get_next_line_bonus.c $(BONUS_SRC_DIR)/get_next_line_utils_bonus.c $(BONUS_SRC_DIR)/instructions_bonus.c $(BONUS_SRC_DIR)/pars_bonus.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc -g

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	Make -C libft
	$(CC) $(OBJS) libft.a -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	Make -C libft
	$(CC) $(OBJS_BONUS) libft.a -o $(BONUS_NAME)

$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_SRC_DIR)/checker_bonus.h $(BONUS_SRC_DIR)/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	Make clean -C libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	Make fclean -C libft
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
