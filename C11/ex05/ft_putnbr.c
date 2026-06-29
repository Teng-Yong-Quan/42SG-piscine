/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:35 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 17:10:22 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_convert_to_pos(long num)
{
	long	n;

	n = num;
	if (n < 0)
	{
		n = -n;
	}
	return (n);
}

void	ft_printdash(long num)
{
	if (num < 0)
	{
		ft_putchar('-');
	}
}

void	ft_putnbr(long nb)
{
	long	print_num;
	long	divisor;

	ft_printdash(nb);
	print_num = nb;
	divisor = 1;
	while (!(-9 <= print_num / divisor && print_num / divisor <= 9))
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		print_num = print_num / divisor;
		print_num = print_num % 10;
		print_num = ft_convert_to_pos(print_num);
		ft_putchar(print_num + '0');
		print_num = nb;
		divisor = divisor / 10;
	}
}
