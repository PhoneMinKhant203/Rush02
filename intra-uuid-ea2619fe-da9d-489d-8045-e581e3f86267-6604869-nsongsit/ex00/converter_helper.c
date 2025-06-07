/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:57:12 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 22:22:30 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_helper.h"

extern int	g_is_error;

char	*ft_get_value(char *key, char **numbers, char **values)
{
	int		index;
	char	*emp_str;

	index = 0;
	while (numbers[index])
	{
		if (ft_strcmp(numbers[index], key) == 0)
			return (values[index]);
		index++;
	}
	g_is_error = 1;
	emp_str = malloc(sizeof(char) * 1);
	emp_str[0] = 0;
	return (emp_str);
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
	mag[0] = '1';
	mag[n] = '\0';
	while (--n > 0)
		mag[n] = '0';
	return (mag);
}

char	*ft_get_mag_nb(char *str)
{
	int		n;
	int		i;
	int		len;
	char	*num;

	len = ft_strlen(str);
	if (len >= 4)
	{
		n = (len - 1) % 3 + 1;
		num = malloc(n + 1);
		i = 0;
		while (i < n)
		{
			num[i] = str[i];
			i ++;
		}
	}
	if (len <= 3)
	{
		n = 1;
		num = malloc(n + 1);
		num[0] = str[0];
	}
	num[n] = '\0';
	return (num);
}

int	only_zero(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (str[index] != '0')
			return (1);
		index++;
	}
	return (0);
}
