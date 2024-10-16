CC := c++
CFLAGS := -Wall -Wextra -Wextra -std=c++98 -g3 -fsanitize=address
SRCS := Account.cpp
NAME := tests

all:
	$(CC) $(CFLAGS) $(SRCS) $(NAME).cpp -o $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
