/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:17:30 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 17:25:27 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

//to fill the file_size array with the lenght of each line in the file
// the file_size[0] contains the total number of lines
// other index contains the length of each line
// then return the same file_size pointer

int	*ft_get_lines_len_loop(int file, int *file_sizes)
{
	char	c;
	int		i;
	int		line_idx;
	int		total_lines;

	if (file_sizes == NULL || file_sizes[0] < 0)
		return (NULL);
	total_lines = file_sizes[0];
	c = 0;
	i = 0;
	line_idx = 0;
	while (read(file, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (line_idx < total_lines)
				file_sizes[line_idx + 1] = i;
			i = 0;
			line_idx++;
		}
		else
			i++;
	}
	if (i > 0)
	{
		if (line_idx < total_lines)
		{
			file_sizes[line_idx + 1] = i;
			line_idx++;
		}
	}
	return (file_sizes);
}
//to read one char into the lines array, 
// while handling the newlines and allocation.
// index is an array of two pointers, 
// first one is the pointer to char position in current line 
// and second one is pointer to the current line number
// file_sizes is the lengths of each line (from get_lines_len_loop)
// lines is pointer to array of strings (char **)
// if success return 0 and if fail return -1

int	ft_get_lines_read_c(char c, int *index[2], int *file_sizes, char ***lines)
{
	if (c == '\n')
	{
		if (*index[0] >= 0)
			(*lines)[*index[1]][*index[0]] = 0;
		*index[0] = -1;
	}
	if (*index[0] == 0)
	{
		(*index[1])++;
		(*lines)[*index[1]] = malloc(sizeof(char)
				* (file_sizes[*index[1] + 1] + 1));
		if ((*lines)[*index[1]] == NULL)
			return (-1);
	}
	if (*index[0] >= 0)
		(*lines)[*index[1]][*index[0]] = c;
	(*index[0])++;
	return (0);
}

int	ft_get_lines_loop(int file, int *file_sizes, char ***lines)
{
	char	c;
	int		i;
	int		line_index;
	int		read_res;
	int		*tab[2];

	c = 0;
	i = 0;
	line_index = -1;
	while (read(file, &c, 1))
	{
		tab[0] = &i;
		tab[1] = &line_index;
		read_res = ft_get_lines_read_c(c, tab, file_sizes, lines);
		if (read_res == -1)
			return (-1);
	}
	(*lines)[line_index + 1] = NULL;
	return (0);
}
