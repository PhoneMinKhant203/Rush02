/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:38:03 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 17:41:59 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

t_app_data	g_app_data = {
	.nb = NULL,
	.val = NULL,
	.is_error = 0
};

// 0 : no error
// 1 : dictionary error
// 2 : argument error

void	print_error(void)
{
	if (g_app_data.is_error == 1)
		write (2, "Dict Error\n", 11);
	if (g_app_data.is_error == 2)
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
	g_app_data.is_error = 2;
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

	written_form = NULL;
	to_convert_num = NULL;
	dict_path = NULL;

	to_convert_num = ft_get_num_cvt(argc, argv, &dict_path);
	if (to_convert_num != NULL)
		written_form = ft_get_written_form(to_convert_num, dict_path,
				&g_app_data);
	if (g_app_data.is_error != 0)
	{
		print_error();
		cleanup_written_form(written_form);
		free_dictionary_data(&g_app_data);
		return (1);
	}
	if (written_form != NULL)
	{
		write(1, written_form, ft_strlen(written_form));
		write(1, "\n", 1);
	}
	cleanup_written_form(written_form);
	free_dictionary_data(&g_app_data);
	return (0);
}
/*int x = open(hello.txt, RDONLY)

0 = input
1 = stdoutput
2 = stderror
===
x = 3
close(x) //I am going to remove this file away
and this file, is 3;
*/