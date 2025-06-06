#ifndef FT_UTILS_H
# define FT_UTILS_H

int		ft_strlen(char *str);         // Return length of string
void	ft_strcat_space(char *dest, char *src); // Append src to dest with a space
char	*ft_strdup(char *src);         // Duplicate a string (malloc)
int		ft_strcmp(char *s1, char *s2); // Compare two strings
int		ft_atoi(char *str);            // Convert string to int

#endif
