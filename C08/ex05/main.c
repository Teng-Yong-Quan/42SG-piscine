/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 16:45:26 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 16:50:57 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"

int	main(int argc, char **argv)
{
	t_stock_str	*output;

	output = ft_strs_to_tab(argc, argv);
	ft_show_tab(output);
	free_arr(argc, output);
	return (0);
}
