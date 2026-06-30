/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_multi.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 20:10:41 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 20:12:59 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INF_MULTI_H
# define INF_MULTI_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_intlen(int *int_arr, int len);
int		*multiply(char c1, char c2, int *int_arr, int index);
int		*multiply_loop(char *s1, char *s2, int *int_arr);
int		*normalize(int *arr, int len);
char	*ft_copy(int *int_arr, int arr_len, char *s1, char *s2);
char	*infinite_multiplication(char *s1, char *s2);

#endif