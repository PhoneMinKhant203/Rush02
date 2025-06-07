/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:25:31 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 22:26:21 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_helper.h"
#include "converter_helper.h"
#include "parse_file.h"
#include "parse_dict.h"

int	print_nb(char *str, int print_o, char *str_nb);

char		**g_nb;
char		**g_val;
extern int	g_is_error;

int	print_nbr_inf100(char *str, int print_o, char *str_nb)
{
	char	*str_cop;
	int		num;
	int		sum;

	num = ft_atoi(str);
	if (num <= 20 || num % 10 == 0)
	{
		if (print_o)
			space_strcat(str_nb, ft_get_value(str, g_nb, g_val));
		return (ft_strlen(ft_get_value(str, g_nb, g_val)) + 1);
	}
	else if (num <= 100)
	{
		sum = 0;
		str_cop = ft_strdup(str);
		str_cop[1] = '0';
		sum += print_nb(str_cop, print_o, str_nb);
		sum += print_nb(str + 1, print_o, str_nb);
		free(str_cop);
		return (sum);
	}
	return (0);
}

int	print_nbr_sup100(char *str, int print_o, char *str_nb)
{
	int		sum;
	char	*magnum;
	char	*rest;

	sum = 0;
	magnum = ft_get_mag_nb(str);
	sum += print_nb(magnum, print_o, str_nb);
	rest = ft_get_value(ft_get_mag(str), g_nb, g_val);
	if (print_o)
		space_strcat(str_nb, rest);
	sum += print_nb(str + ft_strlen(magnum), print_o, str_nb);
	sum += ft_strlen(rest) + 1;
	return (sum);
}

int	print_nb(char *str, int print_o, char *str_nb)
{
	int	len;

	while (str[0] == '0')
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

char	*ft_get_written_form(char *str, const char *dict_path)
{
	char	*str_nb;
	int		str_size;
	int		index;
	char	**dfile_content;

	if (ft_get_lines(dict_path, &dfile_content) != 0
		|| ft_parse_dstring(dfile_content, &g_nb, &g_val) != 0)
	{
		g_is_error = 1;
		return (0);
	}
	index = 0;
	if (only_zero(str) == 0)
		str_size = ft_strlen(ft_get_value("0", g_nb, g_val));
	else
		str_size = print_nb(str, 0, "");
	str_nb = malloc(sizeof(char) * (str_size + 1));
	index = -1;
	while (index++ < str_size)
		str_nb[index] = 0;
	if (only_zero(str) == 0)
		space_strcat(str_nb, ft_get_value("0", g_nb, g_val));
	else
		print_nb(str, 1, str_nb);
	return (str_nb);
}
