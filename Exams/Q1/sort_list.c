/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:39:22 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 19:55:05 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_list.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*first;
	t_list	*second;

	first = lst;
	while (first)
	{
		second = first->next;
		while (second)
		{
			if (!cmp(first->data, second->data))
				swap(&(first->data), &(second->data));
			second = second->next;
		}
		first = first->next;
	}
	return (lst);
}
