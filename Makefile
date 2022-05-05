CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex_test
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): *.c
#	$(CC) -c $(SRCS)

*.c:
	$(CC) -c $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re