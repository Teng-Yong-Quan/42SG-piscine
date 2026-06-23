/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:19:27 by yteng             #+#    #+#             */
/*   Updated: 2026/06/09 15:09:18 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	get_divisor(long num, int base)
{
	long	divisor;

	divisor = 1;
	while (num / divisor >= base)
		divisor *= base;
	return (divisor);
}

int	get_base(char *base)
{
	int	curr;
	int	move;

	curr = 0;
	move = 0;
	while (base[curr])
	{
		move = curr + 1;
		if (base[curr] == '+' || base[curr] == '-'
			|| base[curr] <= 32 || base[curr] == 127)
			return (0);
		while (base[move])
		{
			if (base[move] == base[curr])
				return (0);
			move++;
		}
		curr++;
	}
	return (curr);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_num;
	int		print_num;
	long	divisor;
	long	num;

	base_num = get_base(base);
	if (base_num < 2)
		return ;
	num = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	divisor = get_divisor(num, base_num);
	while (divisor > 0)
	{
		print_num = (num / divisor) % base_num;
		write(1, &base[print_num], 1);
		divisor /= base_num;
	}
}
