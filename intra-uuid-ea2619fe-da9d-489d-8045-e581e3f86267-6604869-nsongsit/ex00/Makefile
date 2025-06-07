# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phonekha <phonekha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 18:47:03 by phonekha          #+#    #+#              #
#    Updated: 2025/06/07 23:49:08 by phonekha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = main.c ft_converter.c converter_helper.c ft_helper.c parse_file.c parse_file_helper.c parse_dict.c parse_dict_helper.c 
OBJS = $(patsubst %.c, %.o, $(SOURCE))
NAME	= rush-02
CC = gcc -g3
CFLAGS = -Wall -Werror -Wextra -c
LFLAGS = -Wall -Werror -Wextra -o

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SOURCE)
	$(CC) $(LFLAGS) $(NAME) $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	fclean all
