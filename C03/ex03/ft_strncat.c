/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 16:18:41 by yteng             #+#    #+#             */
/*   Updated: 2026/06/03 16:24:10 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	counter;
	char			*new_dest;

	new_dest = dest;
	counter = 0;
	while (*new_dest != '\0')
	{
		new_dest++;
	}
	while (*src != '\0' && counter < nb)
	{
		*new_dest = *src;
		new_dest++;
		src++;
		counter++;
	}
	*new_dest = '\0';
	return (dest);
}
