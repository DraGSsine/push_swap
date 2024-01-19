NAME = ../checker

OBJS = checker.o checker_util.o get_next_line.o get_next_line_utils.o pars.o instructions.o double_instractions.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) ../libft.a -o $(NAME)

%.o: %.c checker.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
