/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 15:27:35 by yteng             #+#    #+#             */
/*   Updated: 2026/06/02 11:07:49 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_convert_to_pos(int num)
{
	if (num < 0)
	{
		num = -num;
	}
	return (num);
}

void	ft_printdash(int num)
{
	if (num < 0)
	{
		ft_putchar('-');
	}
}

void	ft_putnbr(int nb)
{
	int	print_num;
	int	divisor;

	ft_printdash(nb);
	print_num = nb;
	divisor = 1;
	while (!(-9 <= nb / divisor && nb / divisor <= 9))
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
