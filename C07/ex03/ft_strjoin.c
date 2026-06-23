/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:51:22 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 15:50:42 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	inner_index;

	inner_index = 0;
	while (str[inner_index])
		inner_index++;
	return (inner_index);
}

int	all_strlen(char **strs, int size)
{
	int		len;
	int		index;

	len = 0;
	index = 0;
	while (index < size)
	{
		len += ft_strlen(strs[index]);
		index++;
	}
	return (len);
}

int	ft_strcopy(char *src, char *dest, int dest_index)
{
	int	src_index;

	src_index = 0;
	while (src[src_index])
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	return (dest_index);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*output;
	int		index;
	int		curr;

	if (!size)
	{
		output = malloc(1);
		if (!output)
			return (NULL);
		output[0] = '\0';
		return (output);
	}
	output = malloc((size - 1) * ft_strlen(sep) + all_strlen(strs, size) + 1);
	if (!output)
		return (NULL);
	index = 0;
	curr = 0;
	while (index < size)
	{
		curr = ft_strcopy(strs[index], output, curr);
		if (index++ < size - 1)
			curr = ft_strcopy(sep, output, curr);
	}
	output[curr] = '\0';
	return (output);
}
