/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 02:57:12 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 04:30:30 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	is_error;

//to return relative value string for given key from the dictionary arrays
//if there is no key, sets error flag and return empty string

char	*get_value(char *key, char **numbers, char **values)
{
	int	 	index;
	char	*emp_str;
	
	index = 0;
	while (numbers[index])
	{
		if (ft_strcmp(numbers[index], key) == 0)
			return (values[index]);
		index++;
	}

	is_error = 1;
	emp_str = malloc(sizeof(char) * 1);
	emp_str[0] = 0;
	return (emp_str);
}

//to calculate the magnitude string for given string of number
//e.g: 1234 to 1000

char	*get_mag(char *str)
{
	int		n;
	int		len;
	char	*mag;

	len = ft_strlen(str);
	n = len;
	if (len >= 4)
	{
		while ((n - 1) % 3 != 0) //to reduce n until it align with magnitude boundary (e.g: thousand, millions,)
			n--;
	}
	mag = malloc(n + 1);
	mag[0] = '1';
	mag[n] = '\0';
	while (--n > 0)
		mag[n] = '0'; //to fill with zeros
	return (mag);
}

char	*get_mag_nb(char *str)
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

//to check if the given num string contain only zero
//if yes, return 0 and if not, return 1

int	only_zero(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (str[index] != '0')
			return (1); //meaing not all zeros
		index++;
	}
	return (0); //meaning all zeros;
}
