NAME = push_swap
COMPILEFLAGS = -Wall -Werror -Wextra
OBJS = ${SRCS:.c=.o}
BONUS_OBJS = ${BONUS_SRCS:.c=.o}
OVERLAPPING_OBJS = ${OVERLAPPING_SRCS:.c=.o}
SRCS = push_swap.c\
	sort_three.c\
	get_cheapest_ab.c\
	get_cheapest_ba.c\
	sort_list.c\
	sort_list_2.c\
	optimise_instr.c
BONUS_SRCS = checker.c
OVERLAPPING_SRCS = rules.c\
	input_utils.c\
	list_utils.c

all: $(NAME)

.c.o:
	cc $(COMPILEFLAGS) -c $<

$(NAME): $(OBJS) $(OVERLAPPING_OBJS)
	$(MAKE) -C ./libft bonus_and_printf_and_gnl
	cc $(OBJS) $(OVERLAPPING_OBJS) $(COMPILEFLAGS) ./libft/libft.a -o push_swap

checker: $(BONUS_OBJS) $(OVERLAPPING_OBJS)
	$(MAKE) -C ./libft bonus_and_printf_and_gnl
	cc $(BONUS_OBJS) $(OVERLAPPING_OBJS) $(COMPILEFLAGS) ./libft/libft.a -o checker

clean:
	$(MAKE) -C ./libft fclean
	rm -f $(OBJS) $(BONUS_OBJS) $(OVERLAPPING_OBJS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: clean fclean all bonus re

test:
	cc 