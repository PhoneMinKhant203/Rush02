/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_parse_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:24:42 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 20:28:39 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//fixed version from the norme error
//intentionally solved the norminette

#include "app.h"

int	ft_get_lines_number(const char *pathname);

int	*norme_ft_get_lines_len(int *f, int *fi, int *nl, const char *pathname)
{
	int		file;
	int		num_lines;

	num_lines = *nl;
	num_lines = ft_get_lines_number(pathname);
	if (num_lines == -1)
		return (NULL);
	fi = malloc(sizeof(int) * (num_lines + 1));
	if (fi == NULL)
		return (NULL);
	fi[0] = num_lines;
	file = open(pathname, O_RDONLY);
	if (ft_get_lines_len_loop(file, fi) == NULL)
	{
		close(file);
		free(fi);
		return (NULL);
	}
	*f = file;
	close(file);
	return (fi);
}

int	norme_ft_get_lines(char ***lines, int *f, int **fs)
{
	int	file;
	int	*file_size;

	file = *f;
	file_size = *fs;
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
	return (0);
}
