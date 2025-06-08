/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:25:31 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 21:45:12 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

int	norme_print_nbr_inf100(t_app_data *data, int print_o,
		char *str, char *str_nb)
{
	int		sum;
	char	*str_cop;

	str_cop = ft_strdup(str);
	sum = 0;
	if (str_cop == NULL)
	{
		data->is_error = 2;
		return (0);
	}
	str_cop[1] = '0';
	sum += print_nb(str_cop, print_o, str_nb, data);
	if (data->is_error != 0)
	{
		free (str_cop);
		return (0);
	}
	sum += print_nb(str + 1, print_o, str_nb, data);
	if (data->is_error != 0)
	{
		free(str_cop);
		return (0);
	}
	free (str_cop);
	return (sum);
}

int	print_nbr_inf100(char *str, int print_o, char *str_nb, t_app_data *data)
{
	int		num;
	int		sum;
	char	*dict_value;

	num = ft_atoi(str);
	if (num <= 20 || num % 10 == 0)
	{
		dict_value = ft_get_value(str, data->nb, data->val, data);
		if (dict_value == NULL)
			return (0);
		if (print_o)
			space_strcat(str_nb, dict_value);
		return (ft_strlen(dict_value) + 1);
	}
	else if (num <= 100)
	{
		sum = norme_print_nbr_inf100(data, print_o, str, str_nb);
		return (sum);
	}
	return (0);
}

// int	norme_print_nbr_sup100(char *magnum, t_app_data *data)
// {

// }

int	print_nbr_sup100(char *str, int print_o, char *str_nb, t_app_data *data)
{
	int		sum;
	char	*magnum;
	char	*temp_mag;
	char	*rest;

	sum = 0;
	magnum = ft_get_mag_nb(str);
	if (magnum == NULL)
		return (0);
	sum += print_nb(magnum, print_o, str_nb, data);
	if (data->is_error != 0)
	{
		free (magnum);
		return (0);
	}
	temp_mag = ft_get_mag (str);
	if (temp_mag == NULL)
	{
		free (magnum);
		return (0);
	}
	rest = ft_get_value(temp_mag, data->nb, data->val, data);
	free (temp_mag);
	if (rest == NULL)
	{
		free (magnum);
		return (0);
	}
	if (print_o)
		space_strcat(str_nb, rest);
	sum += print_nb(str + ft_strlen(magnum), print_o, str_nb, data);
	if (data->is_error != 0)
	{
		free (magnum);
		return (0);
	}
	sum += ft_strlen(rest) + 1;
	free(magnum);
	return (sum);
}

int	print_nb(char *str, int print_o, char *str_nb, t_app_data *data)
{
	int	len;

	while (str[0] == '0')
		str++;
	if (str[0] == 0)
		return (0);
	len = ft_strlen(str);
	if (len <= 2)
		return (print_nbr_inf100(str, print_o, str_nb, data));
	else
		return (print_nbr_sup100(str, print_o, str_nb, data));
	return (0);
}
