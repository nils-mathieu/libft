# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/03 11:37:41 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = ft

SOURCES = $(shell find . -type f -name "*.c")
HEADER = libft.h

OBJECTS = $(%.c,%.o,$(NAME))
NAME = lib$(LiB_NAME).a

CC = gcc -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJECTS)

.PHONY: fclean
fclean:
	rm -f $(OBJECTS) $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

