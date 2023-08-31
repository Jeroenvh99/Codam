NAME = violence
CC = c++
FLAGS = -Wall -Werror -Wextra
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -g -std=c++98 -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
