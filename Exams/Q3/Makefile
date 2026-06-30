# ─── Project Settings ────────────────────────────────────────────────────────

NAME    = inf_multi
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# ─── Source Files ─────────────────────────────────────────────────────────────

SRCS    =   main.c \
            helper.c \
            inf_multi.c

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