/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 04:36:24 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 22:46:47 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
		index++;
	return (index);
}

void	space_strcat(char *dest, char *src)
{
	int	index;
	int	destindex;

	index = 0;
	destindex = ft_strlen(dest);
	dest[destindex] = ' ';
	destindex++;
	while (src[index] != 0)
	{
		dest[destindex] = src[index];
		index++;
		destindex++;
	}
	dest[destindex] = 0;
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		index;

	dup = malloc(ft_strlen(src) + 1);
	index = 0;
	while (src[index] != 0)
	{
		dup[index] = src[index];
		index++;
	}
	dup[index] = 0;
	return (dup);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] != 0 && s2[index] != 0)
	{
		if (s1[index] != s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	ft_atoi(char *str)
{
	int	nb;
	int	index;
	int	sign;

	nb = 0;
	index = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == ' ')
		index++;
	while (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nb = nb * 10 + str[index] - '0';
		index++;
	}
	return (nb * sign);
}
