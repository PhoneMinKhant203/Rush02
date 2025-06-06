#ifndef PARSE_FILE_H
# define PARSE_FILE_H

// Reads lines from file and stores them in 'lines'
// Returns 0 on success, -1 on error
int	ft_get_lines(const char *pathname, char ***lines);

#endif
