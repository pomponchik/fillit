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
	cd Libft/ && $(MAKE)
	cd ..

all:  subsystem
	gcc -Wall -Werror -Wextra -c $(FILES) libft.a -I $(INCLUDES)

clean:
	/bin/rm -f $(OUT)
	/bin/rm -f Libft/*.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f Libft/libft.a

re: fclean all
