NAME = push_swap

OBJS = push_swap_util.o utilitis.o push_swap.o instructions.o pars.o

CFLAGS = -Wall -Wextra -Werror

CC = cc -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) libft.a -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
