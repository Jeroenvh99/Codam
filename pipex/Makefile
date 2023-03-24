NAME = pipex
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c \
	setup.c \
	free_utils.c \
	command_utils.c \
	processes.c \
	split_args.c \
	split_utils.c

all: $(NAME)

$(NAME): $(SRCS)
	$(MAKE) -C ./libft bonus_and_printf_and_gnl
	cc $(SRCS) $(CFLAGS) ./libft/libft.a -o $(NAME)

bonus: pipex

clean:
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re

test:
	pipex && cd tests && ./test.sh