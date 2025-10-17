# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnera <earnera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/17 09:58:59 by earnera           #+#    #+#              #
#    Updated: 2025/10/17 10:04:33 by earnera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	PmergeMe
FUNCTION = ./src/main.cpp ./src/PmergeMe.cpp

all: $(NAME)

$(NAME) : $(FUNCTION)
		$(CC) $(CFLAGS) $(FUNCTION) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re