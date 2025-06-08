# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 18:47:03 by phonekha          #+#    #+#              #
#    Updated: 2025/06/08 21:42:52 by phonekha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = malloc_strike.c main.c ft_converter.c ft_converter2.c converter_helper.c converter_helper2.c ft_helper.c parse_file.c parse_file_helper.c parse_dict.c parse_dict2.c parse_dict_helper.c norme_parse_file.c
OBJS = $(patsubst %.c, %.o, $(SOURCE))
NAME = rush-02
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
LFLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE) -g
	$(CC) $(LFLAGS) $(NAME) $(OBJS) -g

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	fclean all
