/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 16:52:58 by yteng             #+#    #+#             */
/*   Updated: 2026/06/29 17:11:37 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H 
# define DO_OP_H
# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putchar(char c);
long	ft_convert_to_pos(long num);
void	ft_printdash(long num);
void	ft_putnbr(long nb);
void	ft_operation(int a, int b, char c);
#endif