NAME = push_swap
BONUS_NAME = checker

SRC = push_swap_util.c utilitis.c push_swap.c instructions.c pars.c
BONUS_SRC_DIR = bonus
BONUS_SRC = $(BONUS_SRC_DIR)/checker_util.c $(BONUS_SRC_DIR)/checker.c $(BONUS_SRC_DIR)/double_instractions.c $(BONUS_SRC_DIR)/get_next_line.c $(BONUS_SRC_DIR)/get_next_line_utils.c $(BONUS_SRC_DIR)/instructions.c $(BONUS_SRC_DIR)/pars.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BONUS_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) libft.a -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) libft.a -o $(BONUS_NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: $(BONUS_SRC_DIR)/%.c $(BONUS_SRC_DIR)/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
