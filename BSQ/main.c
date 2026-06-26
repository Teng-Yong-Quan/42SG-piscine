/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:16:32 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 14:32:33 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(int file_descriptor, int *len)
{
	int				bytes;
	char			*str;
	t_string_node	*head;
	t_string_node	*prev;

	head = initialise_head();
	if (!head)
		return (NULL);
	prev = head;
	bytes = read_and_build(file_descriptor, prev, len);
	if (bytes < 0)
	{
		free_nodes(head);
		return (NULL);
	}
	str = get_string(head->next, len);
	free_nodes(head);
	return (str);
}

char	*extract_string(char *str, int *len)
{
	int		file_descriptor;
	char	*extracted_str;

	file_descriptor = open(str, O_RDONLY);
	if (file_descriptor == -1)
		return (NULL);
	*len = 0;
	extracted_str = read_file(file_descriptor, len);
	close(file_descriptor);
	return (extracted_str);
}

void	solve_free_process(char *str)
{
	t_map_info	*info_ptr;
	t_grid_map	*map_ptr;

	if (!str)
		write(2, "map error\n", 10);
	else
	{
		info_ptr = extract_map_info(str);
		if (!info_ptr)
			write(2, "map error\n", 10);
		else
		{
			map_ptr = extract_map(str, info_ptr);
			if (!map_ptr)
			{
				free(info_ptr);
				write(2, "map error\n", 10);
			}
			else
			{
				bsq_solve(map_ptr, info_ptr, 0, 0);
				free_after_solve(map_ptr, info_ptr);
			}
		}
	}
}

void	full_process(char *extracted_str, int index, int argc)
{
	if (!extracted_str)
	{
		write(2, "map error\n", 10);
		if (argc == 1)
			exit(EXIT_FAILURE);
		return ;
	}
	solve_free_process(extracted_str);
	if (index < argc - 1)
		write(1, "\n", 1);
	free(extracted_str);
}

int	main(int argc, char **argv)
{
	char	*extracted_str;
	int		*len;
	int		str_len;
	int		index;

	str_len = 0;
	len = &str_len;
	index = 1;
	if (argc > 1)
	{
		while (index < argc)
		{
			extracted_str = extract_string(argv[index], len);
			full_process(extracted_str, index, argc);
			index++;
		}
	}
	else
	{
		extracted_str = read_file(0, len);
		full_process(extracted_str, index, argc);
	}
	exit(EXIT_SUCCESS);
}
