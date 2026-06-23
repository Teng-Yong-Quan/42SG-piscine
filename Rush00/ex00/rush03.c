/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:55:08 by gabrlee           #+#    #+#             */
/*   Updated: 2026/06/23 21:03:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);

void	ft_choosechar(int r, int c, int w, int l)
{
	if (r == 1 || r == l || c == 1 || c == w)
	{
		if ((r == 1 && (c == 1 || c == w)) || (r == l && (c == 1 || c == w)))
		{
			if (c == 1)
			{
				ft_putchar('A');
			}
			else
			{
				ft_putchar('C');
			}
		}
		else
		{
			ft_putchar('B');
		}
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int width, int length)
{
	int		cur_row;
	int		cur_col;

	cur_row = 1;
	cur_col = 1;
	if (width <= 0 || length <= 0)
	{
		write(2, "invalid input\n", 14);
		return ;
	}
	while (cur_row <= length)
	{
		while (cur_col <= width)
		{
			ft_choosechar(cur_row, cur_col, width, length);
			cur_col = cur_col + 1;
		}
		write(1, "\n", 1);
		cur_row = cur_row + 1;
		cur_col = 1;
	}
}
