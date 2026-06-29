/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:47:41 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 20:41:23 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	index;
	int	counter;

	index = 0;
	counter = 0;
	while (index < length)
	{
		if (f(tab[index++]))
			counter++;
	}
	return (counter);
}
