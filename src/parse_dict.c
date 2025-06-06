#include <stdlib.h>   // for malloc, free
#include <stdio.h>    // (not used here, but probably for debugging)
#include <unistd.h>   // for write (if used elsewhere)
#include "parse_dict_utils.h"  // your custom header with helper function declarations

extern int	g_is_error;  // global error flag, declared elsewhere

// Parse the start of a line to extract the number part and move the cursor past ':' and spaces.
// Returns 0 if successful, 1 on failure.
int	parse_line_start(int *cur, char *str, char **number)
{
	*cur = 0;  // initialize cursor at start of line
	if (get_number(cur, str, number) != 0)  // parse number from str, update cur to end of number
		return (1);  // failure if number not valid
	while (str[*cur] == ' ')  // skip spaces after number
		*cur = *cur + 1;
	if (str[*cur] != ':')  // expect colon next
		return (1);  // failure if colon missing
	*cur = *cur + 1;  // move past colon
	while (str[*cur] == ' ')  // skip spaces after colon
		*cur = *cur + 1;
	return (0);  // success
}

// Parse a dictionary line to separate the number and the associated value string.
// Allocates memory for value, which must be freed later.
// Returns 0 on success, 1 on failure.
int	parse_line_string(char *str, char **number, char **value)
{
	int	cur;        // cursor index to traverse str
	int	value_cur;  // index to fill value buffer

	if (parse_line_start(&cur, str, number) != 0)  // parse number and position cur after colon
		return (1);  // failure if line format is wrong

	// Allocate memory for value string, length based on get_value_size helper + 2 (extra padding)
	*value = (char *)malloc(sizeof(char) * (get_value_size(cur, str) + 2));
	
	value_cur = 0;  // initialize index for value string buffer

	// Loop through characters in str while printable ASCII characters present
	while (str[cur] >= 32 && str[cur] <= 126)
	{
		if (is_only_space(cur, str) == 1)  // check if the remaining substring is only spaces
			break ;  // break if only spaces left, end of value reached

		// Copy characters except duplicate spaces (only one space allowed consecutively)
		if (str[cur] != ' ' || (str[cur] == ' ' && str[cur - 1] != ' '))
		{
			(*value)[value_cur] = str[cur];  // copy current char to value buffer
			value_cur++;  // advance value index
		}
		cur++;  // advance cursor in original string
	}

	(*value)[value_cur] = 0;  // null-terminate value string
	return (0);  // success
}

// Parse an array of dictionary lines into two arrays: numbers and values.
// Allocates memory for nums and vals arrays, each of size count+1 for null-termination.
// Returns 0 on success, 1 on failure (also sets global error flag).
int	parse_dict_string(char **strs, char ***nums, char ***vals)
{
	int	cur;  // index to iterate through strs

	cur = 0;
	while (strs[cur] != 0)  // count how many lines in strs (null-terminated array)
		cur++;

	// Allocate array of string pointers for numbers and values (+1 for null terminator)
	*nums = (char **)malloc(sizeof(char *) * (cur + 1));
	*vals = (char **)malloc(sizeof(char *) * (cur + 1));

	cur = 0;  // reset index for parsing lines

	while (strs[cur] != 0)  // iterate over each line string
	{
		// Parse each line into number and value strings, store in allocated arrays
		if (parse_line_string(strs[cur], &(*nums)[cur], &(*vals)[cur]) != 0)
		{
			g_is_error = 1;  // set global error flag on failure
			return (1);  // return failure
		}
		cur++;
	}

	(*nums)[cur] = 0;  // null-terminate nums array
	(*vals)[cur] = 0;  // null-terminate vals array

	return (0);  // success
}
