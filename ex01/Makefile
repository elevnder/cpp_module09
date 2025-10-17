# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnera <earnera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 08:43:01 by earnera           #+#    #+#              #
#    Updated: 2025/10/15 08:43:27 by earnera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	btc
FUNCTION = ./src/main.cpp ./src/RPN.cpp

all: $(NAME)

$(NAME) : $(FUNCTION)
		$(CC) $(CFLAGS) $(FUNCTION) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re