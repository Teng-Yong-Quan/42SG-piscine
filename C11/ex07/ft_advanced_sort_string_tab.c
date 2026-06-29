/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 19:39:38 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 20:40:55 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_string_tab_len(char **tab)
{
	int	index;

	index = 0;
	while (tab[index])
		index++;
	return (index);
}

void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[i], tab[j]) > 0)
				swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
