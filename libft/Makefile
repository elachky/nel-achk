# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-achk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/18 21:34:10 by nel-achk          #+#    #+#              #
#    Updated: 2019/11/08 18:07:01 by nel-achk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

INCLUDES = ./

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	  ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	  ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c \
	  ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c


SRC_B = ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

OBJECTS = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) 
	@ar -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

bonus : all $(OBJ_B)
	@ar -rc $(NAME) $(OBJ_B)
	@ranlib $(NAME)

clean : 
	@rm -f $(OBJECTS) $(OBJ_B)

fclean : clean
	@rm -f $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

re : fclean all

rebonus : fclean bonus
