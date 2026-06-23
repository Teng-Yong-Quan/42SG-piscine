/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsi-yi <tsi-yi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:55:45 by tsi-yi            #+#    #+#             */
/*   Updated: 2026/06/07 17:30:31 by tsi-yi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_check_value(int *clues, int *row_col_dim, int side);

int	check_row_state(int **board, int *row_col_dim, int value)
{
	int	row;
	int	col;
	int	dim;
	int	curr_col;

	row = row_col_dim[0];
	curr_col = row_col_dim[1];
	dim = row_col_dim[2];
	col = 0;
	while (col < dim)
	{
		if (board[row][col] == value)
			return (-1);
		col++;
	}
	board[row][curr_col] = value;
	return (curr_col == dim - 1);
}

int	check_row_left(int **board, int *row_col_dim, int check)
{
	int	col;
	int	counter;
	int	max_value;
	int	fix_row;
	int	dim;

	col = 0;
	fix_row = row_col_dim[0];
	counter = 0;
	max_value = 0;
	dim = row_col_dim[2];
	while (col < dim)
	{
		if (board[fix_row][col] > max_value)
		{
			max_value = board[fix_row][col];
			counter++;
		}
		col++;
	}
	return (counter == check);
}

int	check_row_right(int **board, int *row_col_dim, int check)
{
	int	col;
	int	counter;
	int	max_value;
	int	fix_row;
	int	dim;

	dim = row_col_dim[2];
	col = dim - 1;
	counter = 0;
	max_value = 0;
	fix_row = row_col_dim[0];
	while (col >= 0)
	{
		if (board[fix_row][col] > max_value)
		{
			max_value = board[fix_row][col];
			counter++;
		}
		col--;
	}
	return (counter == check);
}

int	check_row_main(int **board, int *row_col_dim, int *clues, int value)
{
	int	row_left_check;
	int	row_right_check;
	int	row_state;

	row_state = check_row_state(board, row_col_dim, value);
	if (row_state == -1)
		return (0);
	else if (row_state == 0)
		return (1);
	else
	{
		row_left_check = get_check_value(clues, row_col_dim, 2);
		row_right_check = get_check_value(clues, row_col_dim, 3);
		return (check_row_left(board, row_col_dim, row_left_check)
			&& check_row_right(board, row_col_dim, row_right_check));
	}
}
