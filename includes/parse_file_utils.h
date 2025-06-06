#ifndef PARSE_FILE_UTILS_H
# define PARSE_FILE_UTILS_H

// Gets the length of each line in a file
void	*ft_get_line_lens_loop(int file, int *file_sizes);

// Reads file lines into memory
int		ft_get_lines_loop(int file, int *file_sizes, char ***lines);

#endif
