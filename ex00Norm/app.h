/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 07:26:57 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 15:21:10 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef APP_H
# define APP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_app_data
{
	char	**nb;
	char	**val;
	int		is_error;
}	t_app_data;

extern t_app_data	g_app_data;

void	free_dictionary_data(t_app_data *data);
char	*ft_get_value(char *key, char **numbers, char **values,
			t_app_data *data);
char	*ft_get_mag(char *str);
char	*ft_get_mag_nb(char *str);
int		only_zero(char *str);

char	*ft_get_written_form(char *str, const char *dict_path,
			t_app_data *data);

int		ft_strlen(char *str);
void	space_strcat(char *dest, char *src);
char	*ft_strdup(char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_get_number(int *idx, char *str, char **number);
int		ft_get_val_size(int idx, char *str);
int		only_space(int idx, char *str);
int		ft_parse_dstring(char **strs, char ***nums, char ***values,
			t_app_data *data);
int		*ft_get_lines_len_loop(int file, int *file_sizes);
int		ft_get_lines_loop(int file, int *file_sizes, char ***lines);
int		ft_get_lines(const char *pathname, char ***lines);

int		print_nb(char *str, int print_o, char *str_nb, t_app_data *data);
int		print_nbr_inf100(char *str, int print_o, char *str_nb,
			t_app_data *data);
int		print_nbr_sup100(char *str, int print_o, char *str_nb,
			t_app_data *data);
int		load_and_parse_dict(const char *dict_path, char ***dfile_content_ptr,
			t_app_data *data);
void	print_error(void);
void	init_char_array(char *arr, int size);
char	*ft_strcpy(char *dest, const char *src);
int		parse_line_start(int *index, char *str, char **number);
void	free_parsed_arrays(char **nums, char **values, int current_index);
int		parse_line_str(char *str, char **number, char **values);

#endif
