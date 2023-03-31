NAME = megaphone
FLAGS = -Wall -Werror -Wextra
SRCS = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	cc $(FLAGS) -std=c++98 $(SRCS)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re

test:
	