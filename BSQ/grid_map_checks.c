/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_map_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:16:49 by yteng             #+#    #+#             */
/*   Updated: 2026/06/15 13:16:49 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

char	*get_grid_map_string(char *str)
{
	int		len;
	int		index;
	char	*ptr_arr;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	len++;
	index = 0;
	while (str[len + index])
		index++;
	if (!index)
		return (NULL);
	ptr_arr = malloc((index + 1) * sizeof(char));
	if (!ptr_arr)
		return (NULL);
	index = 0;
	while (str[len + index])
	{
		ptr_arr[index] = str[len + index];
		index++;
	}
	ptr_arr[index] = '\0';
	return (ptr_arr);
}

int	grid_map_checks(t_map_info *map_info_ptr, char *str,
	t_params *params, int index)
{
	while (str[index])
	{
		if (str[index] == '\n')
		{
			if (params->prev_col != -1 && params->prev_col != params->col)
				return (0);
			params->prev_col = params->col;
			params->col = 0;
			params->row++;
		}
		else if (str[index] != map_info_ptr->empty
			&& str[index] != map_info_ptr->obstacle)
			return (0);
		else
			params->col++;
		index++;
	}
	if (params->col > 0)
	{
		if (params->prev_col != -1 && params->prev_col != params->col)
			return (0);
		params->row++;
		params->prev_col = params->col;
	}
	return (params->prev_col > 0 && params->row == map_info_ptr->row_num);
}

t_grid_map	*extract_map(char *str, t_map_info *map_info_ptr)
{
	t_grid_map	*grid_map_ptr;
	t_params	params;
	t_params	*p_ptr;
	char		*ptr_arr;

	ptr_arr = get_grid_map_string(str);
	if (!ptr_arr)
		return (NULL);
	params = (t_params){0, 0, -1};
	p_ptr = &params;
	if (!(grid_map_checks(map_info_ptr, ptr_arr, p_ptr, 0)))
	{
		free(ptr_arr);
		return (NULL);
	}
	grid_map_ptr = malloc(sizeof(t_grid_map));
	if (!grid_map_ptr)
	{
		free(ptr_arr);
		return (NULL);
	}
	*grid_map_ptr = (t_grid_map){ptr_arr,
		p_ptr->row, p_ptr->prev_col};
	return (grid_map_ptr);
}
