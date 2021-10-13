NAME := libutils.a

CC := gcc

FLAG = -Wall -Werror -Wextra
INCLUDE := -I.

HEADERS := ft_utils.h

SRC :=	ft_atoi.c ft_atol.c ft_isdigit.c ft_isspace.c \
		ft_putchar_fd.c ft_strcmp.c ft_strlen.c ft_putstr_fd.c\
		ft_putnbr.c 

OBJ := $(SRC:.c=.o)

%.o : %.c $(HEADERS)
	$(CC) -g $(FLAG) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all