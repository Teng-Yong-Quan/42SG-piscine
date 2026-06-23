/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsi-yi <tsi-yi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:55:49 by tsi-yi            #+#    #+#             */
/*   Updated: 2026/06/07 17:20:28 by tsi-yi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_row_main(int **board, int *row_col_dim, int *clues, int value);
int	check_col_main(int **board, int *row_col_dim, int *clues, int value);

int	can_place(int **board, int *row_col_dim, int *clues, int value)
{
	int	check_row_status;
	int	check_col_status;
	int	row;
	int	col;

	row = row_col_dim[0];
	col = row_col_dim[1];
	check_row_status = check_row_main(board, row_col_dim, clues, value);
	board[row][col] = 0;
	if (!check_row_status)
		return (0);
	check_col_status = check_col_main(board, row_col_dim, clues, value);
	board[row][col] = 0;
	return (check_row_status && check_col_status);
}

int	get_check_value(int *clues, int *row_col_dim, int side)
{
	int	input;
	int	dim;

	dim = row_col_dim[2];
	if (side == 0 || side == 1)
		input = row_col_dim[1];
	else
		input = row_col_dim[0];
	return (clues[dim * side + input]);
}

int	solve(int pos, int dim, int *clues, int **board)
{
	int	row;
	int	col;
	int	value;
	int	row_col_dim[3];

	if (pos == dim * dim)
		return (1);
	row = pos / dim;
	col = pos % dim;
	row_col_dim[0] = row;
	row_col_dim[1] = col;
	row_col_dim[2] = dim;
	value = 1;
	while (value <= dim)
	{
		if (can_place(board, row_col_dim, clues, value))
		{
			board[row][col] = value;
			if (solve(pos + 1, dim, clues, board))
				return (1);
			board[row][col] = 0;
		}
		value++;
	}
	return (0);
}

int	count_clues(char *str, int count)
{
	int	i;
	int	space;

	i = 0;
	count = 0;
	space = 0;
	while (str[i])
	{
		if ((str[i] >= '1' && str[i] <= '9') && !space)
		{
			count++;
			while (str[i] >= '1' && str[i] <= '9')
				i++;
			space = 1;
			continue ;
		}
		else if (str[i] == ' ' && space)
			space = 0;
		else
			return (-1);
		i++;
	}
	if (!count || (i > 0 && str[i - 1] == ' '))
		return (-1);
	return (count);
}
