#include <stdio.h>   // for standard input/output functions (not directly used here)
#include <stdlib.h>  // for malloc, free

// Duplicate a substring from str starting at s_cur up to e_cur (inclusive).
// Returns a newly allocated string with that substring.
char	*str_dup(char *str, int s_cur, int e_cur)
{
	int		cur;
	char	*result;

	// Allocate memory for substring plus null terminator
	result = (char *)malloc(sizeof(char) * (e_cur - s_cur + 2));
	cur = 0;
	
	// Copy characters from s_cur to e_cur into result
	while (s_cur <= e_cur)
	{
		result[cur] = str[s_cur];
		s_cur++;
		cur++;
	}
	
	// Null-terminate the duplicated string
	result[cur] = 0;
	return (result);
}

// Parse a number from str starting at *cur and update *cur to the position after the number.
// The parsed number substring is stored in *number (allocated string).
// Returns 0 on success, 1 on failure (if no valid number found).
int	get_number(int *cur, char *str, char **number)
{
	int	start_cur;

	// Handle optional '+' or '-' sign before digits
	if (str[*cur] == '+' || str[*cur] == '-')
		*cur = *cur + 1;
	// If no sign, first character must be digit; otherwise, return failure
	else if (str[*cur] < '0' || str[*cur] > '9')
		return (1);

	start_cur = *cur;  // mark start position of number substring

	// Move cursor forward while characters are digits
	while (str[*cur] >= '0' && str[*cur] <= '9')
		*cur = *cur + 1;

	// Duplicate the number substring [start_cur, *cur - 1]
	*number = str_dup(str, start_cur, *cur - 1);

	return (0);  // success
}

// Check if the substring starting at cur in str consists only of spaces until the end.
// Returns 1 if only spaces, otherwise 0.
int	is_only_space(int cur, char *str)
{
	while (str[cur] != 0)  // iterate until null terminator
	{
		if (str[cur] != ' ')  // if any non-space char found, return false
			return (0);
		cur++;
	}
	return (1);  // only spaces found
}

// Calculate the length of the value substring starting at cur in str, excluding
// trailing spaces and collapsing multiple spaces into one.
// Returns the size of the value string (number of chars excluding extra spaces).
int	get_value_size(int cur, char *str)
{
	int	value_size;

	value_size = 0;
	while (str[cur] >= 32 && str[cur] <= 126)  // while printable ASCII chars
	{
		if (is_only_space(cur, str) == 1)  // if rest is only spaces, break
			break ;

		// Count non-space characters towards value_size
		if (str[cur] != ' ')
			value_size++;
		// Count space only if previous char is not space or colon (to avoid duplicates)
		else if (str[cur] == ' ' && str[cur - 1] != ' ' && str[cur - 1] != ':')
			value_size++;
		cur++;
	}
	return (value_size);
}
