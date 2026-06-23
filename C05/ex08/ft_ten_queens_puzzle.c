/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:48:31 by yteng             #+#    #+#             */
/*   Updated: 2026/06/11 11:26:38 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	can_place(int board[10][10], int row, int col)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (board[row][i])
			return (0);
		i++;
	}
	i = 1;
	while (row - i >= 0 && col - i >= 0)
	{
		if (board[row - i][col - i])
			return (0);
		i++;
	}
	i = 1;
	while (row + i <= 9 && col - i >= 0)
	{
		if (board[row + i][col - i])
			return (0);
		i++;
	}
	return (1);
}

void	print_queens(int board[10][10])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 10)
		{
			if (board[j][i])
			{
				c = j + '0';
				write(1, &c, 1);
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	write(1, "\n", 1);
}

void	solve(int col, int board[10][10], int *solution_count)
{
	int	row;

	if (col == 10)
	{
		print_queens(board);
		*solution_count = *solution_count + 1;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (board[row][col] == 0 && can_place(board, row, col))
		{
			board[row][col] = 1;
			solve(col + 1, board, solution_count);
		}
		board[row][col] = 0;
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	solution;
	int	*solution_count;
	int	col;
	int	row;
	int	board[10][10];

	col = 0;
	row = 0;
	solution = 0;
	solution_count = &solution;
	while (row < 10)
	{
		while (col < 10)
		{
			board[row][col] = 0;
			col++;
		}
		col = 0;
		row++;
	}
	col = 0;
	solve(col, board, solution_count);
	return (*solution_count);
}
