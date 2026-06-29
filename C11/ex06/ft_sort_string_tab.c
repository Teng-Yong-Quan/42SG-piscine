/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:39:38 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 19:56:39 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	char	*s1_ptr;
	char	*s2_ptr;

	s1_ptr = s1;
	s2_ptr = s2;
	while (*s1_ptr != '\0' && *s2_ptr != '\0')
	{
		if (*s1_ptr != *s2_ptr)
		{
			return (*s1_ptr - *s2_ptr);
		}
		s1_ptr++;
		s2_ptr++;
	}
	return (*s1_ptr - *s2_ptr);
}

int	ft_string_tab_len(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
		index++;
	return (index);
}

void	ft_sort_string_tab(char **tab)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	len = ft_string_tab_len(tab);
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
