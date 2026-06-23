/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsi-yi <tsi-yi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:55:53 by tsi-yi            #+#    #+#             */
/*   Updated: 2026/06/07 17:20:52 by tsi-yi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnum(int num)
{
	char	c;

	c = num + '0';
	write(1, &c, 1);
}

void	print_grid(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putnum(grid[row][col]);
			if (col != size - 1)
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
