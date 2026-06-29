/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:53:28 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 16:28:46 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	index;
	int	asc;
	int	desc;
	int	curr;

	if (length < 3)
		return (1);
	index = 0;
	asc = 1;
	desc = 1;
	while (index < length - 1)
	{
		curr = f(tab[index], tab[index + 1]);
		if (curr > 0)
			asc = 0;
		if (curr < 0)
			desc = 0;
		index++;
	}
	return (asc || desc);
}
