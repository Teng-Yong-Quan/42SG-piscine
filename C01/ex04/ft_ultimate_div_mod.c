/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:33:43 by yteng             #+#    #+#             */
/*   Updated: 2026/05/29 12:42:13 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;
	int	temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = temp_a / temp_b;
	*b = temp_a % temp_b;
}
/*
int	main(void)
{
	int	c;
	int	d;

	c = 47;
	d = 12;
	printf("before c d: %d, %d\n", c, d);
	ft_ultimate_div_mod(&c, &d);
	printf("after c d: %d, %d\n", c, d);
}*/
