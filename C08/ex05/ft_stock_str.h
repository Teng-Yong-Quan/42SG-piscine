/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 15:57:17 by yteng             #+#    #+#             */
/*   Updated: 2026/06/26 16:45:12 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;

int					ft_strlen(char *str);
char				*ft_strdup(char *src);
struct s_stock_str	*free_arr(int index, struct s_stock_str *arr);
struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
void				ft_putchar(char c);
long				ft_convert_to_pos(int num);
void				ft_putnbr(int nb);
void				ft_show_tab(struct s_stock_str *par);