/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:18:53 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/08 07:33:44 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "app.h"

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
