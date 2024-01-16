NAME = push_swap

OBJS = ft_lstcat.o push_swap_util.o ft_lstsize.o ft_lstadd_back.o ft_lstnew.o push_swap.o instructions.o ft_lstadd_front.o

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
