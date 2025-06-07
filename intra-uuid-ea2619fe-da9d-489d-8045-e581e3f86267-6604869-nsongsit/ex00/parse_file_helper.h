/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_helper.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:32:38 by phonekha          #+#    #+#             */
/*   Updated: 2025/06/07 19:02:13 by phonekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FILE_HELPER_H
# define PARSE_FILE_HELPER_H

int	*ft_get_lines_len_loop(int file, int *file_sizes);
int	ft_get_lines_loop(int file, int *file_sizes, char ***lines);

#endif
