/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict_helper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:19:21 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 22:35:19 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DICT_HELPER_H
# define PARSE_DICT_HELPER_H

int		ft_get_number(int *idx, char *str, char **number);
int		ft_get_val_size(int idx, char *str);
int		only_space(int idx, char *str);

#endif
