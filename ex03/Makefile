# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgutten <vgutten@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 15:45:44 by vguttenb          #+#    #+#              #
#    Updated: 2022/05/30 21:42:16 by vgutten          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
SRC = main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp
		
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) Makefile
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all fclean re