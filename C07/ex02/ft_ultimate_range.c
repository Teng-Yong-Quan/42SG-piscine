/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:51:12 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 15:57:33 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		*arr;
	long	index;
	long	int_range;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	int_range = max - min;
	index = 0;
	arr = (int *)malloc(int_range * sizeof(int));
	if (!arr)
		return (-1);
	while (index < int_range)
	{
		arr[index] = min;
		min++;
		index++;
	}
	*range = arr;
	return ((int)int_range);
}
