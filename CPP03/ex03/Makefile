NAME = weird
CXX = c++
FLAGS = -Wall -Werror -Wextra -Wshadow
SRCS = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJS = ${SRCS:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -std=c++98 -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
