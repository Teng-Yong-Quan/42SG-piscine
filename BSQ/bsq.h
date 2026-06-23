/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yteng <yteng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:17:03 by yteng             #+#    #+#             */
/*   Updated: 2026/06/15 13:17:03 by yteng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_full_map_info
{
	int		row_num;
	char	empty;
	char	obstacle;
	char	fill;
}	t_map_info;

typedef struct s_full_grid_map
{
	char	*map;
	int		rows;
	int		cols;
}	t_grid_map;

typedef struct s_params
{
	int	row;
	int	col;
	int	prev_col;
}	t_params;

typedef struct s_max_score_params
{
	int	row;
	int	col;
	int	max_score;
}	t_max_score_params;

typedef struct s_string_node
{
	char					*string;
	int						str_len;
	struct s_string_node	*next;
}	t_string_node;

char			*read_file(int file_descriptor, int *len);
char			*extract_string(char *str, int *len);
void			full_process(char *extracted_str, int index, int argc);
void			solve_free_process(char *str);

t_string_node	*join_nodes(t_string_node *prev, char *buffer, int bytes);
char			*get_string(t_string_node *head, int *len);
void			free_nodes(t_string_node *head);
t_string_node	*initialise_head(void);
int				read_and_build(int file_descriptor, t_string_node *prev,
					int *len);

int				symbol_check(char *str, int start, int end);
int				get_row_num(char *str, int end);
int				map_info_checks(char *str, int len);
t_map_info		*generate_map_info(char *str, int len);
t_map_info		*extract_map_info(char *str);

char			*get_grid_map_string(char *str);
int				grid_map_checks(t_map_info *map_info_ptr,
					char *str, t_params *params, int index);
t_grid_map		*extract_map(char *str, t_map_info *map_info_ptr);

int				find_min(int a, int b, int c);
void			draw_square(t_grid_map *grid_map,
					t_max_score_params *params, char fill);
int				get_cell_score(int *scores, int r, int c, int col);
void			check_and_save(int score, int r, int c,
					t_max_score_params *params);

void			free_after_solve(t_grid_map *grid_map, t_map_info *map_info);
void			bsq_solve(t_grid_map *grid_map, t_map_info *map_info,
					int r, int c);

#endif