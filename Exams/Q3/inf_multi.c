/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_multi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:50:15 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 20:15:49 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_multi.h"

int	*multiply(char c1, char c2, int *int_arr, int index)
{
	int	val;

	val = (c1 - '0') * (c2 - '0');
	int_arr[index] += val % 10;
	int_arr[index - 1] += val / 10;
	return (int_arr);
}

int	*multiply_loop(char *s1, char *s2, int *int_arr)
{
	int	s1_index;
	int	s2_index;
	int	s1_len;

	s1_index = ft_strlen(s1) - 1;
	s2_index = ft_strlen(s2) - 1;
	s1_len = ft_strlen(s1);
	while (s2_index >= 0)
	{
		if (s2[s2_index] == '-')
			break ;
		while (s1_index >= 0)
		{
			if (s1[s1_index] == '-')
				break ;
			int_arr = multiply(s1[s1_index], s2[s2_index],
					int_arr, s1_index + s2_index + 1);
			s1_index--;
		}
		s1_index = s1_len - 1;
		s2_index--;
	}
	return (int_arr);
}

int	*normalize(int *arr, int len)
{
	int	index;

	index = len - 1;
	while (index > 0)
	{
		arr[index - 1] += arr[index] / 10;
		arr[index] %= 10;
		index--;
	}
	return (arr);
}

char	*ft_copy(int *int_arr, int arr_len, char *s1, char *s2)
{
	char	*output;
	int		o_index;
	int		i_index;
	int		neg;

	o_index = 0;
	i_index = 0;
	neg = ((s1[o_index] == '-' && s2[o_index] != '-')
			|| (s1[o_index] != '-' && s2[o_index] == '-'));
	output = malloc(ft_intlen(int_arr, arr_len) + 1 + neg);
	if (!output)
	{
		free(int_arr);
		return (NULL);
	}
	if (neg)
		output[o_index++] = '-';
	while (i_index < arr_len - 1 && int_arr[i_index] == 0)
		i_index++;
	while (i_index < arr_len)
		output[o_index++] = int_arr[i_index++] + '0';
	output[o_index] = '\0';
	free(int_arr);
	return (output);
}

char	*infinite_multiplication(char *s1, char *s2)
{
	int		len;
	int		*int_arr;
	int		index;

	len = ft_strlen(s1) + ft_strlen(s2);
	index = 0;
	int_arr = malloc(len * sizeof (int));
	if (!int_arr)
		return (NULL);
	while (index < len)
		int_arr[index++] = 0;
	int_arr = multiply_loop(s1, s2, int_arr);
	int_arr = normalize(int_arr, len);
	index = 0;
	return (ft_copy(int_arr, len, s1, s2));
}
