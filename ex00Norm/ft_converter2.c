/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 01:34:42 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 14:46:33 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_dfile_content(char **dfile_content)
{
	int	i;

	if (dfile_content == NULL)
		return ;
	i = 0;
	while (dfile_content[i] != NULL)
	{
		free(dfile_content[i]);
		i++;
	}
	free (dfile_content);
}

int	load_and_parse_dict(const char *dict_path, char ***dfile_content_ptr,
	t_app_data *data)
{
	if (ft_get_lines(dict_path, dfile_content_ptr) != 0)
	{
		data->is_error = 1;
		return (-1);
	}
	if (ft_parse_dstring(*dfile_content_ptr, &(data->nb),
			&(data->val), data) != 0)
	{
		data->is_error = 1;
		free_dfile_content(*dfile_content_ptr);
		*dfile_content_ptr = NULL;
		return (-1);
	}
	return (0);
}

void	init_char_array(char *arr, int size)
{
	int	i;

	i = 0;
	while (i <= size)
	{
		arr[i] = '\0';
		i++;
	}
}

char	*ft_get_written_form(char *str, const char *dict_path, t_app_data *data)
{
	char	*str_nb;
	int		str_size;
	char	**dfile_content;
	char	*zero_value_str;

	dfile_content = NULL;
	if (load_and_parse_dict(dict_path, &dfile_content, data) != 0)
		return (NULL);

	if (only_zero(str) == 0)
	{
		zero_value_str = ft_get_value("0", data->nb, data->val, data);
		if (zero_value_str == NULL)
		{
			free_dfile_content(dfile_content);
			return (NULL);
		}
		str_size = ft_strlen(zero_value_str);
	}
	else
	{
		str_size = print_nb(str, 0, NULL, data);
		if (data->is_error != 0 || str_size <= 0)
		{
			free_dfile_content(dfile_content);
			return (NULL);
		}
	}
	str_nb = malloc(sizeof(char) * (str_size + 1));
	if (str_nb == NULL)
	{
		data->is_error = 2;
		free_dfile_content(dfile_content);
		return (NULL);
	}
	init_char_array(str_nb, str_size);
	if (only_zero(str) == 0)
	{
		ft_strcpy(str_nb, zero_value_str);
	}
	else
	{
		print_nb(str, 1, str_nb, data);
		if (data->is_error != 0)
		{
			free(str_nb);
			free_dfile_content(dfile_content);
			return (NULL);
		}
	}
	free_dfile_content(dfile_content);
	return (str_nb);
}

