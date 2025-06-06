#ifndef PARSE_DICT_UTILS_H
# define PARSE_DICT_UTILS_H

// Extract number string starting at cur from str
char	*get_number(int *cur, char *str, char **number);

// Get size of the value string starting at cur in str
int		get_value_size(int cur, char *str);

// Check if the rest of str from cur is only spaces
int		is_only_space(int cur, char *str);

#endif
