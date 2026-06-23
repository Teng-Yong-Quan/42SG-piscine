/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:40:22 by yteng             #+#    #+#             */
/*   Updated: 2026/06/11 17:50:35 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	index;

	if (argc > 1)
	{
		index = 1;
		while (index <= argc - 1)
		{
			while (*argv[index] != '\0')
			{
				write(1, argv[index], 1);
				argv[index]++;
			}
			write(1, "\n", 1);
			index++;
		}
	}
	return (0);
}
