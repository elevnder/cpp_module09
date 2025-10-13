# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earnera <earnera@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 12:38:00 by marvin            #+#    #+#              #
#    Updated: 2025/10/07 09:48:10 by earnera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = 	btc
FUNCTION = ./src/main.cpp ./src/BitcoinExchange.cpp

all: $(NAME)

$(NAME) : $(FUNCTION)
		$(CC) $(CFLAGS) $(FUNCTION) -o $(NAME)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re