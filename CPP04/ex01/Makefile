NAME = Fire
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = Animal.hpp Cat.hpp Dog.hpp Brain.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -std=c++98 -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
