CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = main.c helper_functions.c parsin/check_path.c
OBJS = $(SRCS:.c=.o)

NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all