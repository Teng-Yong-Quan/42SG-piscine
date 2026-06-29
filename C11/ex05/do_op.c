/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:47:09 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 17:11:54 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_operation(int first, int second, char op)
{
	if (op == '+')
		ft_putnbr(first + second);
	else if (op == '-')
		ft_putnbr(first - second);
	else if (op == '*')
		ft_putnbr(first * second);
	else if (op == '/')
	{
		if (second == 0)
			write(1, "Stop : division by zero", 23);
		else
			ft_putnbr(first / second);
	}
	else if (op == '%')
	{
		if (second == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(first % second);
	}
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	int		first;
	int		second;
	char	op;

	first = 0;
	second = 0;
	op = 0;
	if (argc == 4)
	{
		op = argv[2][0];
		first = ft_atoi(argv[1]);
		second = ft_atoi(argv[3]);
		ft_operation(first, second, op);
		write(1, "\n", 1);
	}
	return (0);
}
