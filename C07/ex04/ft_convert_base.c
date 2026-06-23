/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:30:08 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 10:30:08 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	get_divisor_count(long num, int base, long *divisor, int *count);
char	*ft_putnbr_base(int nbr, char *base, int base_num);

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

long	get_converted_num(char *str, char *base, int base_num)
{
	long	num;
	int		counter;

	num = 0;
	while (*str != '\0')
	{
		counter = 0;
		while (counter < base_num)
		{
			if (*str == base[counter])
			{
				num = num * base_num + counter;
				str++;
				break ;
			}
			counter++;
		}
		if (counter == base_num)
			break ;
	}
	return (num);
}

long	ft_atoi_base(char *str, char *base, int base_num)
{
	int		sign;
	long	num;

	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	num = get_converted_num(str, base, base_num);
	return (sign * num);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num_from;
	int		base_from_num;
	int		base_to_num;
	char	*output;

	base_from_num = get_base(base_from);
	base_to_num = get_base(base_to);
	if (base_from_num < 2 || base_to_num < 2)
		return (NULL);
	num_from = ft_atoi_base(nbr, base_from, base_from_num);
	if (num_from < -2147483648L || 2147483647L < num_from)
		return (NULL);
	output = ft_putnbr_base((int)num_from, base_to, base_to_num);
	return (output);
}
