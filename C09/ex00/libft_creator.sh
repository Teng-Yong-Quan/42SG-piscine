cc -Wall -Wextra -Werror -c ft_putchar.c
cc -Wall -Wextra -Werror -c ft_swap.c
cc -Wall -Wextra -Werror -c ft_putstr.c
cc -Wall -Wextra -Werror -c ft_strlen.c
cc -Wall -Wextra -Werror -c ft_strcmp.c

ar rcs libft.a \
	ft_putchar.o \
	ft_swap.o \
	ft_putstr.o \
	ft_strlen.o \
	ft_strcmp.o