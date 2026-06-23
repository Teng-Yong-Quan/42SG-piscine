/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:52:18 by yteng             #+#    #+#             */
/*   Updated: 2026/06/02 12:31:21 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	curr_index;

	if (n == 0)
		return (0);
	curr_index = 1;
	while (*s1 != '\0' && *s2 != '\0' && curr_index < n)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		curr_index++;
	}
	return (*s1 - *s2);
}
