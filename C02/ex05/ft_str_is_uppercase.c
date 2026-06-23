/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:17:24 by yteng             #+#    #+#             */
/*   Updated: 2026/05/30 17:35:55 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	return_int;

	return_int = 1;
	while (*str != '\0')
	{
		if (!('A' <= *str && *str <= 'Z'))
		{
			return_int = 0;
			break ;
		}
		str++;
	}
	return (return_int);
}
