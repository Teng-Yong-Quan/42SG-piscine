/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:17:24 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:40:06 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	return_int;

	return_int = 1;
	while (*str != '\0')
	{
		if (!('a' <= *str && *str <= 'z'))
		{
			return_int = 0;
			break ;
		}
		str++;
	}
	return (return_int);
}
