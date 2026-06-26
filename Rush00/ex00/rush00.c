/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:55:08 by gabrlee           #+#    #+#             */
/*   Updated: 2026/06/26 14:43:06 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_choosechar(int r, int c, int w, int l)
{
	if (r == 1 || r == l || c == 1 || c == w)
	{
		if ((r == 1 && (c == 1 || c == w)) || (r == l && (c == 1 || c == w)))
		{
			ft_putchar('o');
		}
		else
		{
			if (r == 1 || r == l)
			{
				ft_putchar('-');
			}
			else
			{
				ft_putchar('|');
			}
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
