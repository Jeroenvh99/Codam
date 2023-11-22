NAME = Interfaces	
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra
SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = AMateria.hpp Character.hpp ICharacter.hpp Cure.hpp Ice.hpp MateriaSource.hpp IMateriaSource.hpp

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
