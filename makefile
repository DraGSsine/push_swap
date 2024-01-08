NAME = push_swap

OBJS = ft_lstadd_back.o ft_lstnew.o push_swap.o instructions.o ft_lstadd_front.o

CFLAGS = -Wall -Wextra -Werror -g

CC = gcc -g

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
