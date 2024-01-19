NAME = ../libft.a

OBJS = ft_atoi.o ft_lstadd_back.o ft_lstadd_front.o ft_lstnew.o ft_lstsize.o ft_split.o ft_error.o

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
