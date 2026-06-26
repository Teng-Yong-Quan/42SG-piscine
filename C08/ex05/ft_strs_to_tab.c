/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:56:43 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 16:24:12 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		len;

	len = ft_strlen(src);
	dup = malloc((len + 1) * sizeof(char));
	len = 0;
	if (!dup)
		return (NULL);
	while (src[len])
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

struct s_stock_str	*free_arr(int index, struct s_stock_str *arr)
{
	while (--index >= 0)
		free(arr[index].copy);
	free(arr);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			index;

	index = 0;
	arr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!arr)
		return (NULL);
	while (index < ac)
	{
		arr[index].copy = ft_strdup(av[index]);
		if (!arr[index].copy)
			return (free_arr(index, arr));
		arr[index].size = ft_strlen(av[index]);
		arr[index].str = av[index];
		index++;
	}
	arr[index].copy = 0;
	arr[index].str = 0;
	arr[index].size = 0;
	return (arr);
}
