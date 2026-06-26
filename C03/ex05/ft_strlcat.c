/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 17:38:47 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:41:07 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *arr)
{
	char				*ptr_arr;
	unsigned int		index;

	ptr_arr = arr;
	index = 0;
	while (*ptr_arr != '\0')
	{
		ptr_arr++;
		index++;
	}
	return (index);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	index;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	index = 0;
	while (index < src_len && index < size - dest_len - 1)
	{
		dest[dest_len + index] = src[index];
		index++;
	}
	dest[dest_len + index] = '\0';
	return (src_len + dest_len);
}
