CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex_test
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME) compile_pipex

compile_pipex:
	cd ../pipex && make

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): *.c
#	$(CC) -c $(SRCS)

*.c:
	$(CC) -c $@

clean:
	rm -f *.o && cd ../pipex && make clean

fclean: clean
	rm -f $(NAME) && cd ../pipex && make fclean

re: fclean all

.PHONY: all clean fclean re compile_pipex