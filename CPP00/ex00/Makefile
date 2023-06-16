NAME = megaphone
FLAGS = -Wall -Werror -Wextra
SRCS = megaphone.cpp

all: $(NAME)

$(NAME): $(SRCS)
	g++ $(FLAGS) $(SRCS) -std=c++98 -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
