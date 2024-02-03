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

SRC = push_swap_util.c ft_free.c utilitis.c push_swap.c instructions.c ft_pars.c ft_atoi.c ft_error.c ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_split.c ft_strjoin.c ft_strlen.c
BONUS_SRC_DIR = bonus
BONUS_SRC = $(BONUS_SRC_DIR)/checker_util_bonus.c $(BONUS_SRC_DIR)/checker_bonus.c $(BONUS_SRC_DIR)/double_instractions_bonus.c $(BONUS_SRC_DIR)/get_next_line_bonus.c $(BONUS_SRC_DIR)/get_next_line_utils_bonus.c $(BONUS_SRC_DIR)/instructions_bonus.c $(BONUS_SRC_DIR)/pars_bonus.c $(BONUS_SRC_DIR)/ft_strjoin_bonus.c ft_atoi.c ft_error.c ft_strjoin.c ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_split.c ft_strlen.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $(BONUS_NAME)

$(BONUS_SRC_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_SRC_DIR)/checker_bonus.h $(BONUS_SRC_DIR)/get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
