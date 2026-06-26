/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:30:30 by yteng             #+#    #+#             */
/*   Updated: 2026/06/18 10:30:30 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index++])
			return (1);
	}
	return (0);
}

int	word_counts(char *str, char *charset)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (is_separator(str[index], charset))
		{
			index++;
			continue ;
		}
		count++;
		while (str[index] && !is_separator(str[index], charset))
			index++;
	}
	return (count);
}

char	*ft_strdup(char *str, int *outer_index, char *charset)
{
	char	*string;
	int		count;
	int		len;

	len = 0;
	while (str[*outer_index + len]
		&& !is_separator(str[*outer_index + len], charset))
		len++;
	count = 0;
	string = malloc(len + 1);
	if (!string)
		return (NULL);
	while (count < len)
	{
		string[count] = str[*outer_index];
		(*outer_index)++;
		count++;
	}
	string[count] = '\0';
	return (string);
}

char	**ft_split(char *str, char *charset)
{
	int		outer_index;
	char	**string_arr;
	char	*string;
	int		word_index;

	string_arr = malloc((word_counts(str, charset) + 1) * sizeof(char *));
	if (!string_arr)
		return (NULL);
	outer_index = 0;
	word_index = 0;
	while (str[outer_index])
	{
		if (!is_separator(str[outer_index], charset))
		{
			string = ft_strdup(str, &outer_index, charset);
			if (!string)
				return (NULL);
			string_arr[word_index++] = string;
		}
		else
			outer_index++;
	}
	string_arr[word_index] = NULL;
	return (string_arr);
}
