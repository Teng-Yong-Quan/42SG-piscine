/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:14:38 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:40:54 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*new_dest;

	new_dest = dest;
	while (*new_dest != '\0')
	{
		new_dest++;
	}
	while (*src != '\0')
	{
		*new_dest = *src;
		new_dest++;
		src++;
	}
	*new_dest = '\0';
	return (dest);
}
