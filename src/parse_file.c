#include <unistd.h>   // for read, close
#include <fcntl.h>    // for open
#include <stdio.h>    // for perror (not used here but typical)
#include <stdlib.h>   // for malloc, free
#include "parse_file_utils.h"

// Returns the number of lines in the file at pathname,
// or -1 if file can't be opened.
int	ft_get_line_number(const char *pathname)
{
	int		file;        // file descriptor
	char	c;           // character buffer to read one byte at a time
	int		i;           // counter to track chars since last newline
	int		line_index;  // count of lines

	file = open(pathname, O_RDONLY);
	if (file == -1)      // fail if file can't be opened
		return (-1);

	c = 0;
	i = 0;
	line_index = 0;

	// Read file byte by byte
	while (read(file, &c, 1))
	{
		if (c == '\n')  // on newline, reset i to -1 (will become 0 after i++)
			i = -1;

		// Increment line_index only once per line when i == 0
		if (i == 0)
			line_index++;

		i++;
	}
	close(file);
	return (line_index);
}

// Returns an int array containing lengths of each line in the file.
// The first element file_sizes[0] stores the number of lines.
// Returns NULL on failure.
int	*ft_get_line_lens(const char *pathname)
{
	int		file;          // file descriptor
	int		*file_sizes;   // array: first element = num lines, then lengths per line

	// Allocate array to hold line count + line lengths
	file_sizes = malloc(sizeof(int) * (1 + ft_get_line_number(pathname)));
	if (file_sizes == NULL)
		return (NULL);

	// Store number of lines at index 0
	file_sizes[0] = ft_get_line_number(pathname);

	// Open file for reading
	file = open(pathname, O_RDONLY);
	if (file == -1 || file_sizes[0] == -1)  // check open and valid line count
		return (NULL);

	// Fill file_sizes array with lengths per line via helper function
	if (ft_get_line_lens_loop(file, file_sizes) == NULL)
		return (NULL);

	close(file);
	return (file_sizes);
}

// Reads all lines from the file into a dynamically allocated array of strings (*lines).
// Returns 0 on success, -1 on failure.
int	ft_get_lines(const char *pathname, char ***lines)
{
	int			file;          // file descriptor
	int			*file_sizes;   // holds number of lines and line lengths
	const char	*default_path = "numbers.dict";  // default dictionary path

	// Use default dictionary if pathname is NULL
	if (pathname == NULL)
		pathname = default_path;

	// Get lengths of lines and number of lines in the file
	file_sizes = ft_get_line_lens(pathname);

	// Open the file
	file = open(pathname, O_RDONLY);

	// Check for errors opening file or allocating sizes
	if (file_sizes == NULL || file == -1)
		return (-1);

	// Allocate array of strings with room for NULL terminator
	*lines = malloc(sizeof(char *) * (file_sizes[0] + 1));
	if (*lines == NULL)
		return (-1);

	// Use helper function to read lines into allocated array
	if (ft_get_lines_loop(file, file_sizes, lines) == -1)
		return (-1);

	// Clean up
	free(file_sizes);
	close(file);
	return (0);
}
