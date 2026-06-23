/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:37:24 by yteng             #+#    #+#             */
/*   Updated: 2026/06/09 15:09:20 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	get_converted_num(char *str, char *base, int base_num)
{
	int	num;
	int	counter;

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

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	base_num;
	int	num;

	sign = 1;
	base_num = get_base(base);
	if (base_num < 2)
		return (0);
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
