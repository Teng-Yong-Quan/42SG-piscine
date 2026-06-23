/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 12:50:08 by yteng             #+#    #+#             */
/*   Updated: 2026/06/04 12:59:04 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanum(char *input)
{
	if (('a' <= *input && *input <= 'z')
		|| ('A' <= *input && *input <= 'Z')
		|| ('0' <= *input && *input <= '9'))
		return (1);
	return (0);
}

void	ft_lowertoupper(char *str)
{
	if ('a' <= *str && *str <= 'z')
		*str = *str + ('A' - 'a');
}

void	ft_uppertolower(char *str)
{
	if ('A' <= *str && *str <= 'Z')
		*str = *str + ('a' - 'A');
}

char	*ft_strcapitalize(char *str)
{
	char	*ptr;
	int		cap;

	cap = 1;
	ptr = str;
	while (*ptr != '\0')
	{
		if (is_alphanum(ptr))
		{
			if (cap)
			{
				ft_lowertoupper(ptr);
				cap = 0;
			}
			else
				ft_uppertolower(ptr);
		}
		else
			cap = 1;
		ptr++;
	}
	return (str);
}
