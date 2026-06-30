/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:00:14 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 14:23:03 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	free_char_arr(char **arr)
{
	char	**str_arr;

	str_arr = arr;
	while (*str_arr)
		free(*(str_arr++));
	free(arr);
}

void	free_nodes(t_list *start)
{
	t_list	*temp;
	t_list	*next;

	temp = start;
	next = NULL;
	while (temp->next)
	{
		next = temp->next;
		free(temp->data);
		free(temp);
		temp = next;
	}
	if (temp)
	{
		free(temp->data);
		free(temp);
	}
}

void	ft_putstr(char *str)
{
	char	*ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr++;
	}
}

t_list	*join_nodes(t_list *curr, char *string)
{
	t_list	*new;
	char	*dup;
	int		index;
	int		end;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = NULL;
	new->next = NULL;
	end = ft_strlen(string);
	dup = malloc(end + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < end)
	{
		dup[index] = string[index];
		index++;
	}
	dup[index] = '\0';
	new->data = dup;
	if (curr)
		curr->next = new;
	return (new);
}

t_list	*loop_arr(char **arr, int word_len)
{
	t_list	*temp;
	t_list	*start;

	temp = NULL;
	start = NULL;
	while (*arr)
	{
		if (ft_strlen(*arr) == word_len)
		{
			temp = join_nodes(temp, *arr);
			if (!start)
				start = temp;
			if (!temp)
			{
				free_nodes(start);
				return (NULL);
			}
		}
		arr++;
	}
	return (start);
}
