/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:38:03 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 00:12:04 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	is_error = 0;

// 0 : no error
// 1 : dictionary error
// 2 : argument error

void print_error(void)
{
	if (is_error == 1)
		write (2, "Dict Error\n", 11);
	if (is_error == 2)
		write (2, "Error\n", 6);
}


// Check if the input arguments only contain digits
// return 0 if true
// return -1 if false

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

// Two input arguments: 
// one to determine number to convert
// one for dictionary path name (optional)

// get number value from argv and check valid
// return pointer to number sting if valid 
// return NULL is not valid

char	*get_num(int argc, char **argv, char **dict_path)
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
	is_error = 2;
	return (NULL);
}



// 1. Parses Input Arguments
// 2. Converts number to written format by using dictionary
// 3. Print the written number or ERROR

int	main(int argc, char **argv)
{
	char	*written_form = NULL;
	char	*to_convert_num = NULL;
	char	*dict_path = NULL;
	int	index;

	to_convert_num = get_num(argc, argv, &dict_path);
	if (to_convert_num != NULL)
		written_form = get_written_form(to_convert_num, dict_path);
	if (is_error != 0)
	{
		print_error();
		free(written_form);
		return (-1);
	}
	index = 0; //To Check Again
	while (written_form[index])
	{
		write(1, &written_form[index], 1);
		index;
	}
	free(written_form);
	return (0);
}
