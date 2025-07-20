CC = cc
CFLAGS = -Wall -Wextra -Werror


SRCS = main.c utils/helper_functions.c parsin/check_path.c parsin/check_map.c utils/get_next_line.c utils/get_next_line_utils.c \
		utils/split.c parsin/assign_col_tex.c
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

.SECONDARY: $(OBJS)