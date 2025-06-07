/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:14:08 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 19:01:45 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HELPER_H
# define CONVERTER_HELPER_H

char	*ft_get_value(char *key, char **numbers, char **values);
char	*ft_get_mag(char *str);
char	*ft_get_mag_nb(char *str);
int		only_zero(char *str);

#endif
