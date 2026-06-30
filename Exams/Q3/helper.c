/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:18:13 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 20:13:15 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_multi.h"

int	ft_strlen(char *str)
{
	char	*ptr;
	int		counter;

	counter = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		counter++;
		ptr++;
	}
	return (counter);
}

int	ft_intlen(int *int_arr, int len)
{
	int	index;
	int	counter;

	counter = 0;
	index = 0;
	while (index < len - 1 && int_arr[index] == 0)
		index++;
	while (index < len)
	{
		counter++;
		index++;
	}
	return (counter);
}
