NAME = push_swap

OBJS = push_swap_util.o utilitis2.o utilitis.o push_swap.o instructions.o

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
