/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:59:19 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 17:45:16 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

//to return the number of lines in the file path (pathname)
//otherwise, return -1 if file cannot be opened

int	ft_get_lines_number(const char *pathname)
{
	int		file;
	char	c;
	int		i;
	int		line_idx;

	file = open(pathname, O_RDONLY);
	if (file == -1)
	{
		close (file);
		return (-1);
	}
	c = 0;
	i = 0;
	line_idx = 0;
	while (read(file, &c, 1))
	{
		if (c == '\n')
			i = -1;
		if (i == 0)
			line_idx++;
		i++;
	}
	close(file);
	return (line_idx);
}

//to return int array containing the lengths of each line in the file
//note that the first element (file_size[0] stroes the number of lines)

int	*ft_get_lines_len(const char *pathname)
{
	int	file;
	int	*file_size;
	int	num_lines;

	num_lines = ft_get_lines_number(pathname);
	if (num_lines == -1)
		return (NULL);
	file_size = malloc(sizeof(int) * (num_lines + 1));
	if (file_size == NULL)
		return (NULL);
	file_size[0] = num_lines;
	file = open(pathname, O_RDONLY);
	if (file == -1)
	{
		free(file_size);
		close(file);
		return (NULL);
	}
	if (ft_get_lines_len_loop(file, file_size) == NULL)
	{
		close(file);
		free(file_size);
		return (NULL);
	}
	close(file);
	return (file_size);
}

//to read all lines from the file into a dynamically allocated array of strings

int	ft_get_lines(const char	*pathname, char ***lines)
{
	int			file;
	int			*file_size;
	const char	*dft_path;

	file_size = NULL;
	dft_path = "numbers.dict";
	if (pathname == NULL)
		pathname = dft_path;
	file_size = ft_get_lines_len(pathname);
	if (file_size == NULL)
		return (-1);
	file = open(pathname, O_RDONLY);
	if (file == -1)
	{
		close (file);
		free (file_size);
		return (-1);
	}
	*lines = malloc(sizeof(char *) * (file_size[0] + 1));
	if (*lines == NULL)
	{
		free (file_size);
		close (file);
		return (-1);
	}
	if (ft_get_lines_loop(file, file_size, lines) == -1)
	{
		free(*lines);
		*lines = NULL;
		free(file_size);
		close (file);
		return (-1);
	}
	free(file_size);
	close (file);
	return (0);
}
