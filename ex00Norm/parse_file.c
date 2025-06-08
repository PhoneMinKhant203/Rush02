/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:59:19 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 20:38:58 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

//to return the number of lines in the file path (pathname)
//otherwise, return -1 if file cannot be opened

int	*norme_ft_get_lines_len(int *f, int *fi, int *nl, const char *path);
int	norme_ft_get_lines(char ***lines, int *f, int **fs);

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
	int	*file;
	int	x;
	int	*file_size;
	int	num_lines;

	x = 0;
	file = &x;
	file_size = NULL;
	file_size = norme_ft_get_lines_len(file, file_size, &num_lines, pathname);
	if (file_size == NULL)
		return (NULL);
	if (file == NULL)
	{
		free(file_size);
		close(*file);
		return (NULL);
	}
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
	norme_ft_get_lines(lines, &file, &file_size);
	free(file_size);
	close (file);
	return (0);
}
