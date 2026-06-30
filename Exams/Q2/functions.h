/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:00:11 by yteng             #+#    #+#             */
/*   Updated: 2026/06/30 14:19:25 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

int		is_separator(char c, char *charset);
int		word_counts(char *str, char *charset);
char	*ft_strdup(char *str, int *outer_index, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_strlen(char *str);
int		ft_max_strlen(char **str);
void	swap(char **a, char **b);
int		ft_strcmp(char *s1, char *s2);
t_list	*sort_list(t_list *lst, int (*cmp)(char*, char*));
void	free_char_arr(char **arr);
void	free_nodes(t_list *start);
void	ft_putstr(char *str);
t_list	*join_nodes(t_list *curr, char *string);
t_list	*loop_arr(char **arr, int word_len);
void	full_process(char **arr, int len);

#endif