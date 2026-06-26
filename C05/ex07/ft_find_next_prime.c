/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 15:19:55 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:42:08 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	num;
	int	is_prime;

	if (nb <= 2)
		return (2);
	else
	{
		while (1)
		{
			num = 2;
			is_prime = 1;
			while (num < nb)
			{
				if (nb % num == 0)
				{
					nb++;
					is_prime = 0;
					break ;
				}
				num++;
			}
			if (is_prime)
				return (nb);
		}
	}
}
