#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_utils.h"
#include "converter_utils.h"
#include "parse_file.h"
#include "parse_dict.h"

// Forward declaration
int print_num(char *str, int print_o, char *str_num);

// Global variables to store dictionary mappings
char **g_numbers;
char **g_values;
extern int g_is_error;

/**
 * Handles numbers less than or equal to 100.
 * Converts numbers from string form to word form using the dictionary.
 */
int print_num_inf100(char *str, int print_o, char *str_num)
{
	char *str_cop;
	int num;
	int sum;

	num = ft_atoi(str);
	if (num <= 20 || num % 10 == 0)
	{
		if (print_o)
			ft_strcat_space(str_num, ft_get_value(str, g_numbers, g_values));
		return (ft_strlen(ft_get_value(str, g_numbers, g_values)) + 1);
	}
	else if (num <= 100)
	{
		sum = 0;
		str_cop = ft_strdup(str); // Make a copy to modify
		str_cop[1] = '0'; // Convert e.g. 42 -> "40"
		sum += print_num(str_cop, print_o, str_num); // Print tens
		sum += print_num(str + 1, print_o, str_num); // Print ones
		free(str_cop);
		return (sum);
	}
	return (0);
}

/**
 * Handles numbers greater than 100.
 * Splits the number into magnitude (e.g., hundreds, thousands) and recursively prints them.
 */
int print_num_sup100(char *str, int print_o, char *str_num)
{
	int sum;
	char *magnum;
	char *rest;

	sum = 0;
	magnum = ft_get_magnitude_number(str); // Get the leading digits for the magnitude
	sum += print_num(magnum, print_o, str_num); // Print the number part before magnitude
	rest = ft_get_value(ft_get_magnitude(str), g_numbers, g_values); // Get magnitude label (e.g., "hundred")
	if (print_o)
		ft_strcat_space(str_num, rest); // Append magnitude to result
	sum += print_num(str + ft_strlen(magnum), print_o, str_num); // Recursively print the rest
	sum += ft_strlen(rest) + 1;
	return (sum);
}

/**
 * Main number printing function.
 * Decides whether to handle number as <100 or >=100 and processes accordingly.
 */
int print_num(char *str, int print_o, char *str_num)
{
	int len;

	while (str[0] == '0') // Skip leading zeros
		str++;
	if (str[0] == 0)
		return (0);
	len = ft_strlen(str);
	if (len <= 2)
		return (print_num_inf100(str, print_o, str_num));
	else
		return (print_num_sup100(str, print_o, str_num));
	return (0);
}

/**
 * Converts a numeric string into its word representation using a dictionary file.
 * Returns the dynamically allocated result string.
 */
char *get_written_num(char *str, const char *dict_pathname)
{
	char *str_num;
	int str_size;
	int cur;
	char **dict_file_content;

	// Parse dictionary file
	if (ft_get_lines(dict_pathname, &dict_file_content) != 0
		|| parse_dict_string(dict_file_content, &g_numbers, &g_values) != 0)
	{
		g_is_error = 1;
		return (0);
	}

	// Determine output string size
	cur = 0;
	if (only_zero(str) == 0)
		str_size = ft_strlen(ft_get_value("0", g_numbers, g_values));
	else
		str_size = print_num(str, 0, "");

	// Allocate memory for result string
	str_num = malloc(sizeof(char) * (str_size + 1));
	cur = -1;
	while (cur++ < str_size)
		str_num[cur] = 0;

	// Convert number to words and store in result
	if (only_zero(str) == 0)
		ft_strcat_space(str_num, ft_get_value("0", g_numbers, g_values));
	else
		print_num(str, 1, str_num);

	return (str_num);
}
