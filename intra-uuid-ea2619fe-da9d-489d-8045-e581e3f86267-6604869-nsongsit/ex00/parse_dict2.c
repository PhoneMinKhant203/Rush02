/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 03:36:01 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 07:34:33 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

extern t_app_data	g_app_data;

int	allocate_parsed_arrays(char ***nums_ptr, char ***values_ptr, int count)
{
	int	i;

	*nums_ptr = malloc(sizeof(char *) * (count + 1));
	if (*nums_ptr == NULL)
		return (1);
	*values_ptr = malloc(sizeof(char *) * (count + 1));
	if (*values_ptr == NULL)
	{
		free (*nums_ptr);
		*nums_ptr = NULL;
		return (1);
	}
	i = 0;
	while (i <= count)
	{
		(*nums_ptr)[i] = NULL;
		(*values_ptr)[i] = NULL;
		i++;
	}
	return (0);
}

int	ft_parse_dstring(char **strs, char ***nums, char ***values,
	t_app_data *data)
{
	int	count;
	int	i;

	count = 0;
	while (strs[count] != NULL)
		count++;
	if (allocate_parsed_arrays(nums, values, count) != 0)
	{
		data->is_error = 1;
		return (1);
	}
	i = 0;
	while (strs[i] != NULL)
	{
		if (parse_line_str(strs[i], &(*nums)[i], &(*values)[i]) != 0)
		{
			data->is_error = 1;
			free_parsed_arrays(*nums, *values, i);
			*nums = NULL;
			*values = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}
