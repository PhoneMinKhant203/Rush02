/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:25:31 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 04:37:21 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Global Variables for dict mapping
char	**g_nb;
char	**g_val;
extern	int	is_error;

// to handle less than or equal to 100
// Convert number from str to word form using dictionary.

int	print_nbr_inf100(char *str, int print_o, char *str_nb)
{
	char	*str_cop;
	int		num;
	int		sum;

	num = ft_atoi(str);
	if (num <= 20 || num % 10 == 0) //unique word format, e.g: zero to twenty
	{
		if (print_o)
			space_strcat(str_nb, get_values(str, g_nb, g_val));
		return (ft_strlen(get_values(str, g_nb, g_val)) + 1);
	}
	else if (num <= 100)
	{
		sum = 0;
		str_cop = ft_strdup(str); //need copy to modify
		str_cop[1] = '0';//eg. 42 to 40
		sum += print_nb(str_cop, print_o, str_nb); //for tens
		sum += print_nb(str + 1, print_o, str_nb); //for ones
		free(str_cop);
		return (sum);
	}
	return (0);
}

//to handle greater than 100 numbers
//cut number accoding to magnitude, e.g hundreds, thousands (to print recursively)

int	print_nbr_sup100(char *str, int print_o, char *str_nb)
{
	int		sum;
	char	*magnum;
	char	*rest;

	sum = 0;
	magnum = get_mag_nb(str); //to get leading digits
	sum += print_num(magnum, print_o, str_nb); //to print number before magnitude
	rest = get_value(get_mag(str), g_nb, g_val); //to get magnitude label, eg.hundred
	if (print_o)
		space_strcat(str_nb, rest); //to append magnitude to result
	sum += print_nb(str + ft_strlen(magnum), print_o, str_nb); //to print the rest recursively
	sum += ft_strlen(rest) + 1;
	return (sum);
}

// to handle number < 100 or >= 100 to proceed

int	print_nb(char *str, int print_o, char *str_nb)
{
	int	len;

	while (str[0] == '0') //to skip leading zero
		str++;
	if (str[0] == 0)
		return (0);
	len = ft_strlen(str);
	if (len <= 2)
		return (print_nbr_inf100(str, print_o, str_nb));
	else
		return (print_nbr_sup100(str, print_o, str_nb));
	return (0);
}

// To convert num string into word format using dictionary file and return result string
// Parse dictionery file
// Determine result string size
// Allocate memory for result string
// Store converted number

char	*get_written_form(char *str, const char *dict_path)
{
	char	*str_nb;
	int		str_size;
	int		index;
	char	**dfile_content;

	if (get_lines(dict_path, &dfile_content) != 0
			|| parse_dstring(dfile_content, &g_nb, &g_val) != 0)
	{
		is_error = 1;
		return (0);
	}
	
	index = 0;
	if (only_zero(str) == 0)
		str_size = ft_strlen(get_values("0", g_nb, g_val));
	else
		str_size = print_nb(str, 0, "");
	
	str_nb = malloc(sizeof(char) * (str_size + 1));
	index = -1; //To Check again
	while (index++ < str_size)
		str_nb[index] = 0;
	
	if (only_zero(str) == 0)
		space_strcat(str_nb, get_value("0", g_nb, g_val));
	else
		print_nb(str, 1, str_nb);
	
	return (str_nb);
}
