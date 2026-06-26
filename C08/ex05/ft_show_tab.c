/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:22:34 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 16:43:27 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long	ft_convert_to_pos(int num)
{
	long	n;

	n = num;
	if (n < 0)
		n = -n;
	return (n);
}

void	ft_putnbr(int nb)
{
	long	print_num;
	long	divisor;

	if (nb < 0)
		ft_putchar('-');
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

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		write(1, par->str, par->size);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		write(1, par->copy, par->size);
		write(1, "\n", 1);
		par++;
	}
}
