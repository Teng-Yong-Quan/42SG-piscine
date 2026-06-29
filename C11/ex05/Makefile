# ─── Project Settings ────────────────────────────────────────────────────────

NAME    = do-op
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# ─── Source Files ─────────────────────────────────────────────────────────────

SRCS    =   do_op.c \
            ft_atoi.c \
            ft_putnbr.c

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