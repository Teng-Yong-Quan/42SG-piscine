/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsi-yi <tsi-yi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:55:58 by tsi-yi            #+#    #+#             */
/*   Updated: 2026/06/07 17:23:40 by tsi-yi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		solve(int pos, int dim, int *clues, int **board);
int		count_clues(char *str, int count);
void	print_grid(int **grid, int size);

int	parse_clues(char *str, int *clues, int n)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			clues[idx] = 0;
			while (str[i] >= '1' && str[i] <= '9')
			{
				clues[idx] = clues[idx] * 10 + (str[i] - '0');
				i++;
			}
			if (clues[idx] < 1 || clues[idx] > n)
				return (-1);
			idx++;
			continue ;
		}
		i++;
	}
	return (idx);
}

int	init_grid(int **grid, int *clues, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		grid[i] = (int *)malloc(n * sizeof(int));
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(*grid);
			free(clues);
			return (0);
		}
		j = 0;
		while (j < n)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	free_grid(int **grid, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	setup(char *input, int ***grid, int **clues, int *n)
{
	int	total_clues;

	total_clues = count_clues(input, 0);
	if (total_clues < 1 || (total_clues % 4) != 0)
		return (0);
	*n = total_clues / 4;
	*clues = (int *)malloc(total_clues * sizeof(int));
	if (!(*clues))
		return (0);
	if (parse_clues(input, *clues, *n) <= 0)
	{
		free(*clues);
		return (0);
	}
	*grid = (int **)malloc((*n) * sizeof(int *));
	if (!(*grid))
	{
		free(*clues);
		return (0);
	}
	if (!init_grid(*grid, *clues, *n))
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			n;
	int			*clues;
	int			**grid;

	if (argc != 2 || !setup(argv[1], &grid, &clues, &n))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (solve(0, n, clues, grid))
		print_grid(grid, n);
	else
		write(1, "Error\n", 6);
	free_grid(grid, n);
	free(clues);
	return (0);
}
