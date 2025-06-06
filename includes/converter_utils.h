#ifndef CONVERTER_UTILS_H
# define CONVERTER_UTILS_H

// Get value by key from numbers and values arrays
char	*ft_get_value(char *key, char **numbers, char **values);

// Get magnitude word for a number string
char	*ft_get_magnitude(char *str);

// Get magnitude number string
char	*ft_get_magnitude_number(char *str);

// Check if string contains only zeros
int	only_zero(char *str);

#endif
