/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:49:56 by yteng             #+#    #+#             */
/*   Updated: 2026/06/11 18:02:13 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **argv, int src, int dest)
{
	char	*temp;

	temp = argv[src];
	argv[src] = argv[dest];
	argv[dest] = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_params(char **argv, int size)
{
	int	src;
	int	des;
	int	counter;

	counter = size;
	while (counter > 1)
	{
		src = 1;
		des = src + 1;
		while (des <= counter)
		{
			if (ft_strcmp(argv[des], argv[src]) > 0)
				src = des;
			des++;
		}
		swap(argv, src, counter);
		counter--;
	}
}

int	main(int argc, char **argv)
{
	int	index;

	if (argc > 1)
	{
		ft_sort_params(argv, argc - 1);
		index = 1;
		while (index <= argc - 1)
		{
			while (*argv[index] != '\0')
			{
				write(1, argv[index], 1);
				argv[index]++;
			}
			write(1, "\n", 1);
			index++;
		}
	}
	return (0);
}
