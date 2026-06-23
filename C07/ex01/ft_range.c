/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:40:28 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 15:57:18 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*arr;
	long	index;
	long	range;

	if (min >= max)
		return (NULL);
	index = 0;
	range = max - min;
	arr = (int *)malloc(range * sizeof(int));
	if (!arr)
		return (NULL);
	while (index < range)
	{
		arr[index] = min;
		min++;
		index++;
	}
	return (arr);
}
