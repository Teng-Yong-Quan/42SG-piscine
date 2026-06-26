/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:21:06 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 15:11:28 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	num1;
	int	num2;

	num1 = 1000;
	num2 = 2000;
	printf("before div, mod: %d %d\n", num1, num2);
	ft_div_mod(5, 2, &num1, &num2);
	printf("after div, mod: %d %d\n", num1, num2);
}*/
