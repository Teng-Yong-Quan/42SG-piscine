/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 13:08:07 by cherlim           #+#    #+#             */
/*   Updated: 2026/06/16 15:35:40 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void	free_after_solve(t_grid_map *grid_map, t_map_info *map_info)
{
	free(grid_map->map);
	free(grid_map);
	free(map_info);
}

void	bsq_solve(t_grid_map *grid_map, t_map_info *map_info, int r, int c)
{
	int					*scores;
	t_max_score_params	params;
	int					i;

	scores = malloc(sizeof(int) * grid_map->rows * (grid_map->cols + 1));
	if (!scores)
		return ;
	params = (t_max_score_params){0, 0, -1};
	while (r < grid_map->rows)
	{
		i = r * (grid_map->cols + 1) + c;
		scores[i] = 0;
		if (grid_map->map[i] == map_info->empty)
			scores[i] = get_cell_score(scores, r, c, grid_map->cols + 1);
		check_and_save(scores[i], r, c, &params);
		c++;
		if (c == grid_map->cols)
		{
			c = 0;
			r++;
		}
	}
	draw_square(grid_map, &params, map_info->fill);
	free(scores);
}
