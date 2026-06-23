/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:25:17 by yteng             #+#    #+#             */
/*   Updated: 2026/06/09 11:20:00 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_substring(char *tracker, char *substring)
{
	char	*tracker_ptr;
	char	*substr_ptr;

	tracker_ptr = tracker;
	substr_ptr = substring;
	while (*substr_ptr != '\0')
	{
		if (*substr_ptr != *tracker_ptr)
			return (0);
		substr_ptr++;
		tracker_ptr++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	char	*ptr;
	int		length;

	length = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		length++;
		ptr++;
	}
	return (length);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*ptr;
	char	*ptr_to_find;
	int		index;
	int		str_len;
	int		to_find_len;

	index = 0;
	ptr_to_find = to_find;
	ptr = str;
	if (*ptr_to_find == '\0')
		return (ptr);
	str_len = ft_strlen(str);
	to_find_len = ft_strlen(to_find);
	if (str_len < to_find_len)
		return (NULL);
	while (index <= (str_len - to_find_len))
	{
		if (is_substring(ptr, ptr_to_find))
			return (ptr);
		index++;
		ptr++;
	}
	return (NULL);
}
