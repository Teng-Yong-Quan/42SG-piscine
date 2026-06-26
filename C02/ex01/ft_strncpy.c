/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:04:41 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:39:50 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	counter;
	char			*new_dest;

	counter = 0;
	new_dest = dest;
	while (counter < n && *src != '\0')
	{
		*new_dest = *src;
		new_dest++;
		src++;
		counter++;
	}
	while (counter < n)
	{
		*new_dest = '\0';
		counter++;
		new_dest++;
	}
	return (dest);
}
