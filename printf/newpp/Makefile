# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-achk <nel-achk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 01:43:58 by nel-achk          #+#    #+#              #
#    Updated: 2020/11/22 14:10:39 by nel-achk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

CC = gcc

INCLUDE = ./includes

SRC = src/utils/ft_atoi.c src/utils/ft_bzero.c src/utils/ft_calloc.c src/utils/ft_isalpha.c \
	  src/utils/ft_itoa.c src/utils/ft_putchar_fd.c src/utils/ft_putstr_fd.c \
	  src/utils/ft_strdup.c src/utils/ft_strlen.c src/utils/ft_toupper.c \
	  src/utils/ft_itoa_hexa.c src/utils/ft_itoa_unsign.c src/utils/ft_isdigit.c \
	  src/utils/ft_max.c src/utils/ft_toupper_str.c src/utils/put.c \
	  src/utils/ft_putnbr.c src/utils/print_pad.c src/utils/ft_size.c\
	  \
	  src/flags/test_pad.c src/flags/test_precision.c src/flags/test_width.c \
	  \
	  src/ft_printf.c src/print/print_int.c src/print/print_hexa.c \
	  src/print/print_pointer.c src/print/print_str.c src/print/print_char.c \
	  src/print/print_unsigned.c

OBJECTS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) 
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean : 
	@rm -f $(OBJECTS)

fclean : clean
	@rm -f $(NAME)

%.o : %.c includes/libftprintf.h
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

re : fclean all
