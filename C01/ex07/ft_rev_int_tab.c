/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:57:37 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:37:42 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
*/
void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	current_index;

	current_index = 0;
	while (current_index < (size / 2))
	{
		swap(tab + current_index, tab + (size - current_index - 1));
		current_index++;
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

	test[0] = 0;
	test[1] = 1;
	test[2] = 2;
	test[3] = 3;
	test[4] = 4;
	test[5] = 5;
	test[6] = 6;
	test[7] = 7;
	test[8] = 8;
	printf("Before: ");
	print_array(test, 9);
	printf("\n");
	ft_rev_int_tab(test, 9);
	printf("After: ");
	print_array(test, 9);
	printf("\n");
}*/
