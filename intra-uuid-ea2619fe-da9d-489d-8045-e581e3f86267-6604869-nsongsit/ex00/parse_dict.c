/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 05:08:02 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 22:38:49 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "parse_dict_helper.h"

extern int	g_is_error;

int	parse_line_start(int *index, char *str, char **number)
{
	*index = 0;
	if (ft_get_number(index, str, number) != 0)
		return (1);
	while (str[*index] == ' ')
		*index = *index + 1;
	if (str[*index] != ':')
		return (1);
	*index = *index + 1;
	while (str[*index] == ' ')
		*index = *index + 1;
	return (0);
}

int	parse_line_str(char *str, char **number, char **values)
{
	int	index;
	int	valueindex;

	if (parse_line_start(&index, str, number) != 0)
		return (1);
	*values = malloc(sizeof(char) * (ft_get_val_size(index, str) + 2));
	valueindex = 0;
	while (str[index] >= 32 && str[index] <= 126)
	{
		if (only_space(index, str) == 1)
			break ;
		if (str[index] != ' ' || (str[index] == ' ' && str[index - 1] != ' '))
		{
			(*values)[valueindex] = str[index];
			valueindex++;
		}
		index++;
	}
	(*values)[valueindex] = 0;
	return (0);
}

int	ft_parse_dstring(char **strs, char ***nums, char ***values)
{
	int	index;

	index = 0;
	while (strs[index] != 0)
		index++;
	*nums = malloc(sizeof(char *) * (index + 1));
	*values = malloc(sizeof(char *) * (index + 1));
	index = 0;
	while (strs[index] != 0)
	{
		if (parse_line_str(strs[index], &(*nums)[index],
			&(*values)[index]) != 0)
		{
			g_is_error = 1;
			return (1);
		}
		index++;
	}
	(*nums)[index] = 0;
	(*values)[index] = 0;
	return (0);
}
