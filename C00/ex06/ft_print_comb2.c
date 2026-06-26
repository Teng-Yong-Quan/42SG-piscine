/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:45:04 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:36:34 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(char c, char d)
{
	write(1, &c, 1);
	write(1, &d, 1);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first < 99)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_putchars((first / 10) + '0', (first % 10) + '0');
			write(1, " ", 1);
			ft_putchars((second / 10) + '0', (second % 10) + '0');
			if (first < 98)
			{
				write(1, ", ", 2);
			}
			second++;
		}
		first++;
	}
}
