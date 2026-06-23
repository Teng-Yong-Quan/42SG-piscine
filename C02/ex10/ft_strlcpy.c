/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:55:26 by yteng             #+#    #+#             */
/*   Updated: 2026/06/02 18:16:33 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_count;
	unsigned int	index;

	src_count = 0;
	index = 0;
	while (*src != '\0')
	{
		src_count++;
		src++;
	}
	src = src - src_count;
	if (size > 0)
	{
		while (*src != '\0' && index < size - 1)
		{
			*dest = *src;
			dest++;
			src++;
			index++;
		}
		*dest = '\0';
	}
	return (src_count);
}
