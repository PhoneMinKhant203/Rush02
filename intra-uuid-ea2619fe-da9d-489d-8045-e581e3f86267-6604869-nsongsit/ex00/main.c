/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:38:03 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 23:53:13 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_converter.h"
#include "ft_helper.h"

int	g_is_error = 0;

// 0 : no error
// 1 : dictionary error
// 2 : argument error

void	print_error(void)
{
	if (g_is_error == 1)
		write (2, "Dict Error\n", 11);
	if (g_is_error == 2)
		write (2, "Error\n", 6);
}

int	check_arg(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

// get number value from argv and check valid
// return pointer to number sting if valid 
// return NULL is not valid

char	*ft_get_num_cvt(int argc, char **argv, char **dict_path)
{
	if (argc == 2)
	{
		*dict_path = NULL;
		if (check_arg(argv[1]) == 0)
			return (argv[1]);
	}
	if (argc == 3)
	{
		*dict_path = argv[1];
		if (check_arg(argv[2]) == 0)
			return (argv[2]);
	}
	g_is_error = 2;
	return (NULL);
}

void	cleanup_written_form(char *form)
{
	if (form != NULL)
	{
		free (form);
	}
}

int	main(int argc, char **argv)
{
	char	*written_form;
	char	*to_convert_num;
	char	*dict_path;
	int		index;

	written_form = NULL;
	to_convert_num = NULL;
	dict_path = NULL;
	to_convert_num = ft_get_num_cvt(argc, argv, &dict_path);
	if (to_convert_num != NULL)
		written_form = ft_get_written_form(to_convert_num, dict_path);
	if (g_is_error != 0)
	{
		print_error();
		cleanup_written_form (written_form);
		return (-1);
	}
	index = 1;
	while (written_form[index])
	{
		write(1, &written_form[index], 1);
		index++;
	}
	cleanup_written_form (written_form);
	return (0);
}
