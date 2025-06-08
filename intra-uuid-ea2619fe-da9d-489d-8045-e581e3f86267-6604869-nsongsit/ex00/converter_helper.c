/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:57:12 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 14:32:11 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

char	*ft_get_value(char *key, char **numbers, char **values,
			t_app_data *data)
{
	int	index;

	index = 0;
	while (numbers[index])
	{
		if (ft_strcmp(numbers[index], key) == 0)
			return (values[index]);
		index++;
	}
	data->is_error = 1;
	return (NULL);
}

char	*ft_get_mag(char *str)
{
	int		n;
	int		len;
	char	*mag;

	len = ft_strlen(str);
	n = len;
	if (len >= 4)
	{
		while ((n - 1) % 3 != 0)
			n--;
	}
	mag = malloc(n + 1);
	if (mag == NULL)
		return (NULL);
	mag[0] = '1';
	mag[n] = '\0';
	while (--n > 0)
		mag[n] = '0';
	return (mag);
}

char	*handle_long_number(char *str, int len)
{
	int		n;
	char	*num;
	int		i;

	n = (len - 1) % 3 + 1;
	num = malloc(n + 1);
	if (num == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		num[i] = str[i];
		i++;
	}
	num[n] = '\0';
	return (num);
}

char	*handle_short_number(char *str)
{
	int		n;
	char	*num;

	n = 1;
	num = malloc(n + 1);
	if (num == NULL)
		return (NULL);
	num[0] = str[0];
	num[n] = '\0';
	return (num);
}

char	*ft_get_mag_nb(char *str)
{
	int		len;
	char	*num;

	len = ft_strlen(str);
	if (len >= 4)
	{
		num = handle_long_number(str, len);
	}
	else
	{
		num = handle_short_number(str);
	}
	return (num);
}
