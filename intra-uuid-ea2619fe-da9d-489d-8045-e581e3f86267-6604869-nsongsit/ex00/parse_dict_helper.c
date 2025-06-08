/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:49:58 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 07:34:13 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

// duplicate the substring from s_idx to e_idx

char	*str_dup(char *str, int s_idx, int e_idx)
{
	int		idx;
	char	*result;

	result = malloc(sizeof(char) * (e_idx - s_idx + 2));
	idx = 0;
	if (result == NULL)
		return (NULL);
	while (s_idx <= e_idx)
	{
		result[idx] = str[s_idx];
		s_idx++;
		idx++;
	}
	result[idx] = 0;
	return (result);
}

int	ft_get_number(int *idx, char *str, char **number)
{
	int	start_idx;

	if (str[*idx] == '+' || str[*idx] == '-')
		*idx = *idx + 1;
	else if (str[*idx] < '0' || str[*idx] > '9')
		return (1);
	start_idx = *idx;
	while (str[*idx] >= '0' && str[*idx] <= '9')
		*idx = *idx + 1;
	*number = str_dup(str, start_idx, *idx - 1);
	return (0);
}

int	only_space(int idx, char *str)
{
	while (str[idx] != 0)
	{
		if (str[idx] != ' ')
			return (0);
		idx++;
	}
	return (1);
}

int	ft_get_val_size(int idx, char *str)
{
	int	val_size;

	val_size = 0;
	while (str[idx] >= 32 && str[idx] <= 126)
	{
		if (only_space(idx, str) == 1)
			break ;
		if (str[idx] != ' ')
			val_size++;
		else if (str[idx] == ' ' && str[idx - 1] != ' ' && str[idx - 1] != ':')
			val_size++;
		idx++;
	}
	return (val_size);
}
