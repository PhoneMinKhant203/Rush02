#include <stdlib.h>

/**
 * Returns the length of a null-terminated string.
 */
int ft_strlen(char *str)
{
	int cur = 0;
	while (str[cur] != 0)
		cur++;
	return (cur);
}

/**
 * Concatenates src string to dest string with a leading space.
 * Assumes dest has enough space.
 */
void ft_strcat_space(char *dest, char *src)
{
	int cur = 0;
	int destcur = ft_strlen(dest);
	dest[destcur] = ' ';  // add space before concatenation
	destcur++;
	while (src[cur] != 0)
	{
		dest[destcur] = src[cur];
		cur++;
		destcur++;
	}
	dest[destcur] = 0;  // null terminate
}

/**
 * Duplicates a string by allocating memory and copying contents.
 * Returns pointer to new string.
 */
char *ft_strdup(char *src)
{
	char *dup = (char *)malloc(ft_strlen(src) + 1);
	int cur = 0;
	while (src[cur] != 0)
	{
		dup[cur] = src[cur];
		cur++;
	}
	dup[cur] = 0;
	return (dup);
}

/**
 * Compares two strings lexicographically.
 * Returns 0 if equal, positive or negative difference otherwise.
 */
int ft_strcmp(char *s1, char *s2)
{
	int cur = 0;
	while (s1[cur] != 0 && s2[cur] != 0)
	{
		if (s1[cur] != s2[cur])
			return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
		cur++;
	}
	return ((unsigned char)s1[cur] - (unsigned char)s2[cur]);
}

/**
 * Converts a string to an integer.
 * Handles optional whitespace and + / - signs.
 */
int ft_atoi(char *str)
{
	int nb = 0;
	int cur = 0;
	int is_negative = 1;

	// Skip whitespace characters
	while ((str[cur] >= 9 && str[cur] <= 13) || str[cur] == ' ')
		cur++;

	// Handle sign
	while (str[cur] == '+' || str[cur] == '-')
	{
		if (str[cur] == '-')
			is_negative *= -1;
		cur++;
	}

	// Convert digits to number
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		nb = nb * 10 + str[cur] - '0';
		cur++;
	}

	return (nb * is_negative);
}
