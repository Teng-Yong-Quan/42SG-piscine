# ─── Project Settings ────────────────────────────────────────────────────────

NAME    = output
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# ─── Source Files ─────────────────────────────────────────────────────────────

SRCS    =   main.c \
            ft_functions.c \
            ft_split.c \
			sort_list.c

# ─── Object Files ─────────────────────────────────────────────────────────────

OBJS    = $(SRCS:.c=.o)

# ─── Rules ────────────────────────────────────────────────────────────────────

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ─── Phony ────────────────────────────────────────────────────────────────────

.PHONY: all clean fclean re