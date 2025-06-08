/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 05:08:02 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 16:24:17 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

void	free_parsed_arrays(char **nums, char **values, int current_index)
{
	int	i;

	if (nums != NULL)
	{
		i = 0;
		while (i < current_index && nums[i] != NULL)
		{
			free (nums[i]);
			i++;
		}
		free (nums);
	}
	if (values != NULL)
	{
		i = 0;
		while (i < current_index && values[i] != NULL)
		{
			free(values[i]);
			i++;
		}
		free (values);
	}
}

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

int	handle_value_malloc_fail(char **number_ptr)
{
	if (*number_ptr != NULL)
	{
		free(*number_ptr);
		*number_ptr = NULL;
	}
	return (1);
}

void	copy_value_string(char *src_str, int start_idx, char *dest_val)
{
	int	value_idx;

	value_idx = 0;
	while (src_str[start_idx] >= 32 && src_str[start_idx] <= 126)
	{
		if (only_space(start_idx, src_str) == 1)
			break ;
		if (src_str[start_idx] != ' '
			|| (src_str[start_idx] == ' ' && src_str[start_idx - 1] != ' '))
		{
			dest_val[value_idx] = src_str[start_idx];
			value_idx++;
		}
		start_idx++;
	}
	dest_val[value_idx] = '\0';
}

int	parse_line_str(char *str, char **number, char **values)
{
	int	index;

	if (parse_line_start(&index, str, number) != 0)
	{
		if (*number != NULL)
		{
			free(*number);
			*number = NULL;
		}
		return (1);
	}
	*values = malloc(sizeof(char) * (ft_get_val_size(index, str) + 2));
	if (*values == NULL)
		return (handle_value_malloc_fail(number));
	copy_value_string(str, index, *values);
	return (0);
}
