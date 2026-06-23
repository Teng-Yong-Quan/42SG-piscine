/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsi-yi <tsi-yi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:55:37 by tsi-yi            #+#    #+#             */
/*   Updated: 2026/06/07 17:23:57 by tsi-yi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_check_value(int *clues, int *row_col_dim, int side);

int	check_col_state(int **board, int *row_col_dim, int value)
{
	int	row;
	int	col;
	int	curr_row;
	int	dim;

	row = 0;
	col = row_col_dim[1];
	curr_row = row_col_dim[0];
	dim = row_col_dim[2];
	while (row < dim)
	{
		if (board[row][col] == value)
			return (-1);
		row++;
	}
	board[curr_row][col] = value;
	return (curr_row == dim - 1);
}

int	check_col_top(int **board, int *row_col_dim, int check)
{
	int	row;
	int	counter;
	int	max_value;
	int	fix_col;
	int	dim;

	row = 0;
	dim = row_col_dim[2];
	fix_col = row_col_dim[1];
	counter = 0;
	max_value = 0;
	while (row < dim)
	{
		if (board[row][fix_col] > max_value)
		{
			max_value = board[row][fix_col];
			counter++;
		}
		row++;
	}
	return (counter == check);
}

int	check_col_bottom(int **board, int *row_col_dim, int check)
{
	int	row;
	int	counter;
	int	max_value;
	int	fix_col;
	int	dim;

	dim = row_col_dim[2];
	row = dim - 1;
	counter = 0;
	max_value = 0;
	fix_col = row_col_dim[1];
	while (row >= 0)
	{
		if (board[row][fix_col] > max_value)
		{
			max_value = board[row][fix_col];
			counter++;
		}
		row--;
	}
	return (counter == check);
}

int	check_col_main(int **board, int *row_col_dim, int *clues, int value)
{
	int	col_top_check;
	int	col_bottom_check;
	int	col_state;

	col_state = check_col_state(board, row_col_dim, value);
	if (col_state == -1)
		return (0);
	else if (col_state == 0)
		return (1);
	else
	{
		col_top_check = get_check_value(clues, row_col_dim, 0);
		col_bottom_check = get_check_value(clues, row_col_dim, 1);
		return (check_col_top(board, row_col_dim,
				col_top_check)
			&& check_col_bottom(board, row_col_dim, col_bottom_check));
	}
}
