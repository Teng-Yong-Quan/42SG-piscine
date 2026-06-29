/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 15:18:58 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 20:41:33 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	index;
	int	*new_tab;

	new_tab = malloc(length * sizeof(int));
	if (!new_tab)
		return (NULL);
	index = 0;
	while (index < length)
	{
		new_tab[index] = f(tab[index]);
		index++;
	}
	return (new_tab);
}
