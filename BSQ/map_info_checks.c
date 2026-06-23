/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:32:02 by cherlim           #+#    #+#             */
/*   Updated: 2026/06/16 15:37:30 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int	symbol_check(char *str, int start, int end)
{
	int	i;
	int	j;

	i = start;
	while (i < end)
	{
		if (!(32 <= str[i] && str[i] <= 126))
			return (0);
		j = i + 1;
		while (j < end)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_row_num(char *str, int end)
{
	int	len;
	int	row_num;

	len = 0;
	row_num = 0;
	while (len < end)
	{
		if (!('0' <= str[len] && str[len] <= '9'))
			return (0);
		row_num = row_num * 10 + (str[len] - '0');
		len++;
	}
	return (row_num);
}

int	map_info_checks(char *str, int len)
{
	int	index;

	if (len == 0)
		return (0);
	index = len - 3;
	if (index <= 0)
		return (0);
	return (get_row_num(str, index) && symbol_check(str, index, len));
}

t_map_info	*generate_map_info(char *str, int len)
{
	t_map_info	*input_ptr;
	int			index;

	if (!(map_info_checks(str, len)))
		return (NULL);
	index = len - 3;
	input_ptr = malloc(sizeof(t_map_info));
	if (!input_ptr)
		return (NULL);
	*input_ptr = (t_map_info){get_row_num(str, index),
		str[index], str[index + 1], str[index + 2]};
	return (input_ptr);
}

t_map_info	*extract_map_info(char *str)
{
	char		*ptr_arr;
	int			len;
	t_map_info	*map_info_ptr;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (!len)
		return (NULL);
	ptr_arr = malloc((len + 1) * sizeof(char));
	if (!ptr_arr)
		return (NULL);
	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
	{
		ptr_arr[len] = str[len];
		len++;
	}
	ptr_arr[len] = '\0';
	map_info_ptr = generate_map_info(ptr_arr, len);
	free(ptr_arr);
	return (map_info_ptr);
}
