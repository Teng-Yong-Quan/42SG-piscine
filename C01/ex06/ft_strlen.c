/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:45:54 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 15:12:43 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != '\0')
	{
		counter++;
	}
	return (counter);
}
/*
int	main(void)
{
	char	*example;

	example = "Hello World";
	printf("Word count: %d", ft_strlen(example));
	return (0);
}*/
