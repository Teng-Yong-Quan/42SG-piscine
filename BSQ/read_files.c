/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cherlim <cherlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:17:14 by yteng             #+#    #+#             */
/*   Updated: 2026/06/15 14:30:52 by cherlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

t_string_node	*join_nodes(t_string_node *prev, char *buffer, int bytes)
{
	t_string_node	*new;
	int				i;

	new = malloc(sizeof(t_string_node));
	if (!new)
		return (NULL);
	new->string = malloc(bytes);
	if (!new->string)
	{
		free(new);
		return (NULL);
	}
	i = 0;
	while (i < bytes)
	{
		new->string[i] = buffer[i];
		i++;
	}
	new->str_len = bytes;
	new->next = NULL;
	prev->next = new;
	return (new);
}

char	*get_string(t_string_node *head, int *len)
{
	char			*str;
	t_string_node	*cur;
	int				i;
	int				j;

	str = malloc(*len + 1);
	if (!str)
		return (NULL);
	cur = head;
	i = 0;
	while (cur)
	{
		j = 0;
		while (j < cur->str_len)
			str[i++] = cur->string[j++];
		cur = cur->next;
	}
	str[i] = 0;
	return (str);
}

void	free_nodes(t_string_node *head)
{
	t_string_node	*curr;
	t_string_node	*next;

	curr = head;
	while (curr)
	{
		next = curr->next;
		free(curr->string);
		free(curr);
		curr = next;
	}
}

t_string_node	*initialise_head(void)
{
	t_string_node	*head;

	head = malloc(sizeof(t_string_node));
	if (!head)
		return (NULL);
	head->string = NULL;
	head->str_len = 0;
	head->next = NULL;
	return (head);
}

int	read_and_build(int file_descriptor, t_string_node *prev, int *len)
{
	int		bytes;
	char	buffer[4096];

	bytes = read(file_descriptor, buffer, 4096);
	while (bytes > 0)
	{
		prev = join_nodes(prev, buffer, bytes);
		if (!prev)
			return (-1);
		*len += bytes;
		bytes = read(file_descriptor, buffer, 4096);
	}
	return (bytes);
}
