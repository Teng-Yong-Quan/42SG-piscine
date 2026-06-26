/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:06:31 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 15:11:19 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	c;
	int	d;

	c = 1;
	d = 2;
	printf("c before: %d\n", c);
	printf("d before: %d\n", d);
	ft_swap(&c, &d);
	printf("c after: %d\n", c);
	printf("d after: %d\n", d);
}*/
