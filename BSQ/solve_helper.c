/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 14:21:59 by cherlim           #+#    #+#             */
/*   Updated: 2026/06/16 15:38:22 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

int	find_min(int a, int b, int c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	draw_square(t_grid_map *grid_map, t_max_score_params *params, char fill)
{
	int	curr_r;
	int	curr_c;
	int	low_r;
	int	low_c;

	curr_r = 0;
	low_r = params->row - params->max_score + 1;
	low_c = params->col - params->max_score + 1;
	while (curr_r < grid_map->rows)
	{
		curr_c = 0;
		while (curr_c <= grid_map->cols)
		{
			if (low_r <= curr_r && curr_r <= params->row
				&& low_c <= curr_c && curr_c <= params->col)
				grid_map->map[curr_r * (grid_map->cols + 1) + curr_c] = fill;
			curr_c++;
		}
		write (1, &grid_map->map[curr_r * curr_c], curr_c);
		curr_r++;
	}
}

int	get_cell_score(int *scores, int r, int c, int col)
{
	if (r == 0 || c == 0)
		return (1);
	return (find_min(scores[(r - 1) * col + c], scores[r * col + (c - 1)],
			scores[(r - 1) * col + (c - 1)]) + 1);
}

void	check_and_save(int score, int r, int c, t_max_score_params *params)
{
	if (score > params->max_score)
	{
		params->row = r;
		params->col = c;
		params->max_score = score;
	}
}
