#include <stdlib.h>
#include "ft_utils.h"

extern int g_is_error;

/**
 * Returns the corresponding value string for a given key from the dictionary arrays.
 * If the key is not found, sets error flag and returns an empty string.
 */
char *ft_get_value(char *key, char **numbers, char **values)
{
	int i;
	char *empty_str;

	i = 0;
	while (numbers[i])
	{
		if (ft_strcmp(numbers[i], key) == 0)
			return (values[i]);
		i++;
	}
	// Key not found, set error flag and return empty string
	g_is_error = 1;
	empty_str = (char *)malloc(1 * sizeof(char));
	empty_str[0] = 0;
	return (empty_str);
}

/**
 * Calculates the magnitude string for a given number string.
 * Example: For "12345", returns "10000" (the highest power of 10 less or equal).
 */
char *ft_get_magnitude(char *str)
{
	int n;
	int len;
	char *magnitude;

	len = ft_strlen(str);
	n = len;
	if (len >= 4)
	{
		// Reduce n until it aligns with magnitude boundary (thousands, millions, etc.)
		while ((n - 1) % 3 != 0)
			n--;
	}
	magnitude = malloc(n + 1);
	magnitude[0] = '1';
	magnitude[n] = '\0';
	while (--n > 0)
		magnitude[n] = '0';  // Fill with zeros
	return (magnitude);
}

/**
 * Extracts the leading number part related to magnitude from the string.
 * For example, "12345" -> "12" (for thousands magnitude)
 * Returns the substring representing the magnitude number.
 */
char *ft_get_magnitude_number(char *str)
{
	int n;
	int i;
	int len;
	char *number;

	len = ft_strlen(str);
	if (len >= 4)
	{
		// Calculate how many digits form the first magnitude chunk (1-3 digits)
		n = (len - 1) % 3 + 1;
		number = malloc(n + 1);
		i = 0;
		while (i < n)
		{
			number[i] = str[i];
			i++;
		}
	}
	if (len <= 3)
	{
		// For numbers <= 3 digits, just take the first digit
		n = 1;
		number = malloc(n + 1);
		number[0] = str[0];
	}
	number[n] = '\0';
	return (number);
}

/**
 * Checks if the given numeric string contains only zeros.
 * Returns 0 if all zeros, 1 otherwise.
 */
int only_zero(char *str)
{
	int cur;

	cur = 0;
	while (str[cur] != 0)
	{
		if (str[cur] != '0')
			return (1); // Not all zeros
		cur++;
	}
	return (0); // All zeros
}
