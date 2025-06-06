#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "converter.h"
#include "ft_utils.h"

// Global error flag: 0 = no error, 1 = dictionary error, 2 = argument error
int g_is_error = 0;

/**
 * Prints error message based on the global error flag.
 */
void ft_print_error(void)
{
	if (g_is_error == 1)
		write(2, "Dict Error\n", 11);
	if (g_is_error == 2)
		write(2, "Error\n", 6);
}

/**
 * Validates that the argument string contains only digits.
 * Returns 0 if valid, -1 otherwise.
 */
int check_arg(char *arg)
{
	int i = 0;

	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

/**
 * Parses command line arguments to determine the number to convert
 * and optional dictionary pathname.
 * 
 * argc: argument count
 * argv: argument vector
 * dict_pathname: pointer to store dictionary path (can be NULL)
 * 
 * Returns pointer to number string if valid, NULL otherwise.
 */
char *get_num_to_convert(int argc, char **argv, char **dict_pathname)
{
	if (argc == 2)
	{
		*dict_pathname = NULL;
		if (check_arg(argv[1]) == 0)
			return (argv[1]);
	}
	if (argc == 3)
	{
		*dict_pathname = argv[1];
		if (check_arg(argv[2]) == 0)
			return (argv[2]);
	}
	g_is_error = 2;  // Invalid arguments
	return (NULL);
}

/**
 * Main function:
 * - Parses input arguments
 * - Converts number to written form using dictionary
 * - Prints the written number or error
 */
int main(int argc, char **argv)
{
	char *written_num = NULL;
	char *num_to_convert = NULL;
	char *dict_pathname = NULL;
	int cur;

	num_to_convert = get_num_to_convert(argc, argv, &dict_pathname);

	if (num_to_convert != NULL)
		written_num = get_written_num(num_to_convert, dict_pathname);

	if (g_is_error != 0)
	{
		ft_print_error();
		free(written_num);
		return (-1);
	}

	// Start from 1 to skip the leading space added by print_num
	cur = 1;
	while (written_num[cur])
	{
		write(1, &written_num[cur], 1);
		cur++;
	}

	free(written_num);
	return (0);
}
