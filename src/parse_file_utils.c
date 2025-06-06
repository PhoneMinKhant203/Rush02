#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// Fills file_sizes array with the length of each line in the file.
// file_sizes[0] contains the total number of lines,
// file_sizes[1..] contain the length of each line.
// Returns the same file_sizes pointer.
int	*ft_get_line_lens_loop(int file, int *file_sizes)
{
	char	c;           // buffer to read each character
	int		i;           // current line length counter
	int		line_index;  // index of current line (0-based)

	c = 0;
	i = 0;
	line_index = -1;   // start before the first line

	// Read file byte by byte
	while (read(file, &c, 1))
	{
		if (c == '\n')  // on newline, store the length of the line
		{
			if (i >= 0 && line_index >= 0)
				file_sizes[line_index + 1] = i;  // store length for current line
			i = -1;  // reset counter (will become 0 after i++)
		}

		// On first character of a line (i == 0), increment line_index
		if (i == 0)
			line_index++;

		i++;
	}
	return (file_sizes);
}

// Reads one character c into the lines array, handling newlines and allocation.
// index is an array of two pointers: index[0] points to char position in current line,
// index[1] points to current line number.
// file_sizes holds lengths of each line (from ft_get_line_lens_loop).
// lines is pointer to array of strings (char**).
// Returns 0 on success, -1 on malloc failure.
int	ft_get_lines_read_c(char c, int *index[2], int *file_sizes, char ***lines)
{
	// If character is newline, terminate the current string and reset char index
	if (c == '\n')
	{
		if (*index[0] >= 0)
			(*lines)[*index[1]][*index[0]] = 0;  // null terminate string
		*index[0] = -1;  // reset char index to signal next line start
	}

	// If starting a new line (char index == 0)
	if (*index[0] == 0)
	{
		(*index[1])++;   // move to next line index
		// Allocate memory for the line string, length from file_sizes + 1 for null terminator
		(*lines)[*index[1]] = malloc(sizeof(char)
				* (file_sizes[*index[1] + 1] + 1));
		if ((*lines)[*index[1]] == NULL)
			return (-1);  // malloc failure
	}

	// If currently writing chars in the line (char index >= 0), store char c
	if (*index[0] >= 0)
		(*lines)[*index[1]][*index[0]] = c;

	(*index[0])++;  // increment char index for next char
	return (0);
}

// Reads lines from the file into the lines array using helper ft_get_lines_read_c.
// Uses file_sizes to allocate correct length for each line.
// Returns 0 on success, -1 on malloc failure.
int	ft_get_lines_loop(int file, int *file_sizes, char ***lines)
{
	char	c;           // buffer to read each char
	int		i;           // char index within current line
	int		line_index;  // current line number
	int		read_res;    // return value from ft_get_lines_read_c
	int		*tab[2];     // array of pointers to i and line_index (for passing by reference)

	c = 0;
	i = 0;
	line_index = -1;

	// Read file char by char
	while (read(file, &c, 1))
	{
		tab[0] = &i;          // pointer to char index
		tab[1] = &line_index; // pointer to line index
		read_res = ft_get_lines_read_c(c, tab, file_sizes, lines);
		if (read_res == -1)   // malloc failure inside helper
			return (-1);
	}

	// Null terminate the array of strings (lines)
	(*lines)[line_index + 1] = NULL;
	return (0);
}
