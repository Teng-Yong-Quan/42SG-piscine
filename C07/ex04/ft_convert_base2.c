/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:30:19 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 10:30:19 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	get_divisor_count(long num, int base, long *divisor, int *count)
{
	*divisor = 1;
	*count = 1;
	if (num < 0)
	{
		(*count)++;
		num = -num;
	}
	while (num / *divisor >= base)
	{
		*divisor *= base;
		(*count)++;
	}
}

char	*ft_putnbr_base(int nbr, char *base, int base_num)
{
	long	divisor;
	long	num;
	char	*output;
	int		count;
	int		index;

	num = nbr;
	index = 0;
	get_divisor_count(num, base_num, &divisor, &count);
	output = malloc(count + 1);
	if (!output)
		return (NULL);
	if (nbr < 0)
	{
		output[index++] = '-';
		num = -nbr;
	}
	while (divisor > 0)
	{
		output[index++] = base[(num / divisor) % base_num];
		divisor /= base_num;
	}
	output[index] = '\0';
	return (output);
}
