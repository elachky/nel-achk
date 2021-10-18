NAME := libft.a

CC := gcc

FLAG = -Wall -Werror -Wextra
INCLUDE := -I.

HEADERS := ft_libft.h

SRC :=	ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_strlen.c \
		ft_putstr_fd.c ft_putnbr.c ft_isstrdigit.c ft_isspace.c

OBJ := $(SRC:.c=.o)

%.o : %.c $(HEADERS)
	$(CC) $(FLAG) -I $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean:	
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all