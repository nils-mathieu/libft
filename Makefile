# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmathieu <nmathieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 11:29:21 by nmathieu          #+#    #+#              #
#    Updated: 2022/05/07 11:22:55 by nmathieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = ft

SOURCES = $(shell find ./src/ -type f -name "*.c")
HEADER = libft.h

OBJECTS = $(patsubst %.c,%.o,$(SOURCES))
NAME = lib$(LIB_NAME).a

CC = gcc -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -vf $(OBJECTS)

.PHONY: fclean
fclean:
	rm -vf $(OBJECTS) $(NAME)

.PHONY: re
re: fclean all

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

%.o: %.c $(HEADER)
	$(CC) -I. -c $< -o $@

