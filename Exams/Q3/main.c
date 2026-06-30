/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:19:45 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 20:13:28 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inf_multi.h"

int	main(int argc, char **argv)
{
	char	*output;
	char	*tmp;

	output = NULL;
	tmp = NULL;
	if (argc == 3)
	{
		output = infinite_multiplication(argv[1], argv[2]);
		if (output)
		{
			tmp = output;
			while (*output != '\0')
				write(1, output++, 1);
			free(tmp);
		}
	}
	write(1, "\n", 1);
	return (0);
}