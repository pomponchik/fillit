# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/24 07:18:31 by ahalmon-          #+#    #+#              #
#    Updated: 2019/02/24 07:18:33 by ahalmon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = sources/*.c
OUT = sources/*.o
INCLUDES = sources/

subsystem:
	cd subdir && $(MAKE)
	cd ..

all:  subsystem
	gcc -Wall -Werror -Wextra -c $(FILES) libft.a -o $(NAME) -I $(INCLUDES)

clean:
	/bin/rm -f $(OUT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
