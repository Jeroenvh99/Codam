NAME = libftprintf.a
COMPILEFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
SRCS = ft_printf.c\
	ft_hex_utils.c\
	ft_printf_utils.c\

all: $(NAME)

.o:
	cc $(COMPILEFLAGS) -c $< -o ${%.c=%.o}

$(NAME): $(OBJS)
	$(MAKE) -C ./sources
	cp ./sources/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(MAKE) -C ./sources fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re
