/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:34:25 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 19:55:42 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	full_process(char **arr, int len)
{
	t_list	*head;
	t_list	*curr;
	char	**ptr;

	ptr = arr;
	head = NULL;
	curr = NULL;
	head = loop_arr(ptr, len);
	if (!head)
		return ;
	head = sort_list(head, ft_strcmp);
	curr = head;
	while (curr)
	{
		ft_putstr(curr->data);
		if (curr->next)
			write(1, ", ", 2);
		curr = curr->next;
	}
	write(1, "\n", 1);
	free_nodes(head);
}

int	main(int argc, char **argv)
{
	char	**str_arr;
	int		max_len;
	int		curr_len;

	str_arr = NULL;
	max_len = 0;
	curr_len = 1;
	if (argc == 2)
	{
		str_arr = ft_split(argv[1], " \t\n");
		max_len = ft_max_strlen(str_arr);
		curr_len = 1;
		while (curr_len <= max_len)
			full_process(str_arr, curr_len++);
		free_char_arr(str_arr);
	}
	else
		write(1, "\n", 1);
}
