/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:52:55 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:40:37 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char *c)
{
	return (' ' <= *c && *c <= '~');
}

char	hex_char(unsigned int num)
{
	if (0 <= num && num <= 9)
	{
		return ('0' + num);
	}
	return ('a' + (num - 10));
}

void	convert_dec_to_hex(char *c)
{
	unsigned char	decimal;
	char			high;
	char			low;

	decimal = (unsigned char)*c;
	low = hex_char(decimal % 16);
	high = hex_char(decimal / 16);
	write(1, "\\", 1);
	write(1, &high, 1);
	write(1, &low, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		if (!is_printable(ptr))
		{
			convert_dec_to_hex(ptr);
		}
		else
		{
			write(1, ptr, 1);
		}
		ptr++;
	}
}
