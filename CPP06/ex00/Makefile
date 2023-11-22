NAME = samebutdifferent
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
SRCS = main.cpp ScalarConverter.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

test:
