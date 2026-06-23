/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 14:51:44 by yteng             #+#    #+#             */
/*   Updated: 2026/06/10 15:04:15 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	num;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		num = 1;
		while (power > 0)
		{
			num *= nb;
			power--;
		}
		return (num);
	}
}
