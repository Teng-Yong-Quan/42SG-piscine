/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:54:47 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:36:47 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combination(char *arr, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		write(1, &arr[index], 1);
		index++;
	}
}

int	ft_initialise(char *arr, int index, int n)
{
	while (index < n)
	{
		arr[index] = index + '0';
		index++;
	}
	return (index);
}

int	ft_carryover(char *arr, int index, int n)
{
	while (index < n - 1)
	{
		arr[index + 1] = arr[index] + 1;
		index++;
	}
	return (index);
}

void	ft_print_combn(int n)
{
	char	arr[11];
	int		index;

	index = 0;
	index = ft_initialise(arr, index, n);
	while (1)
	{
		print_combination(arr, n);
		index = n - 1;
		while (index >= 0 && arr[index] == ('9' - n + index + 1))
			index--;
		if (index < 0)
			break ;
		else
			write(1, ", ", 2);
		arr[index]++;
		index = ft_carryover(arr, index, n);
	}
}
