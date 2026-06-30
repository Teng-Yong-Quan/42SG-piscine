/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:39:22 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 14:19:34 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_strlen(char *str)
{
	char	*ptr;
	int		counter;

	counter = 0;
	ptr = str;
	while (*ptr != '\0')
	{
		counter++;
		ptr++;
	}
	return (counter);
}

int	ft_max_strlen(char **str)
{
	int	max;
	int	curr_len;

	max = 0;
	curr_len = 0;
	while (*str)
	{
		curr_len = ft_strlen(*str);
		if (curr_len > max)
			max = curr_len;
		str++;
	}
	return (max);
}

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

t_list	*sort_list(t_list *lst, int (*cmp)(char*, char*))
{
	t_list	*first;
	t_list	*second;

	first = lst;
	second = NULL;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (cmp(first->data, second->data) > 0)
				swap(&(first->data), &(second->data));
			second = second->next;
		}
		first = first->next;
	}
	return (lst);
}
