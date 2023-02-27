NAME = ClapTrap
CC = c++
SRCS =	./ClapTrap.cpp\
		./ScavTrap.cpp\
		./main.cpp\

FLAGS = -Wall -Wextra -Werror -g3 -std=c++98
OBJS = $(SRCS:.cpp=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -c

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
