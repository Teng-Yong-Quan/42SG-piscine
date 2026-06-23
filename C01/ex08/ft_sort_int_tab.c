/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:57:37 by yteng             #+#    #+#             */
/*   Updated: 2026/05/29 15:27:45 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	src;
	int	des;
	int	counter;

	counter = size;
	while (counter > 0)
	{
		src = 0;
		des = src + 1;
		while (des < counter)
		{
			if (*(tab + src) < *(tab + des))
			{
				src = des;
			}
			des++;
		}
		swap(tab + src, tab + counter - 1);
		counter--;
	}
}
/*
void	print_array(int *arr, int size)
{
	int	counter;

	counter = 0;
	while (counter < size)
	{
		printf("%d", *(arr + counter));
		counter++;
		if (counter < size)
		{
			printf(", ");
		}
	}
}

int	main(void)
{
	int	test[9];

	test[0] = 9;
	test[1] = 8;
	test[2] = 7;
	test[3] = 6;
	test[4] = 5;
	test[5] = 4;
	test[6] = 3;
	test[7] = 2;
	test[8] = 1;
	printf("Before: ");
	print_array(test, 9);
	printf("\n");
	ft_sort_int_tab(test, 9);
	printf("After: ");
	print_array(test, 9);
	printf("\n");
}*/
