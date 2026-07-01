/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 20:36:36 by yteng             #+#    #+#             */
/*   Updated: 2026/07/01 22:00:08 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_nbr(char c, unsigned int d)
{
	unsigned int	divisor;
	char			e;

	divisor = 1;
	e = 0;
	while (d / divisor > 9)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		e = ((d / divisor) % 10) + '0';
		write(1, &e, 1);
		divisor /= 10;
	}
	write(1, &c, 1);
}

void	print_count_alpha(unsigned int *occurrences,
	int *sequence, int last_seq)
{
	int		index;
	int		curr_seq;

	index = 0;
	curr_seq = 1;
	while (curr_seq <= last_seq)
	{
		while (index < 26)
		{
			if (sequence[index] == curr_seq)
			{
				ft_putchar_nbr(index + 97, occurrences[index]);
				if (curr_seq <= last_seq - 1)
					write(1, ", ", 2);
				break ;
			}
			index++;
		}
		index = 0;
		curr_seq++;
	}
}

void	count_alpha(char *str, unsigned int *occurrences, int *sequence)
{
	int				num;
	unsigned int	seq;
	char			c;

	num = 0;
	seq = 0;
	c = 0;
	while (*str != '\0')
	{
		c = *str;
		if (65 <= c && c <= 90)
			c += 32;
		if (97 <= c && c <= 122)
		{
			num = c - 97;
			occurrences[num]++;
			if (!sequence[num])
				sequence[num] = ++seq;
		}
		str++;
	}
	print_count_alpha(occurrences, sequence, seq);
}

int	main(int argc, char **argv)
{
	unsigned int	occurrences[26];
	int				sequence[26];
	int				num;

	num = 0;
	while (num < 26)
	{
		occurrences[num] = 0;
		sequence[num++] = 0;
	}
	if (argc == 2)
		count_alpha(argv[1], occurrences, sequence);
	write(1, "\n", 1);
	return (0);
}
